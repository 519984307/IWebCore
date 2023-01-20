﻿#pragma once

#include "base/IHeaderUtil.h"
$PackageWebCoreBegin

class ITaskWare
{
    $AsWare
public:
    ITaskWare() = default;

public:
    virtual QString taskFinishTip();

    virtual QString name() = 0;
    virtual QStringList orders() = 0;
    virtual void task() = 0;
    virtual QString catagory() = 0;

public:
    void printTips();
};

$PackageWebCoreEnd
