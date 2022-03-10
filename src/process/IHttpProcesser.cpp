﻿#include "IHttpProcesser.h"
#include "IHttpSocketManage.h"
#include "base/ISocketUtil.h"
#include "base/ITicTacUtil.h"
#include "common/net/IRequest.h"
#include "common/net/IResponse.h"
#include "common/net/impl/IReqRespRaw.h"
#include "controller/IControllerManage.h"
#include "process/IHttpRunner.h"

$PackageWebCoreBegin

namespace IHttpProcessorHelper {
    static void handleRequest(IRequest& request, IResponse& response);
    static void handleOptionsRequest(IRequest& request, IResponse& response);
}

IHttpProcesser::IHttpProcesser(qintptr handle)
    :handle(handle)
{
}

// TODO: 刚刚看了一下，如果要实现 长连接，下面的模型需要再分离， 即把 socket 的输入输出和 处理函数函数分离，
// 可以考虑使用异步处理
void IHttpProcesser::run()
{
    socket = ISocketUtil::createTcpSocket(handle);
    if(!socket->waitForReadyRead()){        // TODO: 这里使用 epoll 后可以省略.
        return ISocketUtil::processReadError(&socket);
    }

    IRequest request(socket);
    IResponse response(&request);

    if(!request.valid()){
        response.respond();
        return;
    }

    do {
        if( IControllerManage::preIntercept(request, response)){
            break;
        }
        IControllerManage::preProcess(request, response);

        IHttpProcessorHelper::handleRequest(request, response);

        if(IControllerManage::postIntercept(request, response)){       // "current response is been post intercepted";
            break;
        }
        IControllerManage::postProcess(request, response);

        // 拦截 socket
        if(!response.valid() || response.status() != IHttpStatus::OK_200){
            if(IHttpSocketManage::interceptStatusCode(request, response)){
                break;
            }
        }

    } while(0);

    // 响应
    if(!response.respond()){
        return ISocketUtil::handleInternalError(&socket);
    }
    ISocketUtil::closeTcpSocket(&socket);
}

bool IHttpProcesser::isSocketAlive(IRequest &request)
{
    Q_UNUSED(request)
    return false;
}

void IHttpProcessorHelper::handleRequest(IRequest& request, IResponse& response)
{
    if(request.method() == IHttpMethod::OPTIONS){
        return handleOptionsRequest(request, response);
    }

    auto function = IControllerManage::getUrlFunction(request);
    if(function == nullptr){
        request.setInvalid(IHttpStatus::NOT_FOND_404, request.url() + " " + IHttpMethodHelper::toString(request.method()) +  " has no function to handle");
        return;
    }

    IHttpRunner::runUrlFunction(request, response, function);
}

void IHttpProcessorHelper::handleOptionsRequest(IRequest& request, IResponse& response)
{
    static QMap<IHttpMethod, QString> mappings = {
        {IHttpMethod::GET, "GET"},
        {IHttpMethod::PUT, "PUT"},
        {IHttpMethod::POST, "POST"},
        {IHttpMethod::DELETED, "DELETE"},
        {IHttpMethod::PATCH, "PATCH"},
    };
    static QList<IHttpMethod> keys = mappings.keys();

    QStringList options;

    auto raw = request.getRaw();
    auto origin = raw->m_method;
    for(auto key : keys){
        raw->m_method = key;
        if(IControllerManage::getUrlFunction(request) != nullptr){
            options.append(mappings[key]);
        }
    }

    if(options.contains("GET")){
        options.append("HEAD");
    }
    if(!options.empty()){
        options.append("OPTIONS");
    }

    raw->m_method = origin;

    return IHttpRunner::runOptionsFunction(request, response, options);
}

$PackageWebCoreEnd

