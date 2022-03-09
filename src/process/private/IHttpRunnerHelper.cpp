﻿#include "IHttpRunnerHelper.h"

#include "assertion/IAssertPreProcessor.h"
#include "base/IJsonUtil.h"
#include "bean/IBeanWare.h"

#include "common/node/IFunctionNode.h"
#include "common/net/IMultiPart.h"
#include "common/net/IRequest.h"
#include "common/net/IResponse.h"
#include "common/response/IResponseInterface.h"
#include "common/response/IResponseManage.h"
#include "common/response/IPlainTextResponse.h"
#include "common/response/IStatusCodeResponse.h"
#include "common/response/IJsonResponse.h"
#include "common/response/IByteArrayResponse.h"
#include "common/type/ITypeManage.h"
#include "common/net/impl/IReqRespRaw.h"
#include "process/private/IRequestBeanParamWiredHelper.h"
#include "task/ITaskManage.h"

$PackageWebCoreBegin

// show me something that should not be wrong
static const QString GiveColorSeeSee = QStringLiteral("浪额康康四辣锅削阔爱");

static QVector<int> SystemTypes;

static QVector<int> PrimitiveTypes = {
    QMetaType::Bool,
    QMetaType::Short, QMetaType::UShort,
    QMetaType::Int, QMetaType::UInt,
    QMetaType::Long, QMetaType::ULong,
    QMetaType::LongLong, QMetaType::ULongLong,
    QMetaType::Float, QMetaType::Double
};

static QVector<int> MultiPartTypes;
static QVector<int> CookieTypes;
static QVector<int> SessionTypes;

static QVector<int> JsonTypes = {
    QMetaType::QJsonValue,
    QMetaType::QJsonArray,
    QMetaType::QJsonObject
};

static QVector<int> StringTypes = {
    QMetaType::QString,
    QMetaType::QByteArray
};

static QVector<int> BeanTypes;

static QVector<QVector<int>> JudgeTypes;

namespace IControllerFunctionBaseImplHelper{
void initSystemTypes();
void initMultiPartTypes();
void initCookieTypes();
void initSessionTypes();
void initBeanTypes();
void initJudgeTypes();

void* convertParamToJson(const IFunctionParamNode &node, const QByteArray &content, bool* ok);

}

void IHttpRunnerHelper::createParams(const IFunctionNode& functionNode, ParamType& params, IRequest &request)
{
    for(int i=0; i<=10; i++){
        params[i] = nullptr;
    }

    params[0] = createReturnParam(functionNode.funReturnTypeId);

    for(int i=0; i<functionNode.funParamCount; i++){
        params[i + 1] = createArgParam(functionNode.funParamNodes[i], request);
    }
}

void *IHttpRunnerHelper::createReturnParam(int paramTypeId)
{
    return QMetaType::create(paramTypeId);
}

void *IHttpRunnerHelper::createArgParam(const IFunctionParamNode& node, IRequest &request)
{
    static QVector<CreateParamFunType> funs = {
        &IHttpRunnerHelper::getParamOfSystem,
        &IHttpRunnerHelper::getParamOfMultipart,
        &IHttpRunnerHelper::getParamOfCookie,
        &IHttpRunnerHelper::getParamOfSession,
        &IHttpRunnerHelper::getParamOfPrimitiveType,
        &IHttpRunnerHelper::getParamOfStringType,
        &IHttpRunnerHelper::getParamOfJsonType,
        &IHttpRunnerHelper::getParamOfBean,
    };

    int length = JudgeTypes.length();
    for(int i=0; i<length; i++){
        if(JudgeTypes[i].contains(node.paramTypeId)){
            auto val = funs[i](node, request);
            if(val == nullptr && request.valid()){  //意思是正常返回参数，单参数值是 nullptr, 这种情况不正常
                qFatal(GiveColorSeeSee.toUtf8());       // TODO: 这个逻辑不对
            }
            return val;
        }
    }
    qFatal(GiveColorSeeSee.toUtf8());
    return nullptr;
}

void IHttpRunnerHelper::destroyParams(const IFunctionNode& functionNode, void **params)
{
    destroyReturnParam(params[0], functionNode.funReturnTypeId);

    for(int i=0; i<functionNode.funParamCount; i++){
        destroyArgParam(functionNode.funParamNodes[i], params[i+1]);
    }
}

