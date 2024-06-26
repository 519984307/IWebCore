﻿#pragma once

#include "core/base/IHeaderUtil.h"
#include "core/base/IMetaUtil.h"
#include "core/result/IResult.h"
#include "core/unit/IRegisterMetaTypeUnit.h"
#include "http/jar/IJarUnit.h"
#include "http/jar/IMultiPart.h"

$PackageWebCoreBegin

class IMultiPartJar : public IJarUnit, IRegisterMetaTypeUnit<IMultiPartJar>
{
public:
    using IJarUnit::IJarUnit;

public:
    IMultiPartJar();
    IResult<IMultiPart> operator[](const QString& name) const;

    bool containRequestMulitPartName(const QString& name) const;
    QStringList getRequestMultiPartNames() const;

    IMultiPart getRequestMultiPart(const QString& name, bool& ok) const;
    IResult<IMultiPart> getRequestMultiPart(const QString &name) const;

    const QVector<IMultiPart>& getRequestMultiParts() const;
    QVector<IMultiPart> getRequestFileMultiParts() const;
};

$PackageWebCoreEnd
