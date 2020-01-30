#include "Entities/ClientRequestConverter.h"

#include "Parsers/JSONParser.h"
#include "Parsers/XmlParser.h"

bool ClientRequestConverter::provideClientRequest(ClientRequest& resultData, const std::string& inputData)
{
    bool status{false};

    mConvertStrategy = std::unique_ptr<JSONParser>(new JSONParser);
    if (mConvertStrategy) {
        status = mConvertStrategy->provideClientRequest(resultData, inputData);
    }
/*
    mConvertStrategy = std::make_unique<XmlParser>();
    if (mConvertStrategy) {
        status = mConvertStrategy->provideClientRequest(resultData, inputData);
    }
*/
    return status;

}
