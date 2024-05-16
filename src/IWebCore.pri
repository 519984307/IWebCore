INCLUDEPATH += $$PWD

QT += sql xml testlib

CONFIG += c++17

include($$PWD/core/package/package.pri)

PRECOMPILED_HEADER = $$PWD/core/base/IHeaderUtil.h

HEADERS += \
    $$PWD/IWeb/IHttpControllerInterface \
    $$PWD/core/application/IApplicationAnnomacro.h \
    $$PWD/core/application/IApplicationInterface.h \
    $$PWD/core/application/IAsioApplication.h \
    $$PWD/core/application/IQtApplication.h \
    $$PWD/core/base/ICodecUtil.h \
    $$PWD/core/base/IConstantUtil.h \
    $$PWD/core/base/IConvertUtil.h \
    $$PWD/core/base/IFileUtil.h \
    $$PWD/core/base/IHeaderUtil.h \
    $$PWD/core/base/IJsonUtil.h \
    $$PWD/core/base/IJsonUtil_fromjson.h \
    $$PWD/core/base/IJsonUtil_tojson.h \
    $$PWD/core/base/IMetaUtil.h \
    $$PWD/core/base/IPackageUtil.h \
    $$PWD/core/base/IPreProcessorUtil.h \
#    $$PWD/core/base/ISocketUtil.h \
    $$PWD/core/base/ITicTacUtil.h \
    $$PWD/core/base/IToeUtil.h \
    $$PWD/core/base/ITraitUtil.h \
    $$PWD/core/base/IXmlUtil.h \
    $$PWD/core/assert/IAssertInfo.h \
    $$PWD/core/assert/IAssertInterface.h \
    $$PWD/core/assert/IAssertPreProcessor.h \
    $$PWD/core/assert/IGlobalAssert.h \
    $$PWD/core/bean/IBeanInterface.h \
    $$PWD/core/bean/IBeanPreProcessor.h \
    $$PWD/core/bean/IBeanTypeManage.h \
    $$PWD/core/bean/IBeanWare.h \
    $$PWD/core/config/IConfigAnnomacro.h \
    $$PWD/core/config/IConfigImportInterface.h \
    $$PWD/core/config/IConfigManageInterface.h \
    $$PWD/core/config/IConfigPreProcessor.h \
    $$PWD/core/config/IConfigTaskCatagory.h \
    $$PWD/core/config/IContextImport.h \
    $$PWD/core/config/IContextManage.h \
    $$PWD/core/config/IContextTaskInterface.h \
    $$PWD/core/config/IProfileImport.h \
    $$PWD/core/config/IProfileManage.h \
    $$PWD/core/config/IProfileTaskInterface.h \
    $$PWD/core/config/default/IContextJsonProfileTask.h \
    $$PWD/core/config/default/IContextSystemVariableTask.h \
    $$PWD/core/config/default/IContextTomlProfileTask.h \
    $$PWD/core/config/default/IContextYamlProfileTask.h \
    $$PWD/core/config/default/ILoadProfileFileUnit.h \
    $$PWD/core/core.h \
    $$PWD/core/result/IResult.h \
    $$PWD/core/task/ITaskCatagory.h \
    $$PWD/core/task/ITaskCatagoryInterface.h \
    $$PWD/core/task/ITaskPreProcessor.h \
    $$PWD/core/task/default/IBannerTask.h \
    $$PWD/core/task/default/IEndupTaskCatagory.h \
    $$PWD/core/task/default/IEndupTaskInterface.h \
    $$PWD/core/task/default/IInitializationTaskCatagory.h \
    $$PWD/core/task/default/IInitializationTaskInterface.h \
    $$PWD/core/task/default/IStartupTaskCatagory.h \
    $$PWD/core/task/default/IStartupTaskInterface.h \
    $$PWD/core/task/ITaskManage.h \
    $$PWD/core/task/ITaskWare.h \
    $$PWD/core/task/unit/ITaskCatagoryUnit.h \
    $$PWD/core/task/unit/ITaskInstantUnit.h \
    $$PWD/core/task/unit/ITaskWareUnit.h \
    $$PWD/core/test/ITestBaseInterface.h \
    $$PWD/core/test/ITestCatagory.h \
    $$PWD/core/test/ITestManageBaseInterface.h \
    $$PWD/core/test/ITestTaskBaseInterface.h \
    $$PWD/core/test/IUnitTestInterface.h \
    $$PWD/core/test/IUnitTestManage.h \
    $$PWD/core/test/IUnitTestTask.h \
    $$PWD/core/unit/IGadgetUnit.h \
    $$PWD/core/unit/INoConstructUnit.h \
    $$PWD/core/unit/IOrderUnit.h  \
    $$PWD/core/unit/IRegisterGadgetUnit.h \
    $$PWD/core/unit/IRegisterMetaTypeUnit.h \
    $$PWD/core/unit/ISingletonUnit.h \
    $$PWD/core/unit/IStackObjectUnit.h \
    $$PWD/http/IHttpAnnomacro.h \
    $$PWD/http/IHttpAssert.h \
    $$PWD/http/IHttpControllerTaskCatagory.h \
    $$PWD/http/controller/IHttpControllerInterface.h \
    $$PWD/http/controller/IHttpPathFunctorValidatorInterface.h \
    $$PWD/http/controller/private/IHttpControllerBeanParameter.h \
    $$PWD/http/controller/private/IHttpControllerInfo.h \
    $$PWD/http/controller/private/IHttpControllerParameter.h \
    $$PWD/http/core/defaultTask/IHttpDefaultProfileTask.h \
    $$PWD/http/core/defaultTask/IHttpFileServiceTask.h \
    $$PWD/http/core/defaultTask/IHttpPrintTraceTask.h \
    $$PWD/http/core/defaultTask/IHttpUrlPathValidatorTask.h \
    $$PWD/http/invalid/IHttpBadRequestInvalid.h \
    $$PWD/http/invalid/IHttpInternalErrorInvalid.h \
    $$PWD/http/invalid/IHttpInvalidInterface.h \
    $$PWD/http/invalid/IHttpInvalidManage.h \
    $$PWD/http/invalid/IHttpInvalidUnit.h \
    $$PWD/http/invalid/IHttpInvalidWare.h \
    $$PWD/http/invalid/IHttpNotFoundInvalid.h \
    $$PWD/http/invalid/IHttpRequestTimeoutInvalid.h \
    $$PWD/http/invalid/IRegistInvalidUnit.h \
    $$PWD/http/net/impl/IResponseHeader.h \
    $$PWD/http/net/impl/IResponseRaw.h \
    $$PWD/http/nody/INody.h \
    $$PWD/http/nody/INodyManage.h \
    $$PWD/http/nody/INodyParser.h \
    $$PWD/http/nody/INodyRenderer.h \
    $$PWD/http/response/IStatusResponse.h \
