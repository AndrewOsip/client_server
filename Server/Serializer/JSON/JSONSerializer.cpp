#include <iostream>

#include "Serializer/JSON/JSONSerializer.h"

#include "lib/json/usr/include/rapidjson/document.h"
#include "lib/json/usr/include/rapidjson/writer.h"
#include "lib/json/usr/include/rapidjson/stringbuffer.h"

bool JSONSerializer::serializeData(ClientRequest &resultData, ServerResult& result)
{
    result.operationName = resultData.functionName;

    rapidjson::Value json_val;
    rapidjson::Document answerDocument;
    auto& allocator = answerDocument.GetAllocator();

    answerDocument.SetObject();

    json_val.SetString(result.operationName.c_str(), allocator);
    answerDocument.AddMember("Mathematical_action", json_val, allocator);
    json_val.SetInt(result.operationResult);
    answerDocument.AddMember("answer", json_val, allocator);

    rapidjson::StringBuffer buffer;

    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    answerDocument.Accept(writer);

    const std::string& str = buffer.GetString();
    std::cout << "Serialized:" << "\n" << std::endl;
    result.answer = str;
    std::cout << result.answer << std::endl;

    return true;
}
