INCLUDEPATH += $$PWD

QT += network sql
QT -= gui

PRECOMPILED_HEADER = $$PWD/base/IHeaderUtil.h

HEADERS += \
    $$PWD/assertion/IAssertDetail.h \
    $$PWD/assertion/IAssertJsonInterface.h \
    $$PWD/assertion/infos/ConfigurationAssertion.h \
    $$PWD/assertion/infos/ControllerFatalAssertion.h \
    $$PWD/assertion/infos/ControllerWarnAssertion.h \
    $$PWD/assertion/infos/DeferRegisterNotAllowedFatal.h \
    $$PWD/assertion/infos/OrmFatalAssertion.h \
    $$PWD/assertion/infos/OrmWarnAssertion.h \
    $$PWD/assertion/infos/configuration/ConfigurationMayNotInitializedAssert.h \
    $$PWD/base/IConstantUtil.h \
    $$PWD/base/IConvertUtil.h \
    $$PWD/base/IFileUtil.h \
    $$PWD/base/IHeaderUtil.h \
    $$PWD/base/IJsonUtil.h \
    $$PWD/base/IJsonUtil_tojson.h \
    $$PWD/base/IMetaUtil.h \
    $$PWD/base/IOrmUtil.h \
    $$PWD/base/IPreProcessorUtil.h \
    $$PWD/base/ISocketUtil.h \
    $$PWD/base/ITicTacUtil.h \
    $$PWD/base/IToeUtil.h \
    $$PWD/base/ITraitHelper.h \
    $$PWD/base/IXmlUtil.h \
    $$PWD/bean/IBeanInterface.h \
    $$PWD/bean/IBeanPreProcessor.h \
    $$PWD/bean/IBeanWare.h \
    $$PWD/bean/IGadgetUnit.h \
    $$PWD/biscuits/IHttpCharset.h \
    $$PWD/biscuits/IHttpHeader.h \
    $$PWD/biscuits/IHttpStatus.h \
    $$PWD/common/IInterceptInterface.h \
    $$PWD/common/IManage.h \
    $$PWD/common/IRequestPreInterceptInterface.h \
    $$PWD/common/IRequestPreProcessInterface.h \
    $$PWD/common/IResponsePostInterceptInterface.h \
    $$PWD/common/IResponsePostProcessInterface.h \
    $$PWD/common/application/IWebApplication.h \
    $$PWD/common/argument/IArgumentParserInterface.h \
    $$PWD/common/middleware/IControllerMiddleWare.h \
    $$PWD/common/net/ICookie.h \
    $$PWD/common/net/IMultiPart.h \
    $$PWD/common/net/IRequest.h \
    $$PWD/common/net/IResponse.h \
    $$PWD/common/net/ISession.h \
    $$PWD/common/net/impl/IReqRespRaw.h \
    $$PWD/common/net/impl/IRequestImpl.h \
    $$PWD/common/net/impl/IResponseImpl.h \
    $$PWD/common/node/IFunctionNode.h \
    $$PWD/common/node/IStatusFunctionNode.h \
    $$PWD/common/node/IUrlFunctionNode.h \
    $$PWD/common/response/IByteArrayResponse.h \
    $$PWD/common/response/IHtmlResponse.h \
    $$PWD/common/response/IJsonResponse.h \
    $$PWD/common/response/IPlainTextResponse.h \
    $$PWD/common/response/IRedirectResponse.h \
    $$PWD/common/response/IResponseInterface.h \
    $$PWD/common/response/IResponseManage.h \
    $$PWD/common/response/IResponsePreProcessor.h \
    $$PWD/common/response/IResponseWare.h \
    $$PWD/common/response/IResponseWareRaw.h \
    $$PWD/common/response/IStatusCodeResponse.h \
    $$PWD/common/response/response \
    $$PWD/common/support/INoCopyUnit.h \
    $$PWD/common/support/IRegisterGadgetUnit.h \
    $$PWD/common/support/IRegisterInstanceUnit.h \
    $$PWD/common/support/IRegisterMetaTypeUnit.h \
    $$PWD/common/support/IRegisterTypeUnit.h \
    $$PWD/common/support/IThreadUnit.h \
