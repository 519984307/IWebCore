﻿#pragma once

#include "core/base/IHeaderUtil.h"
#include "core/base/IMetaUtil.h"
#include "core/unit/IRegisterMetaTypeUnit.h"
#include "web/biscuits/IHttpStatus.h"
#include "web/biscuits/IHttpMime.h"
#include "web/response/IResponseManage.h"
#include "web/response/IResponseWare.h"
#include "web/response/IResponseWareRaw.h"
#include "web/core/unit/IRegisterResponseTypeUnit.h"

$PackageWebCoreBegin

struct IResponseWareRaw;
class IRedirectResponse;

template<typename T>
class IResponseInterface : public IResponseWare, IRegisterMetaTypeUnit<T>, IRegisterResponseTypeUnit<T>
{
public:
    using IResponseWare::operator[];

public:
    IResponseInterface();
    IResponseInterface(IRedirectResponse&& response);
    IResponseInterface(const IResponseInterface&);
    IResponseInterface(IResponseInterface &&);
    IResponseInterface(IResponseWare*); // special // only for create
    IResponseInterface& operator=(const IResponseInterface&);
    IResponseInterface& operator=(IResponseInterface&&);

    virtual ~IResponseInterface() = default;

public:
    virtual QSharedPointer<IResponseWare> create(IResponseWare*) override;
    virtual QSharedPointer<IResponseWare> create(QString val) final;
};

template<typename T>
IResponseInterface<T>::IResponseInterface()
{
    qDebug() << "construct";
}

template<typename T>
IResponseInterface<T>::IResponseInterface(IRedirectResponse &&response)
{
    redirectTo(std::forward<IRedirectResponse>(response));
}

template<typename T>
IResponseInterface<T>::IResponseInterface(const IResponseInterface &rhs) : IResponseWare(rhs)
{
    qDebug() << "copy construct";
}

template<typename T>
IResponseInterface<T>::IResponseInterface(IResponseInterface &&rhs) : IResponseWare(std::forward<IResponseInterface>(rhs))
{
    qDebug() << "move construct";
}

template<typename T>
IResponseInterface<T>::IResponseInterface(IResponseWare *ware)
{
    qDebug() << "create here";
    std::swap(this->m_raw, ware->m_raw);
}

template<typename T>
IResponseInterface<T> &IResponseInterface<T>::operator=(const IResponseInterface&rhs)
{
    qDebug() << "assign const";
    IResponseWare::operator =(rhs);
    return *this;
}

template<typename T>
IResponseInterface<T> &IResponseInterface<T>::operator=(IResponseInterface &&rhs)
{
    qDebug() << "assign move";
    IResponseWare::operator =(std::forward<IResponseInterface>(rhs));
    return *this;
}

template<typename T>
QSharedPointer<IResponseWare> IResponseInterface<T>::create(IResponseWare *ware)
{
    return QSharedPointer<T>::create(ware);
}

template<typename T>
QSharedPointer<IResponseWare> IResponseInterface<T>::create(QString val)
{
    return QSharedPointer<T>::create(val.mid(getPrefixMatcher().length())); // TODO: 倒也不必每次调用， 这里之后静态初始化这个值。
}

$PackageWebCoreEnd
