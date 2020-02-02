#pragma once

#include "Entities/ClientRequest.h"
#include "Entities/ServerResult.h"

class ISerializer
{
public:
    virtual bool serializeData(ClientRequest& resultData, ServerResult& result) =0;
    virtual ~ISerializer() =0 ;
};