#    $$PWD/common/task/IArgumentParserUnit.h \
#    $$PWD/common/task/IConfigurationTaskUnit.h \
#    $$PWD/common/task/IControllerTaskUnit.h \
#    $$PWD/common/task/IFirstInvokeTaskUnit.h \
#    $$PWD/common/task/IInitializationTaskUnit.h \
#    $$PWD/common/task/ILastInvokeTaskUnit.h \
#    $$PWD/common/task/IStaticInitializeTaskUnit.h \
#    $$PWD/common/task/ITaskManage.h \
#    $$PWD/common/task/ITaskWare.h \
#    $$PWD/common/task/defaultTask/IBluePrintControllerTask.h \
    $$PWD/common/type/ITypeManage.h \
    $$PWD/configuration/IConfigurationInstancePreProcessor.h \
    $$PWD/configuration/IConfigurationInterface.h \
    $$PWD/configuration/IConfigurationManage.h \
    $$PWD/configuration/IConfigurationPreProcessor.h \
    $$PWD/configuration/IConfigurationResourceAutoLoader.h \
    $$PWD/configuration/IConfigurationSystemPreProcessor.h \
    $$PWD/configuration/IConfigurationTaskInterface.h \
    $$PWD/configuration/IConfigurationWirePreProcessor.h \
    $$PWD/configuration/defaultConfiguration/IBannerConfiguration.h \
    $$PWD/controller/IControllerInterface.h \
    $$PWD/biscuits/IHttpMethod.h \
    $$PWD/biscuits/IHttpMime.h \
    $$PWD/biscuits/IHttpVersion.h \
    $$PWD/controller/IControllerManage.h \
    $$PWD/controller/IControllerPathValidatorInterface.h \
    $$PWD/controller/IControllerRouteNode.h \
    $$PWD/controller/IStatusControllerInterface.h \
    $$PWD/controller/pp/IControlVariablePreProcessor.h \
    $$PWD/controller/pp/IControllerPreProcessor.h \
    $$PWD/controller/pp/IDeleteMappingPreProcessor.h \
    $$PWD/controller/pp/IGetMappingPreProcessor.h \
    $$PWD/controller/pp/IPatchMappingPreProcessor.h \
    $$PWD/controller/pp/IPostMappingPreProcessor.h \
    $$PWD/controller/pp/IPutMappingPreProcessor.h \
    $$PWD/controller/pp/IStatusCodeMappingPreProcessor.h \
    $$PWD/controller/pp/IStatusControllerPreProcessor.h \
    $$PWD/controller/private/IControllerInterfaceImpl.h \
    $$PWD/controller/private/IDefaultStatusController.h \
    $$PWD/controller/private/IStatusControllerInterfaceImpl.h \
    $$PWD/assertion/IAssertInfoList.h \
    $$PWD/assertion/IAssertInterface.h \
    $$PWD/assertion/IAssertManage.h \
    $$PWD/assertion/IAssertPreProcessor.h \
    $$PWD/orm/IOrmManage.h \
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
    $$PWD/package/IPackagePreProcessor.h \
    $$PWD/plugin/yaml/IYamlUtil.h \
    $$PWD/plugin/yaml/Yaml.hpp \
    $$PWD/process/IHttpProcesser.h \
    $$PWD/process/IHttpRunner.h \
    $$PWD/process/IHttpSocketManage.h \
    $$PWD/process/private/IHttpRunnerHelper.h \
    $$PWD/process/private/IRequestBeanParamWiredHelper.h \
    $$PWD/process/support/IRequestErrorPreIntercept.h \
    $$PWD/server/IHttpServer.h \
    $$PWD/server/IServer.h \
    $$PWD/server/IServerInterface.h \
    $$PWD/task/IArgumentParserUnit.h \
    $$PWD/task/IConfigurationTaskUnit.h \
    $$PWD/task/IControllerTaskUnit.h \
    $$PWD/task/IFirstInvokeTaskUnit.h \
    $$PWD/task/IInitializationTaskUnit.h \
    $$PWD/task/ILastInvokeTaskUnit.h \
    $$PWD/task/IStaticInitializeTaskUnit.h \
    $$PWD/task/ITaskManage.h \
    $$PWD/task/ITaskWare.h \
    $$PWD/task/defaultTask/IBluePrintControllerTask.h \
    $$PWD/test/ITestPreProcessor.h

