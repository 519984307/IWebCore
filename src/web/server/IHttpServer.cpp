﻿#include "IHttpServer.h"

$PackageWebCoreBegin

IHttpServer::IHttpServer() :  QTcpServer()
{
    $ConstructConfig()
}

bool IHttpServer::listen()
{
    QHostAddress address = host == "any" ? QHostAddress::Any : QHostAddress(host);
    auto result = this->QTcpServer::listen(address, port);
    if(result){
        QString info = QString("server started at %1:%2").arg(address.toString()).arg(port);
        qDebug().noquote() << info;
    }else{
        QString info = QString("fail to start server at %1:%2").arg(address.toString()).arg(port);
        qDebug().noquote() << info;
    }

    return result;
}

void IHttpServer::setHost(const QString &host)
{
    this->host = host;
}

void IHttpServer::setPort(int port)
{
    this->port = port;
}

void IHttpServer::staticServe(const QString &path, const QString &prefix)
{

}

void IHttpServer::staticServe(std::function<bool (const QString &)> judge)
{

}

void IHttpServer::get(const QString &path, IHttpServer::ProcessFunctor functor)
{
    serve(IHttpMethod::GET, path, functor);
}

void IHttpServer::post(const QString &path, IHttpServer::ProcessFunctor functor)
{
    serve(IHttpMethod::GET, path, functor);
}

void IHttpServer::put(const QString &path, IHttpServer::ProcessFunctor functor)
{
    serve(IHttpMethod::GET, path, functor);
}

void IHttpServer::deletes(const QString &path, IHttpServer::ProcessFunctor functor)
{
    serve(IHttpMethod::GET, path, functor);
}

void IHttpServer::patch(const QString &path, IHttpServer::ProcessFunctor functor)
{
    serve(IHttpMethod::GET, path, functor);
}

void IHttpServer::serve(IHttpMethod method, const QString &path, IHttpServer::ProcessFunctor functor)
{
    Q_UNUSED(method)
    Q_UNUSED(path)
    Q_UNUSED(functor)
    // TODO:
}

void IHttpServer::incomingConnection(qintptr handle)
{
    m_serverManage.addSocket(handle);
}

$PackageWebCoreEnd
