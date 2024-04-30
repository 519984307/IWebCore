﻿#include "IResponse.h"

#include "core/base/IConstantUtil.h"
#include "core/assert/IGlobalAssert.h"
#include "http/biscuits/IHttpHeader.h"
#include "http/IHttpAssert.h"
#include "http/net/IRequest.h"
#include "http/net/impl/IReqRespRaw.h"
#include "http/net/impl/IResponseImpl.h"
#include "http/jar/IHeaderJar.h"
#include "http/response/IResponseWare.h"

$PackageWebCoreBegin

$UseAssert(IHttpAssert)

$UseGlobalAssert()

IResponse::IResponse()
{
    $Ast->fatal("IRequest_IResponse_CREATE_ERROR");
}

IResponse::IResponse(IRequest *request)
{
    raw = request->getRaw();
//    raw->m_responseWare = this;
    impl = new IResponseImpl(raw);
}

IResponse::~IResponse()
{
    delete impl;
}

IResponse::IResponse(const IResponse &)
{
    $Ast->fatal("IRequest_IResponse_COPY_MOVE_ERROR");
}

IResponse &IResponse::operator=(const IResponse &)
{
    $Ast->fatal("IRequest_IResponse_COPY_MOVE_ERROR");
    return *this;
}

IResponse::IResponse(IResponse &&)
{
    $Ast->fatal("IRequest_IResponse_COPY_MOVE_ERROR");
}

IResponse &IResponse::operator=(IResponse &&)
{
    $Ast->fatal("IRequest_IResponse_COPY_MOVE_ERROR");
    return *this;
}

IResponse &IResponse::operator<<(const QString &content)
{
    raw->m_responseRaw->content.append(content);
    return *this;
}

IResponse &IResponse::operator<<(const QByteArray &content)
{
    raw->m_responseRaw->content.append(content);
    return *this;
}

IResponse &IResponse::operator<<(const char *content)
{
    raw->m_responseRaw->content.append(QByteArray(content));
    return *this;
}

IResponse &IResponse::operator<<(IResponseWare *response)
{
    setContent(response);
    return *this;
}

IResponse &IResponse::operator<<(IResponseWare &response)
{
    setContent(&response);
    return *this;
}

QString IResponse::operator[](const QString &header) const
{
    auto it=raw->m_responseRaw->headers.begin();
    for(; it!= raw->m_responseRaw->headers.end(); it++){
        if(it->first == header){
            return it->second;
        }
    }

    return "";
}

QString &IResponse::operator[](const QString &header)
{
    auto it=raw->m_responseRaw->headers.begin();
    for(; it!= raw->m_responseRaw->headers.end(); it++){
        if(it->first == header){
            return it->second;
        }
    }
    QPair<QString, QByteArray> pair{header, ""};
    raw->m_responseRaw->headers.append(pair);
    return raw->m_responseRaw->headers.last().second;
}

IRequest *IResponse::request() const
{
    return raw->m_request;
}

IReqRespRaw *IResponse::getRaw() const
{
    return raw;
}

IResponse &IResponse::setHeader(const QString &key, const QString &value)
{
    if(key.isEmpty() || value.isEmpty()){
        $Ast->warn("iresponse_setHeader_with_empty_value_or_key");
    }

    raw->m_headerJar->setResponseHeader(key, value);
    return *this;
}

IResponse &IResponse::setStatus(IHttpStatusCode statusCode)
{
    raw->m_responseRaw->status = statusCode;
    return *this;
}

// NOTE: 这里是强转， 也就是说，任何一个数据都可以被设置进来。
IResponse &IResponse::setStatus(int statusCode)
{
    raw->m_responseRaw->status = IHttpStatus::toStatus(statusCode);
    return *this;
}

IResponse &IResponse::setMime(IHttpMime mime)
{
    raw->m_responseRaw->mime = IHttpMimeUtil::toString(mime);
    return *this;
}

IResponse &IResponse::setMime(const QString mime)
{
    raw->m_responseRaw->mime = mime;
    return *this;
}

IResponse &IResponse::addCookie(const ICookiePart &cookiePart)
{
    raw->m_responseRaw->cookies.append(cookiePart);
    return *this;
}

