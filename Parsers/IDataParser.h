#pragma once

#include "Entities/ClientRequest.h"

class IDataParser
{
public:
    virtual bool provideClientRequest(ClientRequest& resultData, const std::string& inputData) = 0;
    virtual std::string desserializeData(ClientRequest& resultData) =0;
    virtual ~IDataParser() =0 ;
};
