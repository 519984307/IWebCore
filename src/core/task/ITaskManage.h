﻿#pragma once

#include "base/IHeaderUtil.h"
#include "base/IPreProcessorUtil.h"

$PackageWebCoreBegin

class ITaskWare;
class ITaskCatagory;

class ITaskManage
{
    $UseInstance(ITaskManage)
public:
    using FunType = std::function<void()>;
    using ArgumentTaskFunType = std::function<void(const QStringList&)>;

private:
    ITaskManage() = default;

public:
    static void run();

    void addTaskWare(ITaskWare* node);
    void addTaskCatagory(ITaskCatagory*);

private:
    void execTaskNodes();
    void checkCatagoryExceed();
    void checkTaskExceed();
    void checkTaskWareErrorCatagory();

private:
    QList<ITaskWare*> m_taskWares;
    QList<ITaskCatagory*> m_catagories;
    bool m_isTaskFinished{false};
    QStringList m_arguments;
};

$PackageWebCoreEnd
