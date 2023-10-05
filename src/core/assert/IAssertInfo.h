﻿#pragma once

#include "core/base/IHeaderUtil.h"

$PackageWebCoreBegin

struct IAssertInfo
{
public:
    IAssertInfo() = default;

public:
    operator QString() const;

public:
    int line{INT_MIN};
    QString file;
    QString reason;
    QString className;
    QString function;
    QString returnType;
    QString paramterType;
    QString parameterName;
};

$PackageWebCoreEnd

#ifdef $UseInLineMode
    #include "IAssertInfo.cpp"
#endif
