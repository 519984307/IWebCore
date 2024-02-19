﻿#include "IContextJsonProfileTask.h"
#include "core/assert/IGlobalAssert.h"
#include "core/base/IFileUtil.h"
#include "core/base/IJsonUtil.h"
#include "core/config/IContextManage.h"
#include "core/config/IProfileManage.h"

$PackageWebCoreBegin

$UseGlobalAssert()

QJsonValue IContextJsonProfileTask::config()
{
    auto paths = getJsonPaths();
    for(auto path : paths){
        auto obj = parseJsonFile(path);
        IProfileManage::instance()->addConfig(obj);
    }

    return {};
}

QStringList IContextJsonProfileTask::getJsonPaths() const
{
    QStringList ret;
    QDir dir(":/");
    auto entries = dir.entryInfoList({"*.json"});
    for(auto fileInfo : entries){
        if(!fileInfo.isDir() && fileInfo.filePath().endsWith("config.json")){
            ret.append(fileInfo.filePath());
        }
    }
    return ret;
}

QJsonObject IContextJsonProfileTask::parseJsonFile(const QString &path) const
{
    QJsonObject obj;

    bool convertOk = true;
    QString content = IFileUtil::readFileAsString(path);
    obj = IJsonUtil::toJsonObject(content, &convertOk);
    if(!convertOk){
        IAssertInfo info;
        info.reason = path;
        $GlobalAssert->fatal(IGlobalAssert::ConfigurationResolveJsonError, info);
    }
    return obj;
}

$PackageWebCoreEnd