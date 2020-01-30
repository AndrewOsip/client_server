#include <algorithm>
#include <iostream>

#include "Serializor/JSONSerializor.h"
#include "Executor/FunctionExecutor.h"

#include "json/usr/include/rapidjson/document.h"
#include "json/usr/include/rapidjson/writer.h"
#include "json/usr/include/rapidjson/stringbuffer.h"

std::string JSONSerializer::serializeData(ClientRequest &resultData)
{
    this->operationName = resultData.functionName;
    this->operationResult = resultData.resultOperation;

    rapidjson::Value json_val;
    rapidjson::Document answerDocument;
    auto& allocator = answerDocument.GetAllocator();

    answerDocument.SetObject();

    json_val.SetString(operationName.c_str(), allocator);
    answerDocument.AddMember("funcName", json_val, allocator);
    json_val.SetInt(operationResult);
    answerDocument.AddMember("value", json_val, allocator);

    rapidjson::StringBuffer buffer;

    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    answerDocument.Accept(writer);

    const std::string& str = buffer.GetString();
    std::cout << "Serialized:" << std::endl;
    std::cout << str << std::endl;

    return str;
}
