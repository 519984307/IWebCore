﻿#pragma once

#include "base/IHeaderUtil.h"
#include "base/IConvertUtil.h"
#include "base/IMetaUtil.h"
#include "base/IJsonUtil.h"
#include "configuration/IConfigurationPreProcessor.h"
#include "core/bean/IBeanInterface.h"

$PackageWebCoreBegin

class IOrmDataSource : public IBeanInterface<IOrmDataSource>
{
    Q_GADGET
    $AsBean(IOrmDataSource)

public:
    IOrmDataSource() = default;

    $BeanField(QString, driverName)

    $BeanField(QString, databaseName)

    $BeanFieldDeclare(QString, connectionName)
    QString connectionName = "default";

    $BeanField(int, port)

    $BeanField(QString, host)

    $BeanField(QString, userName)

    $BeanField(QString, password)
};

$PackageWebCoreEnd
