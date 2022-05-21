INCLUDEPATH += $$PWD

QT += network sql xml

PRECOMPILED_HEADER = $$PWD/base/IHeaderUtil.h

HEADERS += \
    $$PWD/core/application/IApplication.h \
    $$PWD/core/assertion/IAssertDetail.h \
    $$PWD/core/assertion/IAssertJsonInterface.h \
    $$PWD/core/assertion/infos/ConfigurationAssertion.h \
    $$PWD/core/assertion/infos/ControllerFatalAssertion.h \
    $$PWD/core/assertion/infos/ControllerWarnAssertion.h \
    $$PWD/core/assertion/infos/DeferRegisterNotAllowedFatal.h \
    $$PWD/core/assertion/infos/OrmFatalAssertion.h \
    $$PWD/core/assertion/infos/OrmWarnAssertion.h \
    $$PWD/core/assertion/infos/configuration/ConfigurationMayNotInitializedAssert.h \
    $$PWD/base/ICodecUtil.h \
    $$PWD/base/IConstantUtil.h \
    $$PWD/base/IConvertUtil.h \
    $$PWD/base/IFileUtil.h \
    $$PWD/base/IHeaderUtil.h \
    $$PWD/base/IJsonUtil.h \
    $$PWD/base/IJsonUtil_tojson.h \
    $$PWD/base/IMetaUtil.h \
    $$PWD/base/IPackageUtil.h \
    $$PWD/base/IPreProcessorUtil.h \
    $$PWD/base/ISocketUtil.h \
    $$PWD/base/ITicTacUtil.h \
    $$PWD/base/IToeUtil.h \
    $$PWD/base/ITraitHelper.h \
    $$PWD/base/IXmlUtil.h \
    $$PWD/core/ast/IAstInfo.h \
    $$PWD/core/ast/IAstInterface.h \
    $$PWD/core/ast/IAstPreProcessor.h \
    $$PWD/core/ast/IGlobalAst.h \
    $$PWD/core/bean/IBeanInterface.h \
    $$PWD/core/bean/IBeanPreProcessor.h \
    $$PWD/core/bean/IBeanWare.h \
    $$PWD/core/bean/IGadgetUnit.h \
    $$PWD/core/bean/ITypeManage.h \
    $$PWD/web/IInterceptInterface.h \
    $$PWD/web/IManage.h \
    $$PWD/web/biscuits/IHttpCharset.h \
    $$PWD/web/biscuits/IHttpHeader.h \
    $$PWD/web/biscuits/IHttpMethod.h \
    $$PWD/web/biscuits/IHttpMime.h \
    $$PWD/web/biscuits/IHttpStatus.h \
    $$PWD/web/biscuits/IHttpVersion.h \
    $$PWD/web/cookie/ICookieJar.h \
    $$PWD/web/cookie/ICookiePart.h \
    $$PWD/web/core/defaultTask/IBluePrintControllerTask.h \
    $$PWD/web/header/IHeaderJar.h \
    $$PWD/web/middleware/IInterceptorWare.h \
    $$PWD/web/middleware/IMiddleWare.h \
    $$PWD/web/middleware/IMiddleWarePreProcessor.h \
    $$PWD/web/middleware/IPostInterceptorInterface.h \
    $$PWD/web/middleware/IPostProcessorInterface.h \
    $$PWD/web/middleware/IPreInterceptorInterface.h \
    $$PWD/web/middleware/IPreProcessorInterface.h \
    $$PWD/web/middleware/IProcessorWare.h \
    $$PWD/web/multipart/IMultiPartJar.h \
    $$PWD/web/net/IMultiPart.h \
    $$PWD/web/net/IRequest.h \
    $$PWD/web/net/IResponse.h \
    $$PWD/web/net/impl/IReqRespRaw.h \
    $$PWD/web/net/impl/IRequestImpl.h \
    $$PWD/web/net/impl/IResponseAst.h \
    $$PWD/web/net/impl/IResponseImpl.h \
    $$PWD/web/node/IFunctionNode.h \
    $$PWD/web/node/IStatusFunctionNode.h \
    $$PWD/web/node/IUrlFunctionNode.h \
    $$PWD/web/response/IByteArrayResponse.h \
    $$PWD/web/response/IHtmlResponse.h \
    $$PWD/web/response/IJsonResponse.h \
    $$PWD/web/response/IPlainTextResponse.h \
    $$PWD/web/response/IRedirectResponse.h \
    $$PWD/web/response/IResponseInterface.h \
    $$PWD/web/response/IResponseManage.h \
    $$PWD/web/response/IResponsePreProcessor.h \
    $$PWD/web/response/IResponseWare.h \
    $$PWD/web/response/IResponseWareRaw.h \
    $$PWD/web/response/IStatusCodeResponse.h \
    $$PWD/web/response/response \
    $$PWD/web/session/ISessionJar.h \
    $$PWD/core/unit/IJarUnit.h \
    $$PWD/core/unit/INoConstructUnit.h \
    $$PWD/core/unit/INoCopyMoveUnit.h \
    $$PWD/core/unit/IRegisterGadgetUnit.h \
    $$PWD/core/unit/IRegisterInstanceUnit.h \
    $$PWD/core/unit/IRegisterMetaTypeUnit.h \
    $$PWD/core/unit/IRegisterTypeUnit.h \
    $$PWD/core/unit/IThreadUnit.h \
    $$PWD/core/configuration/IConfigurationInstancePreProcessor.h \
    $$PWD/core/configuration/IConfigurationInterface.h \
    $$PWD/core/configuration/IConfigurationManage.h \
    $$PWD/core/configuration/IConfigurationPreProcessor.h \
    $$PWD/core/configuration/IConfigurationResourceAutoLoader.h \
    $$PWD/core/configuration/IConfigurationSystemPreProcessor.h \
    $$PWD/core/configuration/IConfigurationTaskInterface.h \
    $$PWD/core/configuration/IConfigurationWirePreProcessor.h \
    $$PWD/core/configuration/defaultConfiguration/IBannerConfiguration.h \
    $$PWD/core/configuration/yaml/IYamlUtil.h \
    $$PWD/core/configuration/yaml/Yaml.hpp \
    $$PWD/web/controller/IControllerInterface.h \
    $$PWD/web/controller/IControllerManage.h \
    $$PWD/web/controller/IControllerPathValidatorInterface.h \
    $$PWD/web/controller/IControllerRouteNode.h \
    $$PWD/web/controller/IStatusControllerInterface.h \
    $$PWD/web/controller/pp/IControlVariablePreProcessor.h \
    $$PWD/web/controller/pp/IControllerPreProcessor.h \
    $$PWD/web/controller/pp/IDeleteMappingPreProcessor.h \
    $$PWD/web/controller/pp/IGetMappingPreProcessor.h \
    $$PWD/web/controller/pp/IPatchMappingPreProcessor.h \
    $$PWD/web/controller/pp/IPostMappingPreProcessor.h \
    $$PWD/web/controller/pp/IPutMappingPreProcessor.h \
    $$PWD/web/controller/pp/IStatusCodeMappingPreProcessor.h \
    $$PWD/web/controller/pp/IStatusControllerPreProcessor.h \
    $$PWD/web/controller/private/IControllerInterfaceDebug.h \
    $$PWD/web/controller/private/IControllerInterfaceImpl.h \
    $$PWD/web/controller/private/IControllerParamBeanUtil.h \
    $$PWD/web/controller/private/IControllerParamUtil.h \
    $$PWD/web/controller/private/IDefaultStatusController.h \
    $$PWD/web/controller/private/IStatusControllerInterfaceImpl.h \
    $$PWD/core/assertion/IAssertInfoList.h \
    $$PWD/core/assertion/IAssertInterface.h \
    $$PWD/core/assertion/IAssertManage.h \
    $$PWD/core/assertion/IAssertPreProcessor.h \
    $$PWD/core/application/IArgumentTaskInterface.h \
    $$PWD/orm/IOrmManage.h \
    $$PWD/orm/IOrmUtil.h \
    $$PWD/orm/database/IOrmDataSource.h \
    $$PWD/orm/database/IOrmDatabaseInterface.h \
    $$PWD/orm/database/IOrmDatabaseWare.h \
    $$PWD/orm/dialect/IOrmDialectInterface.h \
    $$PWD/orm/dialect/IOrmDialectWare.h \
    $$PWD/orm/model/IOrmEntityModeWare.h \
    $$PWD/orm/model/IOrmTableModelInterface.h \
    $$PWD/orm/model/IOrmViewModelInterface.h \
    $$PWD/orm/pp/IOrmPreProcessor.h \
    $$PWD/orm/pp/IOrmTablePreProcessor.h \
    $$PWD/orm/pp/IOrmViewPreProcessor.h \
    $$PWD/orm/private/IOrmConditionImpl.h \
    $$PWD/orm/ISqlQuery.h \
    $$PWD/orm/clause/IOrmClause.h \
    $$PWD/orm/clause/IOrmCondition.h \
    $$PWD/orm/clause/IOrmQueryClause.h \
    $$PWD/orm/dialect/IOrmMySqlDialect.h \
    $$PWD/orm/dialect/IOrmSqliteDialect.h \
    $$PWD/orm/private/IOrmDatabaseWareImpl.h \
    $$PWD/orm/tableview/IOrmEntityInfoWare.h \
    $$PWD/orm/tableview/IOrmEntityWare.h \
    $$PWD/orm/tableview/IOrmTableInfo.h \
    $$PWD/orm/tableview/IOrmTableInterface.h \
    $$PWD/orm/tableview/IOrmTableWare.h \
    $$PWD/orm/tableview/IOrmViewInfo.h \
    $$PWD/orm/tableview/IOrmViewInterface.h \
    $$PWD/orm/tableview/IOrmViewWare.h \
    $$PWD/web/server/IHttpServer.h \
    $$PWD/web/server/IHttpServerManage.h \
    $$PWD/web/server/IServerInterface.h \
    $$PWD/web/server/multiThreadServer/IHttpServerRunable.h \
    $$PWD/web/server/multiThreadServer/IMultiThreadServer.h \
    $$PWD/web/server/quenedServer/IQueneServer.h \
    $$PWD/core/task/IArgumentTaskUnit.h \
    $$PWD/core/task/IConfigurationTaskUnit.h \
    $$PWD/core/task/IControllerTaskUnit.h \
    $$PWD/core/task/IFirstInvokeTaskUnit.h \
    $$PWD/core/task/IInitializationTaskUnit.h \
    $$PWD/core/task/ILastInvokeTaskUnit.h \
    $$PWD/core/task/IMiddleWareTaskUnit.h \
    $$PWD/core/task/IStaticInitializeTaskUnit.h \
    $$PWD/core/task/ITaskManage.h \
    $$PWD/core/task/ITaskWare.h \
    $$PWD/test/IDebugInterface.h \
    $$PWD/test/IDebugPreProcessor.h

