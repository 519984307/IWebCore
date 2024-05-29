﻿#include "IHttpInvalidManage.h"

$PackageWebCoreBegin

void IHttpInvalidManage::addWare(IWebCore::IHttpInvalidWare *ware)
{
    m_wares[ware->tag] = ware;
}

IHttpInvalidWare *IHttpInvalidManage::getWare(const QString &name)
{
    if(!m_wares.contains(name)){
        return nullptr;
    }
    return m_wares[name];
}

$PackageWebCoreEnd
