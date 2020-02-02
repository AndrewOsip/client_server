#include "Converter/ClientRequestConverter.h"

#include "Deserializer/JSONDeserializer.h"
#include "Deserializer/XmlDeserializer.h"

bool ClientRequestConverter::provideClientRequest(ClientRequest& resultData, const std::string& inputData)
{
    bool status{false};

    mConvertStrategy = std::make_unique<JSONDeserializer>();
    if (mConvertStrategy) {
        status = mConvertStrategy->provideClientRequest(resultData, inputData);
    }
/*
    mConvertStrategy = std::make_unique<XmlDeserializer>();
    if (mConvertStrategy) {
        status = mConvertStrategy->provideClientRequest(resultData, inputData);
    }
*/
    return status;

}
