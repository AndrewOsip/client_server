#include <algorithm>
#include <iostream>

#include "Parsers/JSONParser.h"
#include "Parsers/XmlParser.h"
#include "Executor/FunctionExecutor.h"

#include "json/usr/include/rapidjson/document.h"
#include "json/usr/include/rapidjson/writer.h"
#include "json/usr/include/rapidjson/stringbuffer.h"

bool JSONParser::provideClientRequest(ClientRequest& resultData, const std::string& inputData)
{
    rapidjson::Document currentDocument;
    currentDocument.Parse(inputData.c_str());

    if(!currentDocument.IsObject()) {
        throw std::runtime_error("document is not an Object");
    }

    resultData.functionName = currentDocument["funcName"].GetString();

    const auto& params = currentDocument["params"].GetObject();
    for (const auto& item : params) {
        resultData.mapParams[item.name.GetString()] = item.value.GetInt();
    }

    if(resultData.mapParams.size() != 2) {
        throw std::runtime_error("wrong array size");
    }

    return true;
}

std::string JSONParser::desserializeData(ClientRequest& resultData)
{
    this->operationName = resultData.functionName;
    this->operationResult = resultData.resultOperation;

    rapidjson::Value json_val;
    rapidjson::Document currentDocument;
    auto& allocator = currentDocument.GetAllocator();

    currentDocument.SetObject();

    json_val.SetString(operationName.c_str(), allocator);
    currentDocument.AddMember("funcName", json_val, allocator);
    json_val.SetInt(operationResult);
    currentDocument.AddMember("value", json_val, allocator);

    rapidjson::StringBuffer buffer;

    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    currentDocument.Accept(writer);

    const std::string& str = buffer.GetString();
    std::cout << "Serialized:" << std::endl;
    std::cout << str << std::endl;

    return str;
}
