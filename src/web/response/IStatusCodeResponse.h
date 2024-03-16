﻿#pragma once

#include <QtCore>
#include "IResponseInterface.h"
#include "IResponsePreProcessor.h"
#include "web/biscuits/IHttpStatus.h"

$PackageWebCoreBegin

class IStatusCodeResponse : public IResponseInterface<IStatusCodeResponse>
{
    $AsResponse(IStatusCodeResponse)
public:
    using IResponseInterface::operator[];

public:
    IStatusCodeResponse();
    IStatusCodeResponse(int code);
    IStatusCodeResponse(IHttpStatus status, const QString& errorMsg);

    virtual void setInstanceArg(QString &&) final;
    virtual bool canConvertFromString() final;
    virtual bool matchConvertString(const QString &) final;

    virtual QSharedPointer<IResponseWare> createInstance() final;
    static QSharedPointer<IResponseWare> createStatusCodeInstance();

private:
    static const QString m_matcherPrefix;
};

$PackageWebCoreEnd
