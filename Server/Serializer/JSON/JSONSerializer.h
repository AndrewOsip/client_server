#pragma once

#include "Serializer/ISerializer.h"


#include "lib/json/usr/include/rapidjson/document.h"
#include "lib/json/usr/include/rapidjson/writer.h"
#include "lib/json/usr/include/rapidjson/stringbuffer.h"

class JSONSerializer : public ISerializer
{
public:
    bool serializeData(ClientRequest& resultData, ServerResult& result) override;
    bool provideClientRequest(ClientRequest& resultData, const std::string& inputData) override;
};
