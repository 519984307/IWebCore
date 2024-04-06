﻿#pragma once

#include "core/task/default/IInitializationTaskInterface.h"
#include "core/config/IProfileImport.h"

$PackageWebCoreBegin

class INodyTemplate;
class INodyTemplateTask : public IInitializationTaskInterface<INodyTemplateTask>
{
public:
    INodyTemplateTask();

public:
    virtual void task() final;

private:
    void travelFolder(const QString& path, const QString& root);

private:
    $QString suffix{"http.templates.nody.suffix"};
    $QString defaultFolder{"http.templates.nody.defaultTemplateFolder"};
    $QString folder{"http.templates.nody.templateFolder"};
    INodyTemplate* m_template{};
};

$PackageWebCoreEnd
