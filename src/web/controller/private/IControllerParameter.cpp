﻿#include "IControllerParameter.h"

#include "core/base/IJsonUtil.h"
#include "core/base/IToeUtil.h"
#include "core/bean/IBeanWare.h"
#include "core/bean/IBeanTypeManage.h"
#include "core/task/ITaskManage.h"
#include "web/controller/private/IControllerBeanParametr.h"
#include "web/jar/IMultiPart.h"
#include "web/node/IMethodNode.h"
#include "web/node/IFunctionNode.h"
#include "web/node/IParamNode.h"
#include "web/net/IRequest.h"
#include "web/net/IResponse.h"
#include "web/net/impl/IReqRespRaw.h"
#include "web/response/IResponseInterface.h"
#include "web/response/IResponseManage.h"
#include "web/response/IPlainTextResponse.h"
#include "web/response/IStatusCodeResponse.h"
#include "web/response/IJsonResponse.h"
#include "web/response/IByteArrayResponse.h"
#include "web/IWebAssert.h"

$PackageWebCoreBegin

$UseAssert(IWebAssert)

namespace IControllerParameterHelper
{
    static const QString GiveColorSeeSee = QStringLiteral("浪额康康四辣锅削阔爱");
}
using namespace IControllerParameterHelper;

namespace IControllerFunctionBaseImplHelper
{
    void* convertParamToJson(const IParamNode &node, const QByteArray &content, bool& ok);
}

bool IControllerParameter::createArguments(const IMethodNode& methodNode, ParamType& params, IRequest &request)
{
    auto inst = instance();
    for(int i=0; i<=10; i++){
        params[i] = nullptr;
    }

    params[0] = inst->createReturnParam(methodNode.returnTypeId);

    bool ok;
    for(int i=0; i<methodNode.getParamCount(); i++){
        params[i + 1] = inst->createArgParam(methodNode.paramNodes[i], request, ok);
        if(!ok){
            return false;
        }
    }

    return true;
}

void IControllerParameter::destroyArguments(const IMethodNode& node, void **params)
{
    auto inst = instance();
    inst->destroyReturnParam(params[0], node.returnTypeId);

    for(int i=0; i<node.getParamCount(); i++){
        inst->destroyArgParam(node.paramNodes[i], params[i+1]);
    }
}

void IControllerParameter::resolveReturnValue(IResponse& response, const IMethodNode& functionNode, ParamType &params)
{
    QMetaType::Type typeId = functionNode.returnTypeId;
    QSharedPointer<IResponseWare> responseWare;
    auto inst = instance();
    switch (typeId) {
    case QMetaType::Void:
        inst->wrapVoidReturnInstance(response, functionNode, params);
        return;
    case QMetaType::QString:
        responseWare = inst->createStringReturnInstance(params);
        break;
    case QMetaType::Int:
        responseWare = QSharedPointer<IStatusCodeResponse>::create(*static_cast<int*>(params[0]));;
        break;
    case QMetaType::QJsonArray:
        responseWare = QSharedPointer<IJsonResponse>::create(*static_cast<QJsonArray*>(params[0]));
        break;
    case QMetaType::QJsonObject:
        responseWare = QSharedPointer<IJsonResponse>::create(*static_cast<QJsonObject*>(params[0]));
        break;
    case QMetaType::QJsonValue:
        responseWare = QSharedPointer<IJsonResponse>::create(*static_cast<QJsonObject*>(params[0]));
        break;
    case QMetaType::QByteArray:
        responseWare = QSharedPointer<IByteArrayResponse>::create(*static_cast<QByteArray*>(params[0]));
        break;
    case QMetaType::QStringList:
        responseWare = QSharedPointer<IPlainTextResponse>::create(IConvertUtil::toString(*static_cast<QStringList*>(params[0])));
        break;
    default:
        auto type = functionNode.returnTypeName;
        if(type.startsWith("I") && type.endsWith("Response")){
            response.setContent(static_cast<IResponseWare*>(params[0]));
            return;
        }else{
            QString info = type + " not supported, please change the return type!";
            qFatal(info.toUtf8());
        }
    }
    response.setContent(responseWare.data());
}

void *IControllerParameter::createReturnParam(int paramTypeId)
{
    return QMetaType::create(paramTypeId);
}

void *IControllerParameter::createArgParam(const IParamNode& node, IRequest &request, bool& ok)
{
    static QVector<CreateParamFunType> funs = {
        &IControllerParameter::getParamOfSystem,
        &IControllerParameter::getParamOfMultipart,
        &IControllerParameter::getParamOfCookiePart,
        &IControllerParameter::getParamOfPrimitiveType,
        &IControllerParameter::getParamOfStringType,
        &IControllerParameter::getParamOfJsonType,
        &IControllerParameter::getParamOfBean,
    };

    ok = true;
    static int length = m_judgeTypes.length();
    for(int i=0; i<length; i++){
        if(m_judgeTypes[i].contains(node.paramTypeId)){
            return std::mem_fn(funs[i])(this, node, request, ok);
        }
    }

    qFatal("error");
    return nullptr;
}