#    $$PWD/http/server/multiThreadServer/IHttpServerRunnable.h \
    $$PWD/http/srver/IHttpServer.h \
    $$PWD/orm/IOrmAssert.h \
    $$PWD/orm/IOrmManage.h \
    $$PWD/orm/IOrmTaskCatagory.h \
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
    $$PWD/http/IInterceptInterface.h \
    $$PWD/http/biscuits/IHttpHeader.h \
    $$PWD/http/biscuits/IHttpMethod.h \
    $$PWD/http/biscuits/IHttpMime.h \
    $$PWD/http/biscuits/IHttpStatus.h \
    $$PWD/http/biscuits/IHttpVersion.h \
    $$PWD/http/controller/IHttpFolderMapping.h \
    $$PWD/http/controller/IHttpManage.h \
    $$PWD/http/controller/IHttpPathRegexpValidatorInterface.h \
    $$PWD/http/controller/IHttpResourceMapping.h \
    $$PWD/http/controller/IHttpRouteMapping.h \
    $$PWD/http/controller/private/IControllerInterfaceHelper.h \
    $$PWD/http/core/defaultTask/IControllerBaseTypeTask.h \
    $$PWD/http/core/defaultTask/INodyTemplateTask.h \
    $$PWD/http/core/test/IHttpTestInterface.h \
    $$PWD/http/core/test/IHttpTestManage.h \
    $$PWD/http/core/test/IHttpTestTask.h \
    $$PWD/http/jar/ICookieJar.h \
    $$PWD/http/jar/ICookiePart.h \
    $$PWD/http/jar/IHeaderJar.h \
    $$PWD/http/jar/IJarUnit.h \
    $$PWD/http/jar/IMultiPart.h \
    $$PWD/http/jar/IMultiPartJar.h \
    $$PWD/http/jar/ISessionJar.h \
