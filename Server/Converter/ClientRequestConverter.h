#pragma once

#include <memory>
#include <string>

#include "Deserializer/IDeserializer.h"
#include "Entities/ClientRequest.h"

class ClientRequestConverter
{
public:
    bool provideClientRequest(ClientRequest& resultData, const std::string& inputData);
private:
    std::unique_ptr<IDeserializer> mConvertStrategy;
};