IResponse &IResponse::appendContent(const QString &content)
{
    raw->m_responseRaw->content.append(content);
    return *this;
}

IResponse &IResponse::appendContent(const QByteArray &content)
{
    raw->m_responseRaw->content.append(content);
    return *this;
}

IResponse &IResponse::appendContent(const char *content)
{
    raw->m_responseRaw->content.append(content);
    return *this;
}

IResponse &IResponse::setContent(const QString &content)
{
    raw->m_responseRaw->content.setContent(content);
    return *this;
}

IResponse &IResponse::setContent(const QByteArray &content)
{
    raw->m_responseRaw->content.setContent(content);
    return *this;
}

IResponse &IResponse::setContent(QByteArray &&content)
{
    raw->m_responseRaw->content.setContent(std::forward<QByteArray&&>(content));
    return *this;
}

IResponse &IResponse::setContent(const char *content)
{
    raw->m_responseRaw->content.setContent(content);
    return *this;
}

IResponse& IResponse::setContent(IResponseWare *response)
{
    std::swap(raw->m_responseRaw->content, response->getContent());

    if(raw->m_responseRaw->content.type == IResponseContent::Invalid){
        setContent(response->getContent().contentInvalid);
        raw->m_responseRaw->mime = IHttpMimeUtil::toString(IHttpMime::TEXT_PLAIN_UTF8);
    }

    if(response->status() != IHttpStatusCode::UNKNOWN){
        raw->m_responseRaw->status = response->status();
    }

    if(response->mime() != IHttpMimeUtil::MIME_UNKNOWN_STRING){
        raw->m_responseRaw->mime = response->mime();
    }

    auto& headers = response->headers();
    auto keys = headers.keys();
    for(auto key : keys){
        if(!raw->m_headerJar->containResponseHeaderKey(key)){
            raw->m_headerJar->addResponseHeader(key, headers[key]);
            // TODO: 这里可能有冲突，需要特殊处理掉
        }
    }

    // TODO: check ok;
    bool ok;
    if((!raw->m_headerJar->containResponseHeaderKey(IHttpHeader::ContentType)
            || raw->m_headerJar->getResponseHeaderValue(IHttpHeader::ContentType, ok) == "UNKNOWN")
            && raw->m_responseRaw->mime != IHttpMimeUtil::MIME_UNKNOWN_STRING)
    {
        raw->m_headerJar->setResponseHeader(IHttpHeader::ContentType, raw->m_responseRaw->mime);
    }
    return *this;
}

IResponse &IResponse::setContent(IResponseWare &response)
{
    return setContent(&response);
}

IResponse &IResponse::setContent(IHttpInvalidUnit unit)
{
    raw->setInvalid(unit);
    return *this;
}

IHttpVersion IResponse::version() const
{
    return raw->m_httpVersion;
}

QString IResponse::mime() const
{
    return raw->m_responseRaw->mime;
}

IHttpStatusCode IResponse::status() const
{
    return raw->m_responseRaw->status;
}

const QList<QPair<QString, QString>>& IResponse::headers() const
{
    return raw->m_responseRaw->headers;
}

const QMap<QString, QVariant> &IResponse::attributes() const
{
    return raw->m_attribute;
}

bool IResponse::hasAttribute(const QString &name) const
{
    return raw->m_attribute.contains(name);
}

void IResponse::setAttribute(const QString &name, const QVariant &value)
{
    raw->m_attribute[name] = value;
}

QVariant IResponse::getAttribute(const QString &name, const QVariant &defaultValue) const
{
    if(raw->m_attribute.contains(name)){
        return raw->m_attribute[name];
    }
    return defaultValue;
}

bool IResponse::respond()
{
    return impl->respond();
}

bool IResponse::valid() const
{
    return impl->raw->valid();
}

//void IResponse::setInvalidIf(bool condition, IHttpInvalidUnit ware) const
//{
//    if(condition){
//        raw->setInvalid(ware);
//    }
//}

//void IResponse::setInvalid(IHttpInvalidUnit ware) const
//{
//    raw->setInvalid(ware);
//}

$PackageWebCoreEnd
