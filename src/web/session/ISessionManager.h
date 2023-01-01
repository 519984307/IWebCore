﻿#pragma once

#include "base/IHeaderUtil.h"

$PackageWebCoreBegin

class ISessionWare;

class ISessionManager : public QObject
{
    Q_OBJECT
    $UseInstance (ISessionManager)
private:
    ISessionManager() = default;

public:
    bool isSessionValid();
    void registerSessionWare(ISessionWare*);
    ISessionWare* getSessionInterface();

protected:
    virtual void timerEvent(QTimerEvent *event) final;

private:
    int m_timerId{};
    ISessionWare* m_sessionWare{};
};

$PackageWebCoreEnd
