﻿#pragma once

#include "core/base/IHeaderUtil.h"
#include "core/base/IMetaUtil.h"
//#include "core/assert/IGlobalAssert.h"

$PackageWebCoreBegin

//$UseGlobalAssert()

template<typename T>
class ISingletonUnit
{
protected:
    ISingletonUnit();
    virtual ~ISingletonUnit() = default;

    ISingletonUnit(const ISingletonUnit&) = delete;
    ISingletonUnit& operator=(const ISingletonUnit&) = delete;

public:
    static T* instance() {
        static T instance;
        return &instance;
    }
};

// TODO: GlobalAstError

template<typename T>
ISingletonUnit<T>::ISingletonUnit()
{
    static std::atomic_bool flag{false};
    if(flag){
//        IAssertInfo info;
//        info.className = IMetaUtil::getTypename<T>();
//        $GlobalAssert->fatal("SingletonInstanceCreateError");
        qFatal("SingletonInstanceCreateError ", IMetaUtil::getTypename<T>());
    }
    flag = true;
}

$PackageWebCoreEnd
