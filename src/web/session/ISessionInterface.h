﻿#pragma once

#include "base/IHeaderUtil.h"
#include "web/session/ISessionTaskUnit.h"
#include "web/session/ISessionWare.h"
//#include "web/session/ISessionManager.h"

$PackageWebCoreBegin

namespace ISessionInterfaceProxy
{
    void registerSession(ISessionWare*);
}

template<typename T, bool enabled=true>
class ISessionInterface : public ISessionTaskUnit<T, enabled>, public ISessionWare
{
public:
    ISessionInterface() = default;
    virtual ~ISessionInterface() = default;

    virtual void task() final;
    virtual void registerSession() final;
};

template<typename T, bool enabled>
void ISessionInterface<T, enabled>::task ()
{
    static std::once_flag flag;
    std::call_once(flag, [&](){
        registerSession ();
    });
}

template<typename T, bool enabled>
void ISessionInterface<T, enabled>::registerSession ()
{
    ISessionInterfaceProxy::registerSession (T::instance());
}


$PackageWebCoreEnd
