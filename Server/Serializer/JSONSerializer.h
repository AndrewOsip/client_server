#pragma once

#include "Serializer/ISerializer.h"

class JSONSerializer : public ISerializer
{
public:
    bool serializeData(ClientRequest& resultData, ServerResult& result) override;
};
