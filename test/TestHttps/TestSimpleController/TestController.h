﻿#pragma once

#include "IWeb/IControllerInterface"

class TestController : public IControllerInterface<TestController, true>
{
    Q_GADGET
    $AsController(TestController)
public:
    TestController();

//    $DeleteMapping(helloDelete, /)
//    QString helloDelete(){
//        return "";
//    }

    $DeleteMappingDeclare(hello, /)
    $GetMappingDeclare(hello, /)
    Q_INVOKABLE
    QString hello();

//    $PostMapping(helloGet, hello)
//    QString helloGet(){
//        return "";
//    }

//    $GetMapping(index, hello/index)
//    IFileResponse index();
};

