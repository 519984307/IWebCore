﻿#pragma once

#include <IWebCore>
#include <QtTest>

class TestBeanListMapConvertion : public ITestInterface<TestBeanListMapConvertion>
{
    Q_OBJECT
    $AsTest(TestBeanListMapConvertion)
public:
    TestBeanListMapConvertion() = default;

private slots:
    void test_Bean();
    void test_QListBean();
    void test_normalContainer();
};
