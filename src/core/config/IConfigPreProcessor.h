﻿#pragma once

#include "core/base/IPreProcessorUtil.h"
#include "core/base/IToeUtil.h"
#include "core/config/IContextTaskInterface.h"
#include "core/config/IProfileTaskInterface.h"
#include "core/task/unit/ITaskInstantUnit.h"

#define $AsConfig(klassName)   \
    $AsTask(klassName)

#define $AsProfile(klassName)   \
    $AsConfig(klassName)

#define $AsContext(klassName)   \
    $AsConfig(klassName)

#define PP_PRIVILIGE_CONTEXT_CONFIG(klassName, path_, value)   \
class klassName : public ITaskInstantUnit < klassName, true >  \
{   \
public:     \
    klassName(){};  \
    virtual void task() final {  \
        QString key = IToeUtil::trimQuote( #path_ ); \
        QJsonValue obj = QJsonValue(value); \
        IContextManage::instance()->addConfig(obj, key); \
    }    \
};

#define PP_NORMAL_CONTEXT_CONFIG(klassName, path_, value)   \
class klassName : public IContextTaskInterface < klassName, true >  \
{   \
    $AsContext(klassName)   \
public:     \
    klassName(){};  \
    virtual QJsonValue config() final   {  return value; }  \
    virtual QString path() const final { return IToeUtil::trimQuote( #path_ ); }  \
};

#define PP_PROFILE_CONFIG(klassName, path_, value) \
class klassName : public IProfileTaskInterface < klassName, true >  \
{   \
    $AsContext(klassName)   \
public:     \
    klassName(){};  \
    virtual QJsonValue config() final   {  return value; }  \
    virtual QString path() const final { return IToeUtil::trimQuote( #path_ ); }  \
};