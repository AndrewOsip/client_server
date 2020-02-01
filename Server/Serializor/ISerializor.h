#pragma once

#include "Entities/ClientRequest.h"

class ISerializor
{
public:
    virtual std::string serializeData(ClientRequest& resultData) =0;
    virtual ~ISerializor() =0 ;
    std::string operationName;
    int operationResult;
};
