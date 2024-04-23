﻿#include "IHttpPathFunctorValidatorInterface.h"
#include "IHttpManage.h"

$PackageWebCoreBegin

void IHttpPathFunctorValidatorInterfaceHelper::registValidator(const QString &name, std::function<bool (const QString &)> validator)
{
    IHttpManage::instance()->registerPathValidator(name, validator);
}

$PackageWebCoreEnd
