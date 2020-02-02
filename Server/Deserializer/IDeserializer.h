#pragma once

#include "Entities/ClientRequest.h"

class IDeserializer
{
public:
    virtual bool provideClientRequest(ClientRequest& resultData, const std::string& inputData) = 0;
};
