﻿#pragma once

#include "core/base/IHeaderUtil.h"
#include "core/base/IMetaUtil.h"
#include "core/task/unit/ITaskWareUnit.h"
#include "core/task/ITaskManage.h"
#include "core/context/IContextPreProcessor.h"

$PackageWebCoreBegin

template<typename T, bool enabled = true>
class IContextTaskInterface : public ITaskWareUnit<T, enabled>
{
public:
    IContextTaskInterface() = default;

public:
    virtual QJsonValue getSystemConfig();
    virtual QJsonValue getApplicationConfig();

protected:
    virtual QString name() const final;
    virtual QString catagory() const final;
    virtual void task() final;
};

template<typename T, bool enabled>
QString IContextTaskInterface<T, enabled>::name() const
{
    return IMetaUtil::getMetaClassName(T::staticMetaObject);
}

template<typename T, bool enabled>
QString IContextTaskInterface<T, enabled>::catagory() const
{
    return "Context";
}

template<typename T, bool enabled>
QJsonValue IContextTaskInterface<T, enabled>::getSystemConfig()
{
    return {};
}

template<typename T, bool enabled>
QJsonValue IContextTaskInterface<T, enabled>::getApplicationConfig()
{
    return {};
}


template<typename T, bool enabled>
void IContextTaskInterface<T, enabled>::task()
{
    auto systemConfig = getSystemConfig();
    if(!systemConfig.isNull() && !systemConfig.isUndefined()){
        IContextManage::addSystemConfig(systemConfig);
    }

    auto applicationConfig = getApplicationConfig();
    if(!applicationConfig.isNull() && !applicationConfig.isUndefined()){
        IContextManage::addApplicationConfig(applicationConfig);
    }
}


$PackageWebCoreEnd