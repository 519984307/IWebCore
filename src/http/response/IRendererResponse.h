﻿#pragma once

#include "core/base/IHeaderUtil.h"
#include "IResponseInterface.h"
#include "IResponsePreProcessor.h"
#include "IRedirectResponse.h"

$PackageWebCoreBegin

class IRendererResponse : public IResponseInterface<IRendererResponse>
{
    $AsResponse(IRendererResponse)
public:
    using IResponseInterface::operator [];
    using IResponseInterface::IResponseInterface;

public:
    IRendererResponse() = default;
    IRendererResponse(const QString& path, QJsonObject value);
};

$PackageWebCoreEnd