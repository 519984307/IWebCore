﻿#include <ICore/IApplication>
#include <ICore/IContext>
#include <IWeb/IWeb>

//#include "core/bean/IBeanTypeManage.h"

$EnableDefaultConfigFiles

//$EnableConfigFiles(true)
//$SetConfigFilesPath("D:/code/IWebCore/test/TestHttps/TestSimpleController/config")

$EnableTaskOutput
//$EnableControllerPrint(true)
$EnableCatagory(Controller)
$SetIpPort(1000)

int main(int argc, char *argv[])
{
    IApplication a(argc, argv);

    IHttpServer server;
//    server.setPort(81);
    server.listen();

    return a.exec();
}
