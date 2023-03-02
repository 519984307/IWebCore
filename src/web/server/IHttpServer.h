﻿#pragma once

#include "core/base/IConstantUtil.h"
#include "core/context/IContextPreProcessor.h"
#include "core/context/IContextWirePreProcessor.h"
#include "core/context/IContextImport.h"
#include "web/biscuits/IHttpMethod.h"
#include "web/net/IRequest.h"
#include "web/net/IResponse.h"

$PackageWebCoreBegin

class IHttpServer : public QTcpServer
{
    Q_GADGET
    $UseInstance(IHttpServer)
    $UseContext(IHttpServer)

public:
    using ProcessFunctor = std::function<void(const IRequest& req, IResponse& resp)>;

public:
    IHttpServer();
    bool listen(const QHostAddress &address = QHostAddress::Null, quint16 port = 0);
    void setHost(const QString &host);
    void setPort(int port);

public:
    void setDefaultStaticDir(const QString& dir);
    void serveStatic(const QString& dir, const QString& prefix="/");

    void get(const QString& path, ProcessFunctor functor);
    void post(const QString& path, ProcessFunctor functor);
    void put(const QString& path, ProcessFunctor functor);
    void deletes(const QString& path, ProcessFunctor functor);
    void patch(const QString& path, ProcessFunctor functor);
    void serveDynamic(IHttpMethod method, const QString& path, ProcessFunctor);

private:
    virtual void incomingConnection(qintptr handle) final;

private:
    $OptionWireDeclare(QString, host, server.host)
    QString host = "127.0.0.1";

//    $OptionWireDeclare(int, port, server.port)
//    int port = 8088;

    static constexpr char path[] ="abc";
    IContextImport<ushort, path> port;
};

$PackageWebCoreEnd
