#pragma once

#include "Deserializer/IDeserializer.h"

class JSONDeserializer : public IDeserializer
{
public:
    bool provideClientRequest(ClientRequest& resultData, const std::string& inputData) override;
};
