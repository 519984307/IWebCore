﻿#include "IMultiPartJar.h"
#include "web/IWebAssert.h"
#include "web/net/impl/IReqRespRaw.h"

$PackageWebCoreBegin

$UseAssert(IWebAssert)

IMultiPartJar::IMultiPartJar() : IJarUnit(nullptr)
{
    $Ast->fatal("IMultiPartJar_CREATE_ERROR");
}

// NOTE: 这里没有正证伪，需要用户手动判断， 所以这里不建议使用
const IMultiPart& IMultiPartJar::operator[](const QString &name) const
{
    bool ok;
    return getRequestMultiPart (name, ok);
}

bool IMultiPartJar::containRequestMulitPartName(const QString &name) const
{
    const auto& jar = m_raw->m_requestMultiParts;
    for(const auto& part : jar){
        if(part.name == name){
            return true;
        }
    }
    return false;
}

QStringList IMultiPartJar::getRequestMultiPartNames() const
{
    QStringList ret;
    const auto& jar = m_raw->m_requestMultiParts;
    for(const auto& part : jar){
        ret.append (part.name);
    }
    return ret;
}

// 这里的操作是，添加一个invalid multipart;
IMultiPart IMultiPartJar::getRequestMultiPart(const QString &name, bool& ok) const
{
    const auto& jar = m_raw->m_requestMultiParts;
    for(const auto& part : jar){
        if(part.name == name){
            ok = true;
            return part;
        }
    }

    ok = false;
    return IMultiPart::InvalidMulitPart;
}

IResult<IMultiPart> IMultiPartJar::getRequestMultiPart(const QString &name) const
{
    bool ok;
    auto value = getRequestMultiPart(name, ok);
    return {value, ok};
}

const QVector<IMultiPart> &IMultiPartJar::getRequestMultiParts() const
{
    return m_raw->m_requestMultiParts;
}

QVector<IMultiPart> IMultiPartJar::getRequestFileMultiParts() const
{
    QVector<IMultiPart> ret;
    const auto& jar = m_raw->m_requestMultiParts;
    for(const auto& part : jar){
        if(!part.fileName.isEmpty ()){
            ret.append (part);
        }
    }
    return ret;
}

$PackageWebCoreEnd