SOURCES += \
    $$PWD/core/application/IApplication.cpp \
    $$PWD/core/assertion/IAssertDetail.cpp \
    $$PWD/core/assertion/IAssertInfoList.cpp \
    $$PWD/core/assertion/IAssertJsonInterface.cpp \
    $$PWD/core/assertion/infos/ConfigurationAssertion.cpp \
    $$PWD/core/assertion/infos/ControllerFatalAssertion.cpp \
    $$PWD/core/assertion/infos/ControllerWarnAssertion.cpp \
    $$PWD/core/assertion/infos/DeferRegisterNotAllowedFatal.cpp \
    $$PWD/core/assertion/infos/OrmFatalAssertion.cpp \
    $$PWD/core/assertion/infos/OrmWarnAssertion.cpp \
    $$PWD/core/assertion/infos/configuration/ConfigurationMayNotInitializedAssert.cpp \
    $$PWD/base/ICodecUtil.cpp \
    $$PWD/base/IConvertUtil.cpp \
    $$PWD/base/IFileUtil.cpp \
    $$PWD/base/IHeaderUtil.cpp \
    $$PWD/base/IJsonUtil.cpp \
    $$PWD/base/IJsonUtil_tojson.cpp \
    $$PWD/base/IJsonUtil_tojson_impl.cpp \
    $$PWD/base/IMetaUtil.cpp \
    $$PWD/base/IPreProcessorUtil.cpp \
    $$PWD/base/ISocketUtil.cpp \
    $$PWD/base/ITicTacUtil.cpp \
    $$PWD/base/IToeUtil.cpp \
    $$PWD/base/ITraitHelper.cpp \
    $$PWD/base/IXmlUtil.cpp \
    $$PWD/core/ast/IAstInfo.cpp \
    $$PWD/core/ast/IAstInterface.cpp \
    $$PWD/core/ast/IGlobalAst.cpp \
    $$PWD/core/bean/IBeanInterface.cpp \
    $$PWD/core/bean/IBeanWare.cpp \
    $$PWD/core/bean/IGadgetUnit.cpp \
    $$PWD/core/bean/ITypeManage.cpp \
    $$PWD/web/IInterceptInterface.cpp \
    $$PWD/web/IManage.cpp \
    $$PWD/web/biscuits/IHttpCharset.cpp \
    $$PWD/web/biscuits/IHttpHeader.cpp \
    $$PWD/web/biscuits/IHttpMethod.cpp \
    $$PWD/web/biscuits/IHttpMime.cpp \
    $$PWD/web/biscuits/IHttpStatus.cpp \
    $$PWD/web/biscuits/IHttpVersion.cpp \
    $$PWD/web/cookie/ICookieJar.cpp \
    $$PWD/web/cookie/ICookiePart.cpp \
    $$PWD/web/core/defaultTask/IBluePrintControllerTask.cpp \
    $$PWD/web/header/IHeaderJar.cpp \
    $$PWD/web/middleware/IInterceptorWare.cpp \
    $$PWD/web/middleware/IMiddleWare.cpp \
    $$PWD/web/middleware/IPostInterceptorInterface.cpp \
    $$PWD/web/middleware/IPostProcessorInterface.cpp \
    $$PWD/web/middleware/IPreInterceptorInterface.cpp \
    $$PWD/web/middleware/IPreProcessorInterface.cpp \
    $$PWD/web/middleware/IProcessorWare.cpp \
    $$PWD/web/multipart/IMultiPartJar.cpp \
    $$PWD/web/net/IMultiPart.cpp \
    $$PWD/web/net/IRequest.cpp \
    $$PWD/web/net/IResponse.cpp \
    $$PWD/web/net/impl/IReqRespRaw.cpp \
    $$PWD/web/net/impl/IRequestImpl.cpp \
    $$PWD/web/net/impl/IResponseAst.cpp \
    $$PWD/web/net/impl/IResponseImpl.cpp \
    $$PWD/web/node/IFunctionNode.cpp \
    $$PWD/web/response/IByteArrayResponse.cpp \
    $$PWD/web/response/IHtmlResponse.cpp \
    $$PWD/web/response/IJsonResponse.cpp \
    $$PWD/web/response/IPlainTextResponse.cpp \
    $$PWD/web/response/IRedirectResponse.cpp \
    $$PWD/web/response/IResponseInterface.cpp \
    $$PWD/web/response/IResponseManage.cpp \
    $$PWD/web/response/IResponseWare.cpp \
    $$PWD/web/response/IResponseWareRaw.cpp \
    $$PWD/web/response/IStatusCodeResponse.cpp \
    $$PWD/web/session/ISessionJar.cpp \
    $$PWD/core/unit/IJarUnit.cpp \
    $$PWD/core/unit/INoCopyMoveUnit.cpp \
    $$PWD/core/unit/IRegisterGadgetUnit.cpp \
    $$PWD/core/unit/IRegisterInstanceUnit.cpp \
    $$PWD/core/unit/IRegisterMetaTypeUnit.cpp \
    $$PWD/core/unit/IRegisterTypeUnit.cpp \
    $$PWD/core/unit/IThreadUnit.cpp \
    $$PWD/core/configuration/IConfigurationInterface.cpp \
    $$PWD/core/configuration/IConfigurationManage.cpp \
    $$PWD/core/configuration/IConfigurationResourceAutoLoader.cpp \
    $$PWD/core/configuration/IConfigurationSystemPreProcessor.cpp \
    $$PWD/core/configuration/IConfigurationTaskInterface.cpp \
    $$PWD/core/configuration/defaultConfiguration/IBannerConfiguration.cpp \
    $$PWD/core/configuration/yaml/IYamlUtil.cpp \
    $$PWD/core/configuration/yaml/Yaml.cpp \
    $$PWD/web/controller/IControllerInterface.cpp \
    $$PWD/web/controller/IControllerManage.cpp \
    $$PWD/web/controller/IControllerPathValidatorInterface.cpp \
    $$PWD/web/controller/IControllerRouteNode.cpp \
    $$PWD/web/controller/IStatusControllerInterface.cpp \
    $$PWD/web/controller/private/IControllerInterfaceDebug.cpp \
    $$PWD/web/controller/private/IControllerInterfaceImpl.cpp \
    $$PWD/web/controller/private/IControllerParamBeanUtil.cpp \
    $$PWD/web/controller/private/IControllerParamUtil.cpp \
    $$PWD/web/controller/private/IDefaultStatusController.cpp \
    $$PWD/web/controller/private/IStatusControllerInterfaceImpl.cpp \
    $$PWD/core/assertion/IAssertInterface.cpp \
    $$PWD/core/assertion/IAssertManage.cpp \
    $$PWD/core/application/IArgumentTaskInterface.cpp \
    $$PWD/orm/IOrmManage.cpp \
    $$PWD/orm/IOrmUtil.cpp \
    $$PWD/orm/database/IOrmDataSource.cpp \
    $$PWD/orm/database/IOrmDatabaseInterface.cpp \
    $$PWD/orm/database/IOrmDatabaseWare.cpp \
    $$PWD/orm/dialect/IOrmDialectInterface.cpp \
    $$PWD/orm/dialect/IOrmDialectWare.cpp \
    $$PWD/orm/model/IOrmEntityModeWare.cpp \
    $$PWD/orm/model/IOrmTableModelInterface.cpp \
    $$PWD/orm/model/IOrmViewModelInterface.cpp \
    $$PWD/orm/private/IOrmConditionImpl.cpp \
    $$PWD/orm/ISqlQuery.cpp \
    $$PWD/orm/clause/IOrmClause.cpp \
    $$PWD/orm/clause/IOrmCondition.cpp \
    $$PWD/orm/clause/IOrmQueryClause.cpp \
    $$PWD/orm/dialect/IOrmMySqlDialect.cpp \
    $$PWD/orm/dialect/IOrmSqliteDialect.cpp \
    $$PWD/orm/private/IOrmDatabaseWareImpl.cpp \
    $$PWD/orm/tableview/IOrmEntityInfoWare.cpp \
    $$PWD/orm/tableview/IOrmEntityWare.cpp \
    $$PWD/orm/tableview/IOrmTableInfo.cpp \
    $$PWD/orm/tableview/IOrmTableInterface.cpp \
    $$PWD/orm/tableview/IOrmTableWare.cpp \
    $$PWD/orm/tableview/IOrmViewInfo.cpp \
    $$PWD/orm/tableview/IOrmViewInterface.cpp \
    $$PWD/orm/tableview/IOrmViewWare.cpp \
    $$PWD/web/server/IHttpServer.cpp \
    $$PWD/web/server/IHttpServerManage.cpp \
    $$PWD/web/server/IServerInterface.cpp \
    $$PWD/web/server/multiThreadServer/IHttpServerRunable.cpp \
    $$PWD/web/server/multiThreadServer/IMultiThreadServer.cpp \
    $$PWD/web/server/quenedServer/IQueneServer.cpp \
    $$PWD/core/task/IArgumentTaskUnit.cpp \
    $$PWD/core/task/IConfigurationTaskUnit.cpp \
    $$PWD/core/task/IControllerTaskUnit.cpp \
    $$PWD/core/task/IFirstInvokeTaskUnit.cpp \
    $$PWD/core/task/IInitializationTaskUnit.cpp \
    $$PWD/core/task/ILastInvokeTaskUnit.cpp \
    $$PWD/core/task/IMiddleWareTaskUnit.cpp \
    $$PWD/core/task/IStaticInitializeTaskUnit.cpp \
    $$PWD/core/task/ITaskManage.cpp \
    $$PWD/core/task/ITaskWare.cpp \
    $$PWD/test/IDebugInterface.cpp

DISTFILES += \
    $$PWD/IWebCore \
    $$PWD/core/core \
    $$PWD/base/base \
    $$PWD/core/bean/bean \
    $$PWD/web/common \
    $$PWD/core/configuration/configuration \
    $$PWD/web/controller/controller \
    $$PWD/core/assertion/assertion \
    $$PWD/orm/orm \
    $$PWD/web/server/server \
    $$PWD/core/task/task