void IHttpRunnerHelper::destroyReturnParam(void *obj, int paramTypeId)
{
    QMetaType::destroy(paramTypeId, obj);
}

void IHttpRunnerHelper::destroyArgParam(const IFunctionParamNode& node, void *obj)
{
    static QVector<ReleaseParamFunType> funs = {
        &IHttpRunnerHelper::releaseParamOfSystem,
        &IHttpRunnerHelper::releaseParamOfMultipart,
        &IHttpRunnerHelper::releaseParamOfCookie,
        &IHttpRunnerHelper::releaseParamOfSession,
        &IHttpRunnerHelper::releaseParamOfPrimitiveType,
        &IHttpRunnerHelper::releaseParamOfStringType,
        &IHttpRunnerHelper::releaseParamOfJsonType,
        &IHttpRunnerHelper::releaseParamOfBean,
    };

    if(obj == nullptr){
        return;
    }

    int length = JudgeTypes.length();
    for(int i=0; i<length; i++){
        if(JudgeTypes[i].contains(node.paramTypeId)){
            auto val = funs[i](node, obj);
            if(val == false){
                qFatal(GiveColorSeeSee.toUtf8());
            }
            return;
        }
    }
    qFatal(GiveColorSeeSee.toUtf8());
}

void IHttpRunnerHelper::resolveReturnValue(IResponse& response, const IFunctionNode& functionNode, ParamType &params)
{
    QMetaType::Type typeId = functionNode.funReturnTypeId;
    QSharedPointer<IResponseWare> instance;

    switch (typeId) {
    case QMetaType::Type::Void:
        wrapVoidReturnInstance(response, functionNode, params);
        return;
    case QMetaType::QString:
        instance = createStringReturnInstance(params);
        break;
    case QMetaType::Int:
        instance = createIntReturnInstance(params);
        break;
    case QMetaType::QJsonArray:
        instance = createJsonArrayReturnInstance(params);
        break;
    case QMetaType::QJsonObject:
        instance = createJsonObjectReturnInstance(params);
        break;
    case QMetaType::QJsonValue:
        instance = createJsonValueReturnInstance(params);
        break;
    case QMetaType::QByteArray:
        instance = createByteArrayReturnInstance(params);
        break;
    case QMetaType::Type::QStringList:
        instance = createStringListReturnType(params);
        break;
    default:
        auto type = functionNode.funRetunType;
        if(type.startsWith("I") && type.endsWith("Response")){
            instance = createInterfaceReturnInstance(params);
        }else{
            QString info = type + " not supported, please change the return type!";
            qFatal(info.toUtf8());
        }
    }
    response.setContent(instance.data());
}

void IHttpRunnerHelper::wrapVoidReturnInstance(IResponse &response, const IFunctionNode &functionNode, ParamType &params)
{
    Q_UNUSED(functionNode)
    Q_UNUSED(params)
    if(response.mime() == IHttpMime::UNKNOWN){
        response.setMime(IHttpMime::TEXT_PLAIN_UTF8);
        $AssertWarning(process_void_return_with_request_not_set_mime_error)
    }
    if(response.status() == IHttpStatus::UNKNOWN){
        response.setStatus(IHttpStatus::OK_200);
        $AssertWarning(process_void_return_with_request_not_set_status_error)
    }
}

QSharedPointer<IResponseWare> IHttpRunnerHelper::createStringReturnInstance(void **params)
{
    QSharedPointer<IResponseWare> instance;
    auto value = *static_cast<QString*>(params[0]);
    IResponseWare* response;
    if(value.startsWith("$") && (response = IResponseManage::convertMatch(value)) != nullptr){
        instance = response->createInstance();
    }else{
        instance = IPlainTextResponse::createIPlainTexInstance();
    }
    instance->setInstanceArg(std::move(value)); // 这一个是使用 QString 传入参数，其他的全部使用 void* 传入
    return instance;
}

