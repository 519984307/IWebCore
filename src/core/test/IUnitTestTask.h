﻿#pragma once

#include "core/base/IHeaderUtil.h"
#include "core/test/ITestTaskBaseInterface.h"
#include "core/test/IUnitTestManage.h"

$PackageWebCoreBegin

class IUnitTestTask : public ITestTaskBaseInterface<IUnitTestTask, IUnitTestManage>
{
public:
    IUnitTestTask() = default;
};

$PackageWebCoreEnd
