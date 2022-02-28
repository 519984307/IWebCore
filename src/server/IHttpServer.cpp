﻿#include "IHttpServer.h"
#include "process/IHttpSocketManage.h"

$PackageWebCoreBegin

IHttpServer::IHttpServer() : IServerInterface(), QTcpServer()
{
    $ConstructConfig()
}

bool IHttpServer::listen()
{
    QHostAddress address = host == "any" ? QHostAddress::Any : QHostAddress(host);
    auto result = QTcpServer::listen(address, port);
    if(result){
        qDebug().noquote() << QString("server started at %1:%2").arg(address.toString()).arg(port) << endl;
    }else{
        qDebug().noquote() << QString("fail to start server at %1:%2").arg(address.toString()).arg(port) << endl;
    }

    // TODO: 将来在这里可以设置 fd 的各种属性.
    // auto fd = this->socketDescriptor();

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

// TODO: 为了解决 C10K 问题，有一个简便的权宜之计, 就是在这里获取到 handle 之后，将 handle 放置在
// 自定义的 事件循环里面，在 Linux 下面是 epoll, 在windows 下面是 IOCP.
void IHttpServer::incomingConnection(qintptr handle)
{
    IHttpSocketManage::addSocket(handle);
}

$PackageWebCoreEnd
