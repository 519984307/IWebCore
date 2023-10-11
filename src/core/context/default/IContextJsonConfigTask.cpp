﻿#include "IContextJsonConfigTask.h"
#include "core/context/IContextManage.h"
#include "core/base/IFileUtil.h"
#include "core/base/IJsonUtil.h"
#include "core/assert/IGlobalAssert.h"

$PackageWebCoreBegin

$UseGlobalAssert()

QJsonValue IContextJsonConfigTask::getApplicationConfig()
{
    auto paths = getJsonPaths();
    for(auto path : paths){
        auto obj = parseJsonFile(path);
        IContextManage::addConfig(obj, IContextManage::ApplicationContextGroup);
    }

    return {};
}

QStringList IContextJsonConfigTask::getJsonPaths(){
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

QJsonObject IContextJsonConfigTask::parseJsonFile(const QString &path)
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