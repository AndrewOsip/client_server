#pragma once

#include "Entities/ClientRequest.h"

class IExecutor
{
public:
    virtual void ExecuteCommand(ClientRequest& resultData) = 0;
    virtual ~IExecutor() =0 ;
};
