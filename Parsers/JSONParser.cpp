#include <vector>
#include <algorithm>
#include <iterator>
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

void JSONParser::desserializeData(ClientRequest& resultData)
{
    this->operationName = resultData.functionName;
    this->operationResult = resultData.resultOperation;

    rapidjson::Value json_val;
    rapidjson::Document currentDocument;
    auto& allocator = currentDocument.GetAllocator();

    currentDocument.SetObject();

    json_val.SetInt(operationResult);
    currentDocument.AddMember("value", json_val, allocator);

    json_val.SetString(operationName.c_str(), allocator);
    currentDocument.AddMember("funcName", json_val, allocator);

    static const char* members[] = { "value", "funcName" };
    for(size_t i = 0; i < sizeof(members)/sizeof(members[0]); i++)
    {
        if(!currentDocument.HasMember(members[i]))
                        throw std::runtime_error("missing fields");
    }
//__________Теперь ебу как из этого получить файл JSON______________
    int value = currentDocument["value"].GetInt();
    std::string funcName = currentDocument["funcName"].GetString();
//__________________________________________________________________
    std::cout << funcName << " = " << value << std::endl; // показываю что 2 значения уже в файле просто их достал
}