QSharedPointer<IResponseWare> IHttpRunnerHelper::createIntReturnInstance(void **params)
{
    auto instance = IStatusCodeResponse::createStatusCodeInstance();
    instance->setInstanceArg(params[0]);
    return instance;
}

QSharedPointer<IResponseWare> IHttpRunnerHelper::createJsonValueReturnInstance(void **params)
{
    static const QString suffix = "QJsonValue";
    auto instance = IJsonResponse::createJsonInstance();
    instance->setInstanceArg(params[0], suffix);
    return instance;
}

QSharedPointer<IResponseWare> IHttpRunnerHelper::createJsonObjectReturnInstance(void **params)
{
    static const QString suffix = "QJsonObject";
    auto instance = IJsonResponse::createJsonInstance();
    instance->setInstanceArg(params[0], suffix);
    return instance;
}

QSharedPointer<IResponseWare> IHttpRunnerHelper::createJsonArrayReturnInstance(void **params)
{
    static const QString suffix = "QJsonArray";
    auto instance = IJsonResponse::createJsonInstance();
    instance->setInstanceArg(params[0], suffix);
    return instance;
}

QSharedPointer<IResponseWare> IHttpRunnerHelper::createByteArrayReturnInstance(void **params)
{
    auto instance = IByteArrayResponse::createByteArrayInstance();
    instance->setInstanceArg(params[0]);
    return instance;
}

QSharedPointer<IResponseWare> IHttpRunnerHelper::createStringListReturnType(void **params)
{
    auto value = static_cast<QStringList*>(params[0]);
    auto string = IConvertUtil::toString(*value);
    auto instance = IPlainTextResponse::createIPlainTexInstance();
    instance->setInstanceArg(std::move(string));
    return instance;
}

// 这个地方应该是拷贝instance, 而不是 放置数据
QSharedPointer<IResponseWare> IHttpRunnerHelper::createInterfaceReturnInstance(void **params)
{
    auto value = static_cast<IResponseWare*>(params[0]);
    auto instance = value->createInstance();
    instance->setInstanceCopy(value);
    return instance;
}

void *IHttpRunnerHelper::getParamOfSystem(const IFunctionParamNode& node, IRequest &request)
{
    if(node.paramTypeId == SystemTypes[0] || node.paramTypeId == SystemTypes[1]){
        return &request;
    }
    return request.response();
}

void *IHttpRunnerHelper::getParamOfMultipart(const IFunctionParamNode& node, IRequest &request)
{
    auto& parts = request.getRaw()->m_requestMultiParts;
    for(auto& part : parts){
        if(part.name == node.paramName){
            return &part;
        }
    }

    request.setInvalid(IHttpStatus::BAD_REQUEST_400, "multipart content do not have content name " + node.paramName);
    return nullptr;
}

void *IHttpRunnerHelper::getParamOfCookie(const IFunctionParamNode &node, IRequest &request)
{
    Q_UNUSED(node)
    return &request.getRaw()->m_cookie;
}

void *IHttpRunnerHelper::getParamOfSession(const IFunctionParamNode &node, IRequest &request)
{
    Q_UNUSED(node)
    return request.session();
}

void *IHttpRunnerHelper::getParamOfBean(const IFunctionParamNode& node, IRequest &request)
{
    return IRequestBeanParamWiredHelper::getParamOfBean(node, request);
}

void *IHttpRunnerHelper::getParamOfJsonType(const IFunctionParamNode& node, IRequest &request)
{
    bool convertOk;
    QByteArray content;
    if(node.paramName.endsWith("_content")){
        content = request.bodyContent();
    }else{
        content = request.getParameter(node.paramName, &convertOk);
        if(!convertOk){
            request.setInvalid(IHttpStatus::BAD_REQUEST_400, "convert to json fail. At " + node.paramType + " " + node.paramName);
            return nullptr;
        }
    }

    auto ptr = IControllerFunctionBaseImplHelper::convertParamToJson(node, content, &convertOk);
    if(!convertOk){
        request.setInvalidIf(!convertOk, IHttpStatus::BAD_REQUEST_400, node.paramName + " can`t be converted to json type");
    }
    return ptr;
}

