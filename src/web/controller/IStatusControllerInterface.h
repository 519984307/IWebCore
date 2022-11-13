﻿#pragma once

#include "base/IHeaderUtil.h"
#include "base/IMetaUtil.h"
#include "core/configuration/IConfigurationManage.h"
#include "core/task/IControllerTaskUnit.h"
#include "web/controller/IControllerManage.h"
#include "web/node/IStatusActionNode.h"

$PackageWebCoreBegin

struct IControllerInfo;

namespace IStatusControllerInterfaceProxy
{
    void registerController(void* handler, const QString& className,
                            const QMap<QString, QString>& classInfo, const QVector<QMetaMethod>& methods);
    void registerError();

    void unRegisterController(void* handler, const QString& className,
                              const QMap<QString, QString>& classInfo, const QVector<QMetaMethod>& methods);
    void unRegisterError();
}

template<typename T, bool enabled = true>
class IStatusControllerInterface : public IControllerTaskUnit<T, enabled>
{
public:
    IStatusControllerInterface() = default;
    virtual ~IStatusControllerInterface() = default;

    virtual void task() final;
    virtual void registerController() final;
    virtual void unRegisterController() final;
};

template<typename T, bool enabled>
void IStatusControllerInterface<T, enabled>::task()
{
    registerController();
}

template<typename T, bool enabled>
void IStatusControllerInterface<T, enabled>::registerController()
{
    if(this != T::instance()){
        IStatusControllerInterfaceProxy::registerError();
    }

    auto className = IMetaUtil::getMetaClassName (T::staticMetaObject);
    auto classInfo = IMetaUtil::getMetaClassInfoMap(T::staticMetaObject);
    auto classMethods = IMetaUtil::getMetaMethods(T::staticMetaObject);
    IStatusControllerInterfaceProxy::registerController(this, className, classInfo, classMethods);
}

template<typename T, bool enabled>
void IStatusControllerInterface<T, enabled>::unRegisterController()
{
    if(this != T::instance()){
        IStatusControllerInterfaceProxy::unRegisterError();
    }

    auto className = IMetaUtil::getMetaClassName (T::staticMetaObject);
    auto classInfo = IMetaUtil::getMetaClassInfoMap(T::staticMetaObject);
    auto classMethods = IMetaUtil::getMetaMethods(T::staticMetaObject);
    IStatusControllerInterfaceProxy::unRegisterController(this, className, classInfo, classMethods);
}

$PackageWebCoreEnd
