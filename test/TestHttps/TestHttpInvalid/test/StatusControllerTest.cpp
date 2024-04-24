﻿#include <IWeb/HttpRequest>

#include "StatusControllerTest.h"
#include <iostream>

void StatusControllerTest::testInt()
{
    http::Request req(url + "/int");
    auto res = req.send("GET");
    QVERIFY(HttpRequestHelper::toBody(res).isEmpty());
    QVERIFY(HttpRequestHelper::toStatus(res) == IHttpStatus::NOT_FOUND_404);
}

void StatusControllerTest::testIntString()
{
    http::Request req(url + "/intString");
    auto res = req.send("GET");
    QVERIFY(HttpRequestHelper::toBody(res) == "status");
    QVERIFY(HttpRequestHelper::toStatus(res) == IHttpStatus::NOT_FOUND_404);
}

void StatusControllerTest::testStatus()
{
    http::Request req(url + "/status");
    auto res = req.send("GET");
    QVERIFY(HttpRequestHelper::toBody(res).isEmpty());
    QVERIFY(HttpRequestHelper::toStatus(res) == IHttpStatus::INTERNAL_SERVER_ERROR_500);
}

void StatusControllerTest::testStatusString()
{
    http::Request req(url + "/statusString");
    auto res = req.send("GET");
    QVERIFY(HttpRequestHelper::toBody(res) == "created");
    QVERIFY(HttpRequestHelper::toStatus(res) == IHttpStatus::CREATED_201);

}

void StatusControllerTest::testUserLiteral()
{
    http::Request req(url + "/userLiteral");
    auto res = req.send("GET");
    QVERIFY(HttpRequestHelper::toBody(res).isEmpty());
    QVERIFY(HttpRequestHelper::toStatus(res) == IHttpStatus::BAD_GATEWAY_502);
}