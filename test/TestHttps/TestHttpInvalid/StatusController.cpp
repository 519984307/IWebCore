﻿#include "StatusController.h"

IStatusResponse StatusController::statusResponseInt()
{
    return 404;
}

IStatusResponse StatusController::statusResponseIntString()
{
    return {404, "status"};
}

IStatusResponse StatusController::statusResponseStatus()
{
    return IHttpStatus::INTERNAL_SERVER_ERROR_500;
}

IStatusResponse StatusController::statusResponseStatusString()
{
    return {
        IHttpStatus::CREATED_201,
        "created"
    };
}

IStatusResponse StatusController::userLiteral()
{
    return 502_status;
}

IHtmlResponse StatusController::replace()
{
    IStatusResponse response(404, "replace content");
    return response;
}

