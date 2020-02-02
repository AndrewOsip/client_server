#pragma once

#include "Serializer/ISerializer.h"

class XmlDeserializer : public ISerializer
{
public:
    bool provideClientRequest(ClientRequest& resultData, const std::string& inputData) override;
};



