#pragma once

#include "Serializer/ISerializer.h"

class JSONDeserializer : public ISerializer
{
public:
    bool provideClientRequest(ClientRequest& resultData, const std::string& inputData) override;
};
