#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "Parsers/JSONParser.h"
#include "Parsers/XmlParser.h"

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
