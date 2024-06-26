﻿#pragma once

#include "core/base/IHeaderUtil.h"
#include "http/server/IServerInterface.h"

$PackageWebCoreBegin

class IMultiThreadServer : public IServerInterface<IMultiThreadServer>
{
public:
    IMultiThreadServer() = default;

    virtual void addSocket(qintptr handle) final;
    virtual void addSocket(QTcpSocket* socket) final;

private:
    QThreadPool m_pool;
};

$PackageWebCoreEnd
