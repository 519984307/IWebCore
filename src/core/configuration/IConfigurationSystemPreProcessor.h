﻿#pragma once

#include "IConfigurationManage.h"
#include "base/IHeaderUtil.h"
#include "base/IToeUtil.h"
#include "base/IPreProcessorUtil.h"

#define PP_SYSTEM_SETTING(klassName, path, value)   \
class klassName \
{   \
public: \
    klassName(){    \
        QString key = IToeUtil::trimQuote( #path ); \
        QJsonValue val = QJsonValue(value); \
        IConfigurationManage::setSystemValue(key, val); \
    }   \
    static klassName* instance(){   \
        static klassName inst;  \
        return &inst;   \
    }   \
};  \
static klassName* system_setting_ ## klassName ## _instance = klassName::instance();

#define $EnableConfigFile(fileName) \
    PP_SYSTEM_SETTING(EnableFileClass, PP_FILE, fileName)

#define $EnableDefaultStaticDir(prefix) \
    PP_SYSTEM_SETTING(EnableDefaultStaticFilePrefix, PP_DEFAULT_STATIC_DIR, prefix)

#define $EnableBluePrint(boolValue) \
    PP_SYSTEM_SETTING(EnableBluePrint, SYSTEM_BLUE_PRINT, boolValue)

#define $EnableBeanResolveStrictMode(boolValue) \
    PP_SYSTEM_SETTING(EnableBeanResolveStrictMode, BEAN_RESOLVE_IS_STRICT_MODE, boolValue)

#define $EnableSqlInfoPrint(boolValue) \
    PP_SYSTEM_SETTING(EnableSqlInfoPrint, ENABLE_SQL_PRINT_INFO, boolValue)

// begin task
#define $EnableCatagory(catagoryName) \
    PP_SYSTEM_SETTING(EnableCatagory_##catagoryName, CATAGORY_ENABLE_STATE_##catagoryName, true)

#define $DisableCatagory(catagoryName) \
    PP_SYSTEM_SETTING(DisableCatagory_##catagoryName, CATAGORY_ENABLE_STATE_##catagoryName, false)

#define $EnableTask(catagoryName, taskName) \
    PP_SYSTEM_SETTING(EnableTask_##catagoryName##_##taskName, TASK_ENABLE_STATE_##catagoryName##_##taskName, true)

#define $DisableTask(catagoryName, taskName) \
    PP_SYSTEM_SETTING(DisableTask_##catagoryName##_##taskName, TASK_ENABLE_STATE_##catagoryName##_##taskName, false)
// end task

// begin test
#define $EnableTest_(N) $EnableTest_##N
#define $EnableTest_EVAL(N) $EnableTest_(N)
#define $EnableTest(...) PP_EXPAND( $EnableTest_EVAL(PP_EXPAND( PP_NARG(__VA_ARGS__) ))(__VA_ARGS__) )

#define $EnableTest_1(testKlass1) \
    $EnableTask(Test, testKlass1)

#define $EnableTest_2(testKlass1, testKlass2) \
    $EnableTest_1(testKlass1) \
    $EnableTask(Test, testKlass2)

#define $EnableTest_3(testKlass1, testKlass2, testKlass3) \
    $EnableTest_1(testKlass1, testKlass2) \
    $EnableTask(Test, testKlass3)

#define $EnableTest_4(testKlass1, testKlass2, testKlass3, testKlass4) \
    $EnableTest_5(testKlass1, testKlass2, testKlass3) \
    $EnableTask(Test, testKlass4)

#define $EnableTest_5(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5) \
    $EnableTest_5(testKlass1, testKlass2, testKlass3, testKlass4) \
    $EnableTask(Test, testKlass5)

#define $EnableTest_6(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6) \
    $EnableTest_5(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5) \
    $EnableTask(Test, testKlass6)

#define $EnableTest_7(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6, testKlass7) \
    $EnableTest_6(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6) \
    $EnableTask(Test, testKlass7)

#define $EnableTest_8(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6, testKlass7, testKlass8) \
    $EnableTest_7(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6, testKlass7) \
    $EnableTask(Test, testKlass8)

#define $EnableTest_9(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6, testKlass7, testKlass8, testKlass9) \
    $EnableTest_8(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6, testKlass7, testKlass8) \
    $EnableTask(Test, testKlass9)

#define $DisableTest_(N) $DisableTest_##N
#define $DisableTest_EVAL(N) $DisableTest_(N)
#define $DisableTest(...) PP_EXPAND( $DisableTest_EVAL(PP_EXPAND( PP_NARG(__VA_ARGS__) ))(__VA_ARGS__) )

#define $DisableTest_1(testKlass1) \
    $DisableTask(Test, testKlass1)

#define $DisableTest_2(testKlass1, testKlass2) \
    $DisableTest_1(testKlass1) \
    $DisableTask(Test, testKlass2)

#define $DisableTest_3(testKlass1, testKlass2, testKlass3) \
    $DisableTest_1(testKlass1, testKlass2) \
    $DisableTask(Test, testKlass3)

#define $DisableTest_4(testKlass1, testKlass2, testKlass3, testKlass4) \
    $DisableTest_5(testKlass1, testKlass2, testKlass3) \
    $DisableTask(Test, testKlass4)

#define $DisableTest_5(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5) \
    $DisableTest_5(testKlass1, testKlass2, testKlass3, testKlass4) \
    $DisableTask(Test, testKlass5)

#define $DisableTest_6(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6) \
    $DisableTest_5(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5) \
    $DisableTask(Test, testKlass6)

#define $DisableTest_7(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6, testKlass7) \
    $DisableTest_6(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6) \
    $DisableTask(Test, testKlass7)

#define $DisableTest_8(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6, testKlass7, testKlass8) \
    $DisableTest_7(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6, testKlass7) \
    $DisableTask(Test, testKlass8)

#define $DisableTest_9(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6, testKlass7, testKlass8, testKlass9) \
    $DisableTest_8(testKlass1, testKlass2, testKlass3, testKlass4, testKlass5, testKlass6, testKlass7, testKlass8) \
    $DisableTask(Test, testKlass9)
// end test