void IControllerParameter::destroyReturnParam(void *obj, int paramTypeId)
{
    QMetaType::destroy(paramTypeId, obj);
}

void IControllerParameter::destroyArgParam(const IParamNode& node, void *obj)
{
    static QVector<ReleaseParamFunType> funs = {
        &IControllerParameter::releaseParamOfSystem,
        &IControllerParameter::releaseParamOfMultipart,
        &IControllerParameter::releaseParamOfCookiePart,
        &IControllerParameter::releaseParamOfPrimitiveType,
        &IControllerParameter::releaseParamOfStringType,
        &IControllerParameter::releaseParamOfJsonType,
        &IControllerParameter::releaseParamOfBean,
    };

    if(obj == nullptr){
        return;
    }

    static int length = m_judgeTypes.length();
    for(int i=0; i<length; i++){
        if(m_judgeTypes[i].contains(node.paramTypeId)){
            auto val = std::mem_fn(funs[i])(this, node, obj);
            if(val == false){
                qFatal(GiveColorSeeSee.toUtf8());
            }
            return;
        }
    }
    qFatal(GiveColorSeeSee.toUtf8());
}

// "IRequest", "IResponse", "ICookieJar", "IMultiPartJar", "IHeaderJar", "ISessionJar"
void *IControllerParameter::getParamOfSystem(const IParamNode& node, IRequest &request, bool& ok)
{
    Q_UNUSED(ok)
    auto index = m_systemTypes.indexOf(node.paramTypeId);

    switch (index / 2) {
    case 0:
        return &request;
    case 1:
        return request.response();
    case 2:
        return request.cookieJar();
    case 3:
        return request.multiPartJar();
    case 4:
        return request.headerJar();
    case 5:
        return request.sessionJar();
    default:
        qFatal("error");
    }
    return nullptr;
}

void *IControllerParameter::getParamOfMultipart(const IParamNode& node, IRequest &request, bool& ok)
{
    auto& parts = request.getRaw()->m_requestMultiParts;
    for(auto& part : parts) {
        if(part.name == node.paramName) {
            return &part;
        }
    }

    IToeUtil::setOk(ok, false);
    request.setInvalid(IHttpStatus::BAD_REQUEST_400, "multipart content do not have content name " + node.paramName);
    return nullptr;
}

void *IControllerParameter::getParamOfCookiePart(const IParamNode &node, IRequest &request, bool& ok)
{
    ICookiePart* part{nullptr};

    int count {0};
    const auto& cookies = request.getRaw()->m_requestCookieParameters;
    for(const auto& cookie : cookies){
        if(cookie.first == node.paramName){
            if(count == 0){
                part = new ICookiePart(cookie.first, cookie.second);
            }
            count ++;
        }
    }

    if(count == 1){
        return part;
    }

    if(count == 0){
        request.setInvalid(IHttpStatus::BAD_REQUEST_400, "ICookiePart does not have name " + node.paramName);
    }else if(count > 1){
        delete part;
        request.setInvalid(IHttpStatus::BAD_REQUEST_400, "ICookiePart has more than one key, name: " + node.paramName);
    }
    IToeUtil::setOk(ok, false);
    return nullptr;
}

void *IControllerParameter::getParamOfBean(const IParamNode& node, IRequest &request, bool& ok)
{
    Q_UNUSED(ok)
    return IControllerBeanParametr::getParamOfBean(node, request);
}

void *IControllerParameter::getParamOfJsonType(const IParamNode& node, IRequest &request, bool& ok)
{
    const auto& content = node.paramName.endsWith("_content")
                              ? request.bodyContent() : request.getParameter(node.paramName, ok);
    if(!ok){
        request.setInvalid(IHttpStatus::BAD_REQUEST_400, "convert to json fail. At " + node.paramTypeName + " " + node.paramName);
        return nullptr;
    }

    auto ptr = IControllerFunctionBaseImplHelper::convertParamToJson(node, content, ok);
    if(!ok){
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, node.paramName + " can`t be converted to json type");
    }
    return ptr;
}