#    $$PWD/http/middleware/IInterceptorWare.h \
#    $$PWD/http/middleware/IMiddleWare.h \
#    $$PWD/http/middleware/IMiddleWarePreProcessor.h \
#    $$PWD/http/middleware/IPostInterceptorInterface.h \
#    $$PWD/http/middleware/IPostProcessorInterface.h \
#    $$PWD/http/middleware/IPreInterceptorInterface.h \
#    $$PWD/http/middleware/IPreProcessorInterface.h \
#    $$PWD/http/middleware/IProcessorWare.h \
    $$PWD/http/net/IRequest.h \
    $$PWD/http/net/IResponse.h \
    $$PWD/http/net/impl/IReqRespRaw.h \
    $$PWD/http/net/impl/IRequestAssert.h \
    $$PWD/http/net/impl/IRequestImpl.h \
    $$PWD/http/net/impl/IResponseImpl.h \
    $$PWD/http/node/IFunctionNode.h \
    $$PWD/http/node/IMethodNode.h \
    $$PWD/http/node/IParamNode.h \
    $$PWD/http/node/IUrlActionNode.h \
    $$PWD/http/response/IByteArrayResponse.h \
    $$PWD/http/response/IFileResponse.h \
    $$PWD/http/response/IHtmlResponse.h \
    $$PWD/http/response/IInvalidResponse.h \
    $$PWD/http/response/IJsonResponse.h \
    $$PWD/http/response/IPlainTextResponse.h \
    $$PWD/http/response/IRedirectResponse.h \
    $$PWD/http/response/IRendererResponse.h \
    $$PWD/http/response/IResponseContent.h \
    $$PWD/http/response/IResponseInterface.h \
    $$PWD/http/response/IResponseManage.h \
    $$PWD/http/response/IResponsePreProcessor.h \
    $$PWD/http/response/IResponseTemplateRenderer.h \
    $$PWD/http/response/IResponseWare.h \
    $$PWD/http/response/response \
#    $$PWD/http/server/IServerInterface.h \
#    $$PWD/http/server/IServerWare.h \
#    $$PWD/http/server/multiThreadServer/ITcpSocket.h \
    $$PWD/http/controller/pp/IControlVariablePreProcessor.h \
    $$PWD/http/controller/pp/IControllerPreProcessor.h \
    $$PWD/http/controller/pp/IDeleteMappingPreProcessor.h \
    $$PWD/http/controller/pp/IGetMappingPreProcessor.h \
    $$PWD/http/controller/pp/IPatchMappingPreProcessor.h \
    $$PWD/http/controller/pp/IPostMappingPreProcessor.h \
    $$PWD/http/controller/pp/IPutMappingPreProcessor.h \
#    $$PWD/http/server/IHttpServer.h \
#    $$PWD/http/server/IHttpServerManage.h \
#    $$PWD/http/server/multiThreadServer/IMultiThreadServer.h \
#    $$PWD/http/server/quenedServer/IQueneServer.h \
    $$PWD/http/session/ISessionInterface.h \
    $$PWD/http/session/ISessionManager.h \
    $$PWD/http/session/ISessionWare.h

SOURCES += \
    $$PWD/core/application/IApplicationInterface.cpp \
    $$PWD/core/application/IAsioApplication.cpp \
    $$PWD/core/application/IQtApplication.cpp \
    $$PWD/core/base/ICodecUtil.cpp \
    $$PWD/core/base/IConvertUtil.cpp \
    $$PWD/core/base/IFileUtil.cpp \
    $$PWD/core/base/IHeaderUtil.cpp \
    $$PWD/core/base/IJsonUtil.cpp \
    $$PWD/core/base/IJsonUtil_tojson.cpp \
    $$PWD/core/base/IJsonUtil_tojson_impl.cpp \
    $$PWD/core/base/IMetaUtil.cpp \
    $$PWD/core/base/IPreProcessorUtil.cpp \
