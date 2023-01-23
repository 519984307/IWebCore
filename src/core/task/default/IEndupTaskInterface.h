﻿#pragma once

#include "base/IHeaderUtil.h"
#include "base/IMetaUtil.h"
#include "core/task/ITaskWare.h"
#include "core/task/ITaskManage.h"
#include "core/unit/IRegisterInstanceUnit.h"

$PackageWebCoreBegin

template<typename T, bool enabled=true>
class IEndupTaskInterface : public ITaskWare, public IRegisterInstanceUnit<T, enabled>
{
public:
    IEndupTaskInterface() = default;

public:
    virtual void task() = 0;

    virtual QString name() const override;
    virtual QStringList orders() const override;
    virtual QString catagory()  const final;
    virtual void registerToBase() final;
};

template<typename T, bool enabled>
QString IEndupTaskInterface<T, enabled>::name() const
{
    return IMetaUtil::getMetaClassName(T::staticMetaObject);
}

template<typename T, bool enabled>
QStringList IEndupTaskInterface<T, enabled>::orders() const
{
    return {};
}

template<typename T, bool enabled>
QString IEndupTaskInterface<T, enabled>::catagory() const
{
    return "EndUp";
}

template<typename T, bool enabled>
void IEndupTaskInterface<T, enabled>::registerToBase()
{
    ITaskManage::instance()->addTaskWare(T::instance());
}

$PackageWebCoreEnd