void *IHttpRunnerHelper::getParamOfPrimitiveType(const IFunctionParamNode &node, IRequest &request)
{
    bool ok = true;
    const QString paramName = node.paramName;

    QString content;
    if(node.paramName.endsWith("_content")){
        content = request.bodyContent();
    }else{
        content = request.getParameter(paramName, &ok);
    }
    if(!ok || content.isEmpty()){
        request.setInvalid(IHttpStatus::BAD_REQUEST_400, paramName + " is empty to convert to any type");
        return nullptr;
    }

    auto param = QMetaType::create(node.paramTypeId);
    switch (node.paramTypeId) {
    case QMetaType::Bool :
        *static_cast<bool*>(param) = IConvertUtil::toBool(QString(content), &ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to bool");
        break;
    case QMetaType::Short:
        *static_cast<short*>(param) = IConvertUtil::toShort(content, &ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to short");
        break;
    case QMetaType::UShort:
        *static_cast<ushort*>(param) = IConvertUtil::toUShort(content, &ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to ushort");
        break;
    case QMetaType::Int:
        *static_cast<int*>(param) = IConvertUtil::toInt(content, &ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to int");
        break;
    case QMetaType::UInt:
        *static_cast<uint*>(param) = IConvertUtil::toUInt(content, &ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to UInt");
        break;
    case QMetaType::Long:
        *static_cast<long*>(param) = IConvertUtil::toLong(content, &ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to long");
        break;
    case QMetaType::ULong:
        *static_cast<ulong*>(param) = IConvertUtil::toULong(content, &ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to ulong");
        break;
    case QMetaType::LongLong:
        *static_cast<qlonglong*>(param) = IConvertUtil::toLongLong(content, &ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to LongLong");
        break;
    case QMetaType::ULongLong:
        *static_cast<qulonglong*>(param) = IConvertUtil::toULongLong(content, &ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to ULongLong");
        break;
    case QMetaType::Float:
        *static_cast<float*>(param) = IConvertUtil::toFloat(content, &ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to float");
        break;
    case QMetaType::Double:
        *static_cast<double*>(param) = IConvertUtil::toDouble(content, &ok);
        request.setInvalidIf(!ok, IHttpStatus::BAD_REQUEST_400, paramName + " can`t be converted to double");
        break;
    }
    return param;
}

void *IHttpRunnerHelper::getParamOfStringType(const IFunctionParamNode &node, IRequest &request)
{
    bool convertOk = true;
    QByteArray content;

    if(node.paramName.endsWith("_content")){
        content = request.bodyContent();
    }else{
        content = request.getParameter(node.paramName, &convertOk);
    }

    if(convertOk){
        if(node.paramTypeId == QMetaType::QString){
            QString value = QString(content);
            return QMetaType::create(QMetaType::QString, &value);
        }else if(node.paramTypeId == QMetaType::QByteArray){
            return QMetaType::create(QMetaType::QByteArray, &content);
        }
    }
    request.setInvalid(IHttpStatus::BAD_REQUEST_400, "param of string not exist");
    return nullptr;
}

bool IHttpRunnerHelper::releaseParamOfSystem(const IFunctionParamNode& node, void *obj)
{
    Q_UNUSED(obj);
    return SystemTypes.contains(node.paramTypeId);
}

bool IHttpRunnerHelper::releaseParamOfMultipart(const IFunctionParamNode& node, void *obj)
{
    Q_UNUSED(obj)
    return MultiPartTypes.contains(node.paramTypeId);
}

bool IHttpRunnerHelper::releaseParamOfCookie(const IFunctionParamNode &node, void *obj)
{
    Q_UNUSED(obj)
    return CookieTypes.contains(node.paramTypeId);
}

bool IHttpRunnerHelper::releaseParamOfSession(const IFunctionParamNode &node, void *obj)
{
    Q_UNUSED(obj)
    return SessionTypes.contains(node.paramTypeId);
}

bool IHttpRunnerHelper::releaseParamOfBean(const IFunctionParamNode& node, void *obj)
{
    if(node.paramTypeId >= QMetaType::User && ITypeManage::containBean(node.paramType)){
        QMetaType::destroy(node.paramTypeId, obj);
        return true;
    }
    return false;
}

bool IHttpRunnerHelper::releaseParamOfJsonType(const IFunctionParamNode& node, void *obj)
{
    Q_UNUSED(obj)
    auto id = node.paramTypeId;
    if(JsonTypes.contains(node.paramTypeId)){
        if(id != QMetaType::QJsonValue){
            QMetaType::destroy(id, obj);
        }
        return true;
    }
    return false;
}

bool IHttpRunnerHelper::releaseParamOfPrimitiveType(const IFunctionParamNode &node, void *obj)
{
    if(PrimitiveTypes.contains(node.paramTypeId)){
        QMetaType::destroy(node.paramTypeId, obj);
        return true;
    }
    return false;
}

bool IHttpRunnerHelper::releaseParamOfStringType(const IFunctionParamNode &node, void *obj)
{
    if(node.paramTypeId == QMetaType::QString || node.paramTypeId == QMetaType::QByteArray){
        QMetaType::destroy(node.paramTypeId, obj);
        return true;
    }
    return false;
}

void IControllerFunctionBaseImplHelper::initSystemTypes(){
    static std::once_flag flag;
    std::call_once(flag, [](){
        QString nmspace = QString($PackageWebCoreName).append("::");
        SystemTypes << QMetaType::type((nmspace + "IRequest").toUtf8());
        SystemTypes << QMetaType::type((nmspace + "IRequest&").toUtf8());
        SystemTypes << QMetaType::type((nmspace + "IResponse").toUtf8());
        SystemTypes << QMetaType::type((nmspace + "IResponse&").toUtf8());
    });
}

void IControllerFunctionBaseImplHelper::initMultiPartTypes(){
    static std::once_flag flag;
    std::call_once(flag, [](){
//        QString nmspace = QString($PackageWebCoreName).append("::");
        const QString nmspace = "";
        MultiPartTypes << QMetaType::type((nmspace + "IMultiPart").toUtf8());
        MultiPartTypes << QMetaType::type((nmspace + "IMultiPart&").toUtf8());
    });
}

void IControllerFunctionBaseImplHelper::initCookieTypes(){
    static std::once_flag flag;
    std::call_once(flag, [](){
//        QString nmspace = QString($PackageWebCoreName).append("::");
        const QString nmspace = "";
        MultiPartTypes << QMetaType::type((nmspace + "ICookie").toUtf8());
        MultiPartTypes << QMetaType::type((nmspace + "ICookie&").toUtf8());
    });
}

void IControllerFunctionBaseImplHelper::initSessionTypes(){
    static std::once_flag flag;
    std::call_once(flag, [](){
//        QString nmspace = QString($PackageWebCoreName).append("::");
        const QString nmspace = "";
        MultiPartTypes << QMetaType::type((nmspace + "ISession").toUtf8());
        MultiPartTypes << QMetaType::type((nmspace + "ISession&").toUtf8());
    });
}

void IControllerFunctionBaseImplHelper::initBeanTypes(){
    static std::once_flag flag;
    std::call_once(flag, [](){
        for(int id=QMetaType::User; ; id++){
            QString name = QMetaType::typeName(id);
            if(name.isEmpty()){
                break;
            }
            if(ITypeManage::containBean(name)){
                BeanTypes << id;
            }
        }
    });
}

void IControllerFunctionBaseImplHelper::initJudgeTypes(){
    static std::once_flag flag;
    std::call_once(flag, [](){
        JudgeTypes << SystemTypes;
        JudgeTypes << MultiPartTypes;
        JudgeTypes << CookieTypes;
        JudgeTypes << SessionTypes;
        JudgeTypes << PrimitiveTypes;
        JudgeTypes << StringTypes;
        JudgeTypes << JsonTypes;
        JudgeTypes << BeanTypes;
    });
}

void* IControllerFunctionBaseImplHelper::convertParamToJson(const IFunctionParamNode &node, const QByteArray &content, bool* ok)
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

void IHttpRunnerHelper::task()
{
    IControllerFunctionBaseImplHelper::initSystemTypes();
    IControllerFunctionBaseImplHelper::initMultiPartTypes();
    IControllerFunctionBaseImplHelper::initBeanTypes();
    IControllerFunctionBaseImplHelper::initJudgeTypes();
}

$PackageWebCoreEnd
