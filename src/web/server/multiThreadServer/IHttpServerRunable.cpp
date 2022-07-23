﻿#include "IHttpServerRunable.h"
#include "base/ISocketUtil.h"
#include "web/controller/IControllerManage.h"
#include "web/controller/private/IControllerParamUtil.h"
#include "web/net/IRequest.h"
#include "web/net/IResponse.h"
#include "web/net/impl/IReqRespRaw.h"
#include "web/response/IStaticFileResponse.h"

$PackageWebCoreBegin

IHttpServerRunable::IHttpServerRunable(qintptr handle) : handle{handle}
{

}

void IHttpServerRunable::run()
{
    // TODO: socket 在这里内存泄露!!!
    socket = ISocketUtil::createTcpSocket(handle);
    if(!socket->waitForReadyRead()){        // TODO: 这里使用 epoll 后可以省略.
        return;
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

        handleRequest(request, response);

        if(IControllerManage::postIntercept(request, response)){
            break;
        }
        IControllerManage::postProcess(request, response);

        // 拦截 socket
        if(!response.valid() || response.status() != IHttpStatus::OK_200){
            if(interceptStatusCode(request, response)){
                break;
            }
        }

    } while(0);

    // 响应
    if(!response.respond()){
        return ISocketUtil::handleInternalError(socket);
    }
}

void IHttpServerRunable::handleRequest(IRequest &request, IResponse &response)
{
    if(request.method() == IHttpMethod::OPTIONS){
        return runOptionsFunction(request, response);
    }

    // process as dynamic server first
    auto function = IControllerManage::getUrlFunction(request);
    if(function != nullptr){
        processInDynamicUrlFunctionMode(request, response, function);
        return;
    }

    // process as static file server then
    auto path = IControllerManage::getStaticFilePath(request);
    if(!path.isEmpty()){
        processInStaticFileMode(request, response, path);
        return;
    }

    // process as not found last
    processInNotFoundMode(request, response);
}

void IHttpServerRunable::runStatusFunction(IRequest &request, IResponse &response, IStatusActionNode *function)
{
    Q_UNUSED(response)
    IControllerParamUtil::ParamType params;
    IControllerParamUtil::createParams(function->methodNode, params, request);

    if(!request.valid()){   // unneeded, but write here for assurance
        IControllerParamUtil::destroyParams(function->methodNode, params);
        return;
    }

    auto index = function->methodNode.metaMethod.methodIndex();
    auto enclosingObject = function->methodNode.metaMethod.enclosingMetaObject();
    enclosingObject->static_metacall(QMetaObject::InvokeMetaMethod, index, params);

    IControllerParamUtil::destroyParams(function->methodNode, params);
}

void IHttpServerRunable::processInDynamicUrlFunctionMode(IRequest &request, IResponse &response, IUrlActionNode *function)
{
    IControllerParamUtil::ParamType params;
    IControllerParamUtil::createParams(function->methodNode, params, request);

    if(!request.valid()){           // 这里 request invalid 的情况产生于 数据转换的时候。
        IControllerParamUtil::destroyParams(function->methodNode, params);
        return;
    }

    auto index = function->methodNode.metaMethod.methodIndex();
    auto enclosingObject = function->methodNode.metaMethod.enclosingMetaObject();
    enclosingObject->static_metacall(QMetaObject::InvokeMetaMethod, index, params);
    IControllerParamUtil::resolveReturnValue(response, function->methodNode, params);

    IControllerParamUtil::destroyParams(function->methodNode, params);
}

void IHttpServerRunable::processInStaticFileMode(IRequest &request, IResponse &response, const QString &path)
{
    Q_UNUSED(request)
    IStaticFileResponse staticFileReponse(path);
    response.setContent(&staticFileReponse);
}

void IHttpServerRunable::processInNotFoundMode(IRequest &request, IResponse &response)
{
    Q_UNUSED(response)
    QString info = request.url() + " " + IHttpMethodHelper::toString(request.method()) + " has no function to handle";
    request.setInvalid(IHttpStatus::NOT_FOND_404, info);
    return;
}

QStringList handleOptionsRequest1(IRequest& request, IResponse& response)
{
    Q_UNUSED(response)
    static const QMap<IHttpMethod, QString> mappings = {
        {IHttpMethod::GET,      "GET"},
        {IHttpMethod::PUT,      "PUT"},
        {IHttpMethod::POST,     "POST"},
        {IHttpMethod::DELETED,  "DELETE"},
        {IHttpMethod::PATCH,    "PATCH"},
    };
    static const QList<IHttpMethod> keys = mappings.keys();

    QStringList options;
    auto raw = request.getRaw();
    auto origin = raw->m_method;
    for (auto key : keys) {
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

    return options;
}

void IHttpServerRunable::runOptionsFunction(IRequest &request, IResponse &response)
{
    QStringList  options = handleOptionsRequest1(request, response);

    response.setStatus(IHttpStatus::OK_200);
    if(options.isEmpty()) {
        response.setHeader("Allow" , "NONE");
    } else {
        response.setHeader("Allow" , options.join(", "));
    }
    response.setContent("");
}

bool IHttpServerRunable::interceptStatusCode(IRequest &request, IResponse &response)
{
    auto function = IControllerManage::getStatusFunction(response.status());
    if(function != nullptr){
        runStatusFunction(request, response, function);
    }
    return false;
}

$PackageWebCoreEnd