#    $$PWD/core/base/ISocketUtil.cpp \
    $$PWD/core/base/ITicTacUtil.cpp \
    $$PWD/core/base/IToeUtil.cpp \
    $$PWD/core/base/IXmlUtil.cpp \
    $$PWD/core/assert/IAssertInfo.cpp \
    $$PWD/core/assert/IAssertInterface.cpp \
    $$PWD/core/assert/IGlobalAssert.cpp \
    $$PWD/core/bean/IBeanTypeManage.cpp \
    $$PWD/core/config/IConfigManageInterface.cpp \
    $$PWD/core/config/IConfigTaskCatagory.cpp \
    $$PWD/core/config/IProfileManage.cpp \
    $$PWD/core/config/default/IContextJsonProfileTask.cpp \
    $$PWD/core/config/default/IContextSystemVariableTask.cpp \
    $$PWD/core/config/default/IContextTomlProfileTask.cpp \
    $$PWD/core/config/default/IContextYamlProfileTask.cpp \
    $$PWD/core/config/default/ILoadProfileFileUnit.cpp \
    $$PWD/core/task/ITaskCatagory.cpp \
    $$PWD/core/task/default/IBannerTask.cpp \
    $$PWD/core/task/default/IEndupTaskCatagory.cpp \
    $$PWD/core/task/default/IInitializationTaskCatagory.cpp \
    $$PWD/core/task/default/IStartupTaskCatagory.cpp \
    $$PWD/core/task/ITaskManage.cpp \
    $$PWD/core/task/ITaskWare.cpp \
    $$PWD/core/test/ITestCatagory.cpp \
    $$PWD/core/test/ITestTask.cpp \
    $$PWD/core/test/IUnitTestInterface.cpp \
    $$PWD/core/test/IUnitTestManage.cpp \
    $$PWD/core/test/IUnitTestTask.cpp \
    $$PWD/core/unit/IGadgetUnit.cpp \
    $$PWD/core/unit/IRegisterGadgetUnit.cpp \
    $$PWD/core/unit/IRegisterMetaTypeUnit.cpp \
    $$PWD/http/IHttpAssert.cpp \
    $$PWD/http/IHttpControllerTaskCatagory.cpp \
    $$PWD/http/controller/IHttpPathFunctorValidatorInterface.cpp \
    $$PWD/http/controller/IHttpPathRegexpValidatorInterface.cpp \
    $$PWD/http/controller/private/IHttpControllerBeanParameter.cpp \
    $$PWD/http/controller/private/IHttpControllerParameter.cpp \
    $$PWD/http/core/defaultTask/IHttpDefaultProfileTask.cpp \
    $$PWD/http/core/defaultTask/IHttpFileServiceTask.cpp \
    $$PWD/http/core/defaultTask/IHttpPrintTraceTask.cpp \
    $$PWD/http/core/defaultTask/IHttpUrlPathValidatorTask.cpp \
    $$PWD/http/invalid/IHttpBadRequestInvalid.cpp \
    $$PWD/http/invalid/IHttpInternalErrorInvalid.cpp \
    $$PWD/http/invalid/IHttpInvalidManage.cpp \
    $$PWD/http/invalid/IHttpInvalidUnit.cpp \
    $$PWD/http/invalid/IHttpInvalidWare.cpp \
    $$PWD/http/invalid/IHttpNotFoundInvalid.cpp \
    $$PWD/http/invalid/IHttpRequestTimeoutInvalid.cpp \
    $$PWD/http/net/impl/IResponseHeader.cpp \
    $$PWD/http/net/impl/IResponseRaw.cpp \
    $$PWD/http/nody/INody.cpp \
    $$PWD/http/nody/INodyManage.cpp \
    $$PWD/http/nody/INodyParser.cpp \
    $$PWD/http/nody/INodyRenderer.cpp \
    $$PWD/http/response/IStatusResponse.cpp \
