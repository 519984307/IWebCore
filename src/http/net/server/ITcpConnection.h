﻿#pragma once

#include "core/base/IHeaderUtil.h"
#include "http/net/server/ITcpConnectionData.h"


$PackageWebCoreBegin

class ITcpResolverInterface;

class ITcpConnection
{
public:
    ITcpConnection(asio::ip::tcp::socket socket);
    virtual ~ITcpConnection();

public:
    void doRead();
    void doWrite();
    void doDestroy();
    void doReuse();

public:
    ITcpConnectionData m_data;

private:
    asio::ip::tcp::socket m_socket;
    ITcpResolverInterface* m_resolver{};

public:
    friend class ITcpResolverInterface;
};

$PackageWebCoreEnd
