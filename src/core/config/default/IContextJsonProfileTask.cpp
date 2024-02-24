﻿#include "IContextJsonProfileTask.h"
#include "core/assert/IGlobalAssert.h"
#include "core/base/IFileUtil.h"
#include "core/base/IJsonUtil.h"
#include "core/config/IProfileManage.h"
#include "core/config/IContextImport.h"

$PackageWebCoreBegin

$UseGlobalAssert()

QJsonValue IContextJsonProfileTask::config()
{
    $ContextBool enableConfigFiles{"config.enableConfigFiles", false};
    if(!enableConfigFiles){
        return {};
    }

    auto paths = getJsonPaths();
    for(auto path : paths){
        auto obj = parseJsonFile(path);
        IProfileManage::instance()->addConfig(obj);
    }

    return {};
}

double IContextJsonProfileTask::order() const
{
    return 99.0;
}

QStringList IContextJsonProfileTask::getJsonPaths() const
{
    $Context<QJsonObject> paths{"config.configFilePaths"};
    if(!paths.isFound()){
        return {};
    }

    QStringList keys = paths.value().keys();
    qDebug() << keys << "keys";


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
    bool ok;
    QString content = IFileUtil::readFileAsString(path, ok);
    if(!ok){
        $GlobalAssert->fatal("ConfigurationResolveJsonError");
        return obj;
    }

    obj = IJsonUtil::toJsonObject(content, ok);
    if(!ok){
        IAssertInfo info;
        info.reason = path;
        $GlobalAssert->fatal("ConfigurationResolveJsonError", info);
    }
    return obj;
}

$PackageWebCoreEnd
