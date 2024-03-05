﻿#include "IControllerFileNode.h"
#include "core/base/IFileUtil.h"
#include "web/IWebAssert.h"

$PackageWebCoreBegin

$UseAssert(IWebAssert)

namespace IControllerFileNodeHelper
{
    void mountFilesToResourceMapping(QHash<QString, QString>& hash, const QString& path, const QString& prefix);
    void mountFirstPageToServer(QHash<QString, QString>& hash, const QString& path, const QString& prefix);
    bool mountFilePageToServer(QHash<QString, QString>& hash, const QString& filePath, const QString& url);
}

QString IControllerFileNode::getFilePath(const QString &url) const
{
    if(m_resourceMappingEnabled && m_resourceFileMappings.contains(url)){
        return m_resourceFileMappings[url];
    }
    return {};
}

void IControllerFileNode::mountMapping(const QString &dir, const QString &prefix)
{
    m_resourceMap[dir] = prefix;
    this->m_resourceMappingEnabled = true;
    IControllerFileNodeHelper::mountFilesToResourceMapping(m_resourceFileMappings, dir, prefix);
}

void IControllerFileNode::travelPrint(int space) const
{
    if(m_resourceMappingEnabled){
        qDebug() << "Mapping Directory";
        auto keys = m_resourceMap.keys();
        for(const auto& key : keys){
            qDebug().noquote()<< QString().fill(' ', 2) << key << "to" << m_resourceMap[key];
        }
    }
    
    qDebug() << endl;
}

void IControllerFileNodeHelper::mountFilesToResourceMapping(QHash<QString, QString>& hash, const QString &path, const QString &prefix)
{
    QDir dir(path);
    if(!dir.exists() || dir.isEmpty()){
        return;
    }

    mountFirstPageToServer(hash, path, prefix);

    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    auto entries = dir.entryInfoList();
    for(const auto& entry : entries){
        if(entry.isDir()){
            auto newPrefix = IFileUtil::joinPath(prefix, entry.fileName());
            mountFilesToResourceMapping(hash, entry.absoluteFilePath(), newPrefix);
            continue;
        }

        QString url = IFileUtil::joinPath(prefix, entry.fileName());
        while(url.contains("//")){
            url.replace("//", "/");
        }

        auto filePath = entry.absoluteFilePath();
        mountFilePageToServer(hash, filePath, url);
    }
}

void IControllerFileNodeHelper::mountFirstPageToServer(QHash<QString, QString>& hash, const QString& path, const QString& prefix)
{
    static const QStringList names = {
        "index.html", "index.htm", "default.html", "default.html", "home.html", "home.htm"
    };

    for(const auto& name : names){
        auto pagePath = IFileUtil::joinPath(path, name);
        if(mountFilePageToServer(hash, pagePath, prefix)){
            return;
        }
    }
}

bool IControllerFileNodeHelper::mountFilePageToServer(QHash<QString, QString>& hash, const QString& filePath, const QString& url)
{
    bool alreadyExist = hash.contains(url);
    if(QFileInfo(filePath).exists()){
        if(!alreadyExist){
            hash[url] = filePath;
            return true;
        }

        IAssertInfo info;
        info.reason = QString("url: ").append(url).append(" path1: ").append(filePath).append(" path2: ").append(hash[url]);
        $Ast->fatal("register_the_same_url", info);
    }
    return false;
}

$PackageWebCoreEnd