#    $$PWD/http/server/multiThreadServer/IHttpServerRunnable.cpp \
    $$PWD/http/srver/IHttpServer.cpp \
    $$PWD/orm/IOrmAssert.cpp \
    $$PWD/orm/IOrmManage.cpp \
    $$PWD/orm/IOrmTaskCatagory.cpp \
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
    $$PWD/orm/tableview/IOrmTableWare.cpp \
    $$PWD/orm/tableview/IOrmViewInfo.cpp \
    $$PWD/orm/tableview/IOrmViewWare.cpp \
    $$PWD/http/IInterceptInterface.cpp \
    $$PWD/http/biscuits/IHttpMethod.cpp \
    $$PWD/http/biscuits/IHttpMime.cpp \
    $$PWD/http/biscuits/IHttpStatus.cpp \
    $$PWD/http/biscuits/IHttpVersion.cpp \
    $$PWD/http/controller/IHttpFolderMapping.cpp \
    $$PWD/http/controller/IHttpManage.cpp \
    $$PWD/http/controller/IHttpResourceMapping.cpp \
    $$PWD/http/controller/IHttpRouteMapping.cpp \
    $$PWD/http/controller/private/IControllerInterfaceHelper.cpp \
    $$PWD/http/core/defaultTask/IControllerBaseTypeTask.cpp \
    $$PWD/http/core/defaultTask/INodyTemplateTask.cpp \
    $$PWD/http/core/test/IHttpTestInterface.cpp \
    $$PWD/http/core/test/IHttpTestManage.cpp \
    $$PWD/http/core/test/IHttpTestTask.cpp \
    $$PWD/http/jar/ICookieJar.cpp \
    $$PWD/http/jar/ICookiePart.cpp \
    $$PWD/http/jar/IHeaderJar.cpp \
    $$PWD/http/jar/IJarUnit.cpp \
    $$PWD/http/jar/IMultiPart.cpp \
    $$PWD/http/jar/IMultiPartJar.cpp \
    $$PWD/http/jar/ISessionJar.cpp \
#    $$PWD/http/middleware/IInterceptorWare.cpp \
#    $$PWD/http/middleware/IMiddleWare.cpp \
#    $$PWD/http/middleware/IPostInterceptorInterface.cpp \
#    $$PWD/http/middleware/IPostProcessorInterface.cpp \
#    $$PWD/http/middleware/IPreInterceptorInterface.cpp \
#    $$PWD/http/middleware/IPreProcessorInterface.cpp \
#    $$PWD/http/middleware/IProcessorWare.cpp \
    $$PWD/http/net/IRequest.cpp \
    $$PWD/http/net/IResponse.cpp \
    $$PWD/http/net/impl/IReqRespRaw.cpp \
    $$PWD/http/net/impl/IRequestAssert.cpp \
    $$PWD/http/net/impl/IRequestImpl.cpp \
    $$PWD/http/net/impl/IResponseImpl.cpp \
    $$PWD/http/node/IFunctionNode.cpp \
    $$PWD/http/node/IMethodNode.cpp \
    $$PWD/http/node/IParamNode.cpp \
    $$PWD/http/response/IByteArrayResponse.cpp \
    $$PWD/http/response/IFileResponse.cpp \
    $$PWD/http/response/IHtmlResponse.cpp \
    $$PWD/http/response/IInvalidResponse.cpp \
    $$PWD/http/response/IJsonResponse.cpp \
    $$PWD/http/response/IPlainTextResponse.cpp \
    $$PWD/http/response/IRedirectResponse.cpp \
    $$PWD/http/response/IRendererResponse.cpp \
    $$PWD/http/response/IResponseContent.cpp \
    $$PWD/http/response/IResponseManage.cpp \
    $$PWD/http/response/IResponseTemplateRenderer.cpp \
    $$PWD/http/response/IResponseWare.cpp \
    $$PWD/http/controller/IControllerInterface.cpp \
#    $$PWD/http/server/multiThreadServer/ITcpSocket.cpp \
#    $$PWD/http/server/IHttpServer.cpp \
#    $$PWD/http/server/IHttpServerManage.cpp \
#    $$PWD/http/server/multiThreadServer/IMultiThreadServer.cpp \
#    $$PWD/http/server/quenedServer/IQueneServer.cpp \
    $$PWD/http/session/ISessionInterface.cpp \
    $$PWD/http/session/ISessionManager.cpp \
    $$PWD/http/session/ISessionWare.cpp

HEADERS += \
    $$PWD/IWebCore   \
    $$PWD/ICore/IApplication \
    $$PWD/ICore/IContext \
    $$PWD/ICore/IProfile \
    $$PWD/ICore/IUnitTestInterface \
#    $$PWD/IWeb/IHttpServer \
    $$PWD/IWeb/IHttpTestInterface   \
    $$PWD/IWeb/IHttpInvalidInterface \
    $$PWD/IWeb/HttpRequest \

DISTFILES +=

RESOURCES += \
    $$PWD/http/webresource.qrc