SOURCES += \
    $$PWD/assertion/IAssertDetail.cpp \
    $$PWD/assertion/IAssertInfoList.cpp \
    $$PWD/assertion/IAssertJsonInterface.cpp \
    $$PWD/assertion/infos/ConfigurationAssertion.cpp \
    $$PWD/assertion/infos/ControllerFatalAssertion.cpp \
    $$PWD/assertion/infos/ControllerWarnAssertion.cpp \
    $$PWD/assertion/infos/DeferRegisterNotAllowedFatal.cpp \
    $$PWD/assertion/infos/OrmFatalAssertion.cpp \
    $$PWD/assertion/infos/OrmWarnAssertion.cpp \
    $$PWD/assertion/infos/configuration/ConfigurationMayNotInitializedAssert.cpp \
    $$PWD/base/IConvertUtil.cpp \
    $$PWD/base/IFileUtil.cpp \
    $$PWD/base/IHeaderUtil.cpp \
    $$PWD/base/IJsonUtil.cpp \
    $$PWD/base/IJsonUtil_tojson.cpp \
    $$PWD/base/IJsonUtil_tojson_impl.cpp \
    $$PWD/base/IMetaUtil.cpp \
    $$PWD/base/IOrmUtil.cpp \
    $$PWD/base/IPreProcessorUtil.cpp \
    $$PWD/base/ISocketUtil.cpp \
    $$PWD/base/ITicTacUtil.cpp \
    $$PWD/base/IToeUtil.cpp \
    $$PWD/base/ITraitHelper.cpp \
    $$PWD/base/IXmlUtil.cpp \
    $$PWD/bean/IBeanInterface.cpp \
    $$PWD/bean/IBeanWare.cpp \
    $$PWD/bean/IGadgetUnit.cpp \
    $$PWD/biscuits/IHttpCharset.cpp \
    $$PWD/biscuits/IHttpHeader.cpp \
    $$PWD/biscuits/IHttpStatus.cpp \
    $$PWD/common/IInterceptInterface.cpp \
    $$PWD/common/IManage.cpp \
    $$PWD/common/IRequestPreInterceptInterface.cpp \
    $$PWD/common/IRequestPreProcessInterface.cpp \
    $$PWD/common/IResponsePostInterceptInterface.cpp \
    $$PWD/common/IResponsePostProcessInterface.cpp \
    $$PWD/common/application/IWebApplication.cpp \
    $$PWD/common/argument/IArgumentParserInterface.cpp \
    $$PWD/common/middleware/IControllerMiddleWare.cpp \
    $$PWD/common/net/ICookie.cpp \
    $$PWD/common/net/IMultiPart.cpp \
    $$PWD/common/net/IRequest.cpp \
    $$PWD/common/net/IResponse.cpp \
    $$PWD/common/net/ISession.cpp \
    $$PWD/common/net/impl/IReqRespRaw.cpp \
    $$PWD/common/net/impl/IRequestImpl.cpp \
    $$PWD/common/net/impl/IResponseImpl.cpp \
    $$PWD/common/node/IFunctionNode.cpp \
    $$PWD/common/response/IByteArrayResponse.cpp \
    $$PWD/common/response/IHtmlResponse.cpp \
    $$PWD/common/response/IJsonResponse.cpp \
    $$PWD/common/response/IPlainTextResponse.cpp \
    $$PWD/common/response/IRedirectResponse.cpp \
    $$PWD/common/response/IResponseInterface.cpp \
    $$PWD/common/response/IResponseManage.cpp \
    $$PWD/common/response/IResponseWare.cpp \
    $$PWD/common/response/IResponseWareRaw.cpp \
    $$PWD/common/response/IStatusCodeResponse.cpp \
    $$PWD/common/support/INoCopyUnit.cpp \
    $$PWD/common/support/IRegisterGadgetUnit.cpp \
    $$PWD/common/support/IRegisterInstanceUnit.cpp \
    $$PWD/common/support/IRegisterMetaTypeUnit.cpp \
    $$PWD/common/support/IRegisterTypeUnit.cpp \
    $$PWD/common/support/IThreadUnit.cpp \
