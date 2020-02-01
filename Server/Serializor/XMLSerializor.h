#pragma once

#include "Serializor/ISerializor.h"

class XMLSerializer : public ISerializor
{
public:
    std::string serializeData(ClientRequest& resultData) override;
};
