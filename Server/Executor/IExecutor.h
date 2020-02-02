#pragma once

#include "Entities/ClientRequest.h"
#include "Entities/ServerResult.h"

class IExecutor
{
public:
    virtual void ExecuteCommand(ClientRequest& resultData, ServerResult& result) = 0;
    virtual ~IExecutor() =0 ;
};
