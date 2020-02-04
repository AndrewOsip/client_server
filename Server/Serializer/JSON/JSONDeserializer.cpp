#include "Serializer/JSON/JSONSerializer.h"

bool JSONSerializer::provideClientRequest(ClientRequest& resultData, const std::string& inputData)
{
    rapidjson::Document questionDocument;
    questionDocument.Parse(inputData.c_str());

    if(!questionDocument.IsObject()) {
        throw std::runtime_error("document is not an Object");
    }

    resultData.functionName = questionDocument["Mathematical_action"].GetString();

    const auto& params = questionDocument["parameter"].GetObject();
    for (const auto& item : params) {
        resultData.mapParams[item.name.GetString()] = item.value.GetInt();
    }

    if(resultData.mapParams.size() != 2) {
        throw std::runtime_error("wrong array size");
    }

    return true;
}
