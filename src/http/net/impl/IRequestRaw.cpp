﻿#include "IRequestRaw.h"
#include "core/base/IHeaderUtil.h"
#include "core/base/IConstantUtil.h"
#include "core/base/IToeUtil.h"
#include "core/base/IJsonUtil.h"
#include "core/base/IXmlUtil.h"
#include "http/IHttpAssert.h"
#include "http/invalid/IHttpBadRequestInvalid.h"
#include "http/jar/ICookieJar.h"
#include "http/jar/IHeaderJar.h"
#include "http/jar/ISessionJar.h"
#include "http/jar/IMultiPartJar.h"
#include "http/net/impl/IResponseRaw.h"
#include "http/session/ISessionManager.h"

$PackageWebCoreBegin

$UseAssert(IHttpAssert)

IRequestRaw::IRequestRaw()
{
    qFatal(IConstantUtil::UnVisibleMethod);
}

IRequestRaw::IRequestRaw(IRequest *request)
{
    m_request = request;
    m_headerJar = new IHeaderJar(this);
    m_cookieJar = new ICookieJar(this);
    m_multiPartJar = new IMultiPartJar(this);
    m_responseRaw = new IResponseRaw;

    if(ISessionManager::instance()->getSessionWare() != nullptr){
        m_sessionJar = new ISessionJar(this);
    }
}

IRequestRaw::~IRequestRaw()
{
    delete m_headerJar;
    delete m_cookieJar;
    delete m_multiPartJar;
    delete m_sessionJar;
    delete m_responseRaw;
}

bool IRequestRaw::valid() const
{
    return m_responseRaw->valid();
}

void IRequestRaw::setInvalid(IHttpInvalidUnit ware)
{
    m_responseRaw->setMime(IHttpMimeUtil::toString(IHttpMime::TEXT_PLAIN_UTF8));
    m_responseRaw->setContent(ware);
}

// TODO: 这里需要查看一下，感觉返回数据过于早了，应该统一处理的。
QJsonValue IRequestRaw::getRequestJson(bool& ok)
{
    if(!isJsonInited){
        m_requestJson = IJsonUtil::toJsonValue(m_requestBody, ok);
        if(!ok){
            setInvalid(IHttpBadRequestInvalid("convert body to json failed"));
            return {}; // TODO: check here;
        }
        isJsonInited = true;
    }
    ok = true;
    return m_requestJson;
}

IResult<QJsonValue> IRequestRaw::getRequestJson()
{
    bool ok;
    auto value = getRequestJson(ok);
    return {value, ok};
}

$PackageWebCoreEnd