#    $$PWD/common/task/IArgumentParserUnit.cpp \
#    $$PWD/common/task/IConfigurationTaskUnit.cpp \
#    $$PWD/common/task/IControllerTaskUnit.cpp \
#    $$PWD/common/task/IFirstInvokeTaskUnit.cpp \
#    $$PWD/common/task/IInitializationTaskUnit.cpp \
#    $$PWD/common/task/ILastInvokeTaskUnit.cpp \
#    $$PWD/common/task/IStaticInitializeTaskUnit.cpp \
#    $$PWD/common/task/ITaskManage.cpp \
#    $$PWD/common/task/ITaskWare.cpp \
#    $$PWD/common/task/defaultTask/IBluePrintControllerTask.cpp \
    $$PWD/common/type/ITypeManage.cpp \
    $$PWD/configuration/IConfigurationInterface.cpp \
    $$PWD/configuration/IConfigurationManage.cpp \
    $$PWD/biscuits/IHttpMethod.cpp \
    $$PWD/biscuits/IHttpMime.cpp \
    $$PWD/biscuits/IHttpVersion.cpp \
    $$PWD/configuration/IConfigurationResourceAutoLoader.cpp \
    $$PWD/configuration/IConfigurationSystemPreProcessor.cpp \
    $$PWD/configuration/IConfigurationTaskInterface.cpp \
    $$PWD/configuration/defaultConfiguration/IBannerConfiguration.cpp \
    $$PWD/controller/IControllerInterface.cpp \
    $$PWD/controller/IControllerManage.cpp \
    $$PWD/controller/IControllerPathValidatorInterface.cpp \
    $$PWD/controller/IControllerRouteNode.cpp \
    $$PWD/controller/IStatusControllerInterface.cpp \
    $$PWD/controller/private/IControllerInterfaceImpl.cpp \
    $$PWD/controller/private/IDefaultStatusController.cpp \
    $$PWD/controller/private/IStatusControllerInterfaceImpl.cpp \
    $$PWD/assertion/IAssertInterface.cpp \
    $$PWD/assertion/IAssertManage.cpp \
    $$PWD/orm/IOrmManage.cpp \
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
    $$PWD/plugin/yaml/IYamlUtil.cpp \
    $$PWD/plugin/yaml/Yaml.cpp \
    $$PWD/process/IHttpProcesser.cpp \
    $$PWD/process/IHttpRunner.cpp \
    $$PWD/process/IHttpSocketManage.cpp \
    $$PWD/process/private/IHttpRunnerHelper.cpp \
    $$PWD/process/private/IRequestBeanParamWiredHelper.cpp \
    $$PWD/process/support/IRequestErrorPreIntercept.cpp \
    $$PWD/server/IHttpServer.cpp \
    $$PWD/server/IServerInterface.cpp \
    $$PWD/task/IArgumentParserUnit.cpp \
    $$PWD/task/IConfigurationTaskUnit.cpp \
    $$PWD/task/IControllerTaskUnit.cpp \
    $$PWD/task/IFirstInvokeTaskUnit.cpp \
    $$PWD/task/IInitializationTaskUnit.cpp \
    $$PWD/task/ILastInvokeTaskUnit.cpp \
    $$PWD/task/IStaticInitializeTaskUnit.cpp \
    $$PWD/task/ITaskManage.cpp \
    $$PWD/task/ITaskWare.cpp \
    $$PWD/task/defaultTask/IBluePrintControllerTask.cpp

DISTFILES += \
    $$PWD/IWebCore \
    $$PWD/base/base \
    $$PWD/bean/bean \
    $$PWD/common/common \
    $$PWD/configuration/configuration \
    $$PWD/controller/controller \
    $$PWD/assertion/assertion \
#    $$PWD/log/log \
    $$PWD/orm/orm \
    $$PWD/process/process \
    $$PWD/task/task \
    $$PWD/test/test
