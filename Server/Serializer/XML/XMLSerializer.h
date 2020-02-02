#pragma once

#include "Serializer/ISerializer.h"

class XMLSerializer : public ISerializer
{
public:
    bool serializeData(ClientRequest& resultData, ServerResult& result) override;
    bool provideClientRequest(ClientRequest& resultData, const std::string& inputData) override;
};