void *IControllerParameter::getParamOfPrimitiveType(const IParamNode &node, IRequest &request, bool& ok)
{    
    const auto& content = node.paramName.endsWith("_content")
                              ? request.bodyContent() : request.getParameter(node.paramName, ok);

    if(!ok || content.isEmpty()){
        request.setInvalid(IHttpStatus::BAD_REQUEST_400, node.paramName + " is empty to convert to any type");
        IToeUtil::setOk(ok, false);
        return nullptr;
    }

    const QString& paramName = node.paramName;
    auto param = QMetaType::create(node.paramTypeId);
    switch (node.paramTypeId) {
    case QMetaType::Bool :
        *static_cast<bool*>(param) = IConvertUtil::toBool(QString(content), ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to bool");
        break;
    case QMetaType::Short:
        *static_cast<short*>(param) = IConvertUtil::toShort(QString(content), ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to short");
        break;
    case QMetaType::UShort:
        *static_cast<ushort*>(param) = IConvertUtil::toUShort(QString(content), ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to ushort");
        break;
    case QMetaType::Int:
        *static_cast<int*>(param) = IConvertUtil::toInt(QString(content), ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to int");
        break;
    case QMetaType::UInt:
        *static_cast<uint*>(param) = IConvertUtil::toUInt(QString(content), ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to UInt");
        break;
    case QMetaType::Long:
        *static_cast<long*>(param) = IConvertUtil::toLong(QString(content), ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to long");
        break;
    case QMetaType::ULong:
        *static_cast<ulong*>(param) = IConvertUtil::toULong(QString(content), ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to ulong");
        break;
    case QMetaType::LongLong:
        *static_cast<qlonglong*>(param) = IConvertUtil::toLongLong(QString(content), ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to LongLong");
        break;
    case QMetaType::ULongLong:
        *static_cast<qulonglong*>(param) = IConvertUtil::toULongLong(QString(content), ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to ULongLong");
        break;
    case QMetaType::Float:
        *static_cast<float*>(param) = IConvertUtil::toFloat(QString(content), ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to float");
        break;
    case QMetaType::Double:
        *static_cast<double*>(param) = IConvertUtil::toDouble(QString(content), ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to double");
        break;
    }

    return param;
}

void *IControllerParameter::getParamOfStringType(const IParamNode &node, IRequest &request, bool& ok)
{
    const auto& content = node.paramName.endsWith("_content") ? request.bodyContent()
                                                  : request.getParameter(node.paramName, ok);
    if(ok){
        if(node.paramTypeId == QMetaType::QString){
            QString value = QString(content);
            return QMetaType::create(QMetaType::QString, &value);
        }else if(node.paramTypeId == QMetaType::QByteArray){
            return QMetaType::create(QMetaType::QByteArray, &content);
        }
    }

    request.setInvalid(IHttpStatus::BAD_REQUEST_400, "param of string not exist, name: " + node.paramName);
    return nullptr;
}

bool IControllerParameter::releaseParamOfSystem(const IParamNode& node, void *obj)
{
    Q_UNUSED(node)
    Q_UNUSED(obj)
    return true;
}

bool IControllerParameter::releaseParamOfMultipart(const IParamNode& node, void *obj)
{
    Q_UNUSED(node)
    Q_UNUSED(obj)
    return true;
}

bool IControllerParameter::releaseParamOfCookiePart(const IParamNode &node, void *obj)
{
    Q_UNUSED(node)
    if(obj != nullptr){
        auto part = static_cast<ICookiePart*>(obj);
        delete part;
    }
    return true;
}

bool IControllerParameter::releaseParamOfBean(const IParamNode& node, void *obj)
{
    if(obj != nullptr){
        QMetaType::destroy(node.paramTypeId, obj);
    }
    return true;
}

bool IControllerParameter::releaseParamOfJsonType(const IParamNode& node, void *obj)
{
    Q_UNUSED(obj)
    if(obj != nullptr){
        auto id = node.paramTypeId;
        if(id != QMetaType::QJsonValue){
            QMetaType::destroy(id, obj);
        }
    }
    return true;
}

bool IControllerParameter::releaseParamOfPrimitiveType(const IParamNode &node, void *obj)
{
    if(obj != nullptr){
        QMetaType::destroy(node.paramTypeId, obj);
    }
    return true;
}

bool IControllerParameter::releaseParamOfStringType(const IParamNode &node, void *obj)
{
    if(obj != nullptr){
        QMetaType::destroy(node.paramTypeId, obj);
    }
    return true;
}

void IControllerParameter::wrapVoidReturnInstance(IResponse &response, const IMethodNode &functionNode, ParamType &params)
{
    Q_UNUSED(functionNode)
    Q_UNUSED(params)
    if(response.mime() == IHttpMimeHelper::MIME_UNKNOWN_STRING){
        response.setMime(IHttpMime::TEXT_PLAIN_UTF8);
        $Ast->warn("process_void_return_with_request_not_set_mime_error");
    }
    if(response.status() == IHttpStatus::UNKNOWN){
        response.setStatus(IHttpStatus::OK_200);
        $Ast->warn("process_void_return_with_request_not_set_status_error");
    }
}

QSharedPointer<IResponseWare> IControllerParameter::createStringReturnInstance(void **params)
{
    static auto responseMange = IResponseManage::instance();
    QSharedPointer<IResponseWare> instance;
    auto value = *static_cast<QString*>(params[0]);
    IResponseWare* response;
    if(value.startsWith("$") && (response = responseMange->convertMatch(value)) != nullptr){
        return response->create(std::move(value)); // TODO: 这里应该使用函数优化掉这个内容
    }

    return QSharedPointer<IPlainTextResponse>::create(std::move(value));
}

// 这个地方应该是拷贝instance, 而不是 放置数据
QSharedPointer<IResponseWare> IControllerParameter::createInterfaceReturnInstance(void **params)
{
    auto value = static_cast<IResponseWare*>(params[0]);
    auto instance = value->create(value);        // TODO: 先解决另外一个问题
//    instance->setInstanceCopy(value);
    return instance;
}

void IControllerParameter::initSystemTypes(){
    static const QStringList SystemTypeNames = {
        "IRequest", "IResponse", "ICookieJar", "IMultiPartJar", "IHeaderJar", "ISessionJar"
    };

    static std::once_flag flag;
    std::call_once(flag, [&](){
        QString nmspace = QString($PackageWebCoreName).append("::");

        for(const auto& name : SystemTypeNames){
            m_systemTypes << QMetaType::type((nmspace + name).toUtf8());
            m_systemTypes << QMetaType::type((nmspace + name + "&").toUtf8());
        }
    });
}

void IControllerParameter::initMultiPartTypes(){
    static std::once_flag flag;
    std::call_once(flag, [&](){
//        QString nmspace = QString($PackageWebCoreName).append("::");
        const QString nmspace = "";
        m_multiPartTypes << QMetaType::type((nmspace + "IMultiPart").toUtf8());
        m_multiPartTypes << QMetaType::type((nmspace + "IMultiPart&").toUtf8());
    });
}

void IControllerParameter::initCookiePartTypes(){
    static std::once_flag flag;
    std::call_once(flag, [&](){
//        QString nmspace = QString($PackageWebCoreName).append("::");
        const QString nmspace = "";
        m_cookiePartTypes << QMetaType::type((nmspace + "ICookiePart").toUtf8());
        m_cookiePartTypes << QMetaType::type((nmspace + "ICookiePart&").toUtf8());
    });
}

void IControllerParameter::initPrimitiveTypes()
{
    m_primitiveTypes = {
        QMetaType::Bool,
        QMetaType::Short, QMetaType::UShort,
        QMetaType::Int, QMetaType::UInt,
        QMetaType::Long, QMetaType::ULong,
        QMetaType::LongLong, QMetaType::ULongLong,
        QMetaType::Float, QMetaType::Double
    };

    m_jsonTypes = {
        QMetaType::QJsonValue,
        QMetaType::QJsonArray,
        QMetaType::QJsonObject
    };

    m_stringTypes = {
        QMetaType::QString,
        QMetaType::QByteArray
    };
}

void IControllerParameter::initBeanTypes(){
    static std::once_flag flag;
    std::call_once(flag, [&](){
        for(int id=QMetaType::User; ; id++){
            QString name = QMetaType::typeName(id);
            if(name.isEmpty()){
                break;
            }
            if(IBeanTypeManage::containBean(name)){
                m_beanTypes << id;
            }
        }
    });
}

void* IControllerFunctionBaseImplHelper::convertParamToJson(const IParamNode &node, const QByteArray &content, bool& ok)
{
    IToeUtil::setOk(ok, true);
    auto param = QMetaType::create(node.paramTypeId);
    switch (node.paramTypeId) {
    case QMetaType::QJsonArray:
        *static_cast<QJsonArray*>(param) = IConvertUtil::toJsonArray(content, ok);
        break;
    case QMetaType::QJsonObject:
        *static_cast<QJsonObject*>(param) = IConvertUtil::toJsonObject(content, ok);
        break;
    case QMetaType::QJsonValue:
        *static_cast<QJsonValue*>(param) = IConvertUtil::toJsonValue(QString(content), ok);
        break;
    }
    return param;
}

void IControllerParameter::task()
{
    initPrimitiveTypes();
    initSystemTypes();
    initMultiPartTypes();
    initCookiePartTypes();
    initBeanTypes();

    static std::once_flag flag;
    std::call_once(flag, [&](){
        m_judgeTypes << m_systemTypes;
        m_judgeTypes << m_multiPartTypes;
        m_judgeTypes << m_cookiePartTypes;
        m_judgeTypes << m_primitiveTypes;
        m_judgeTypes << m_stringTypes;
        m_judgeTypes << m_jsonTypes;
        m_judgeTypes << m_beanTypes;
    });
}

$PackageWebCoreEnd
