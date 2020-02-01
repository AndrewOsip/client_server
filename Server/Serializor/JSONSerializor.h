#pragma once

#include "Serializor/ISerializor.h"

class JSONSerializer : public ISerializor
{
public:
    std::string serializeData(ClientRequest& resultData) override;
};
