#include "Converter/ClientRequestConverter.h"

#include "Serializer/JSON/JSONSerializer.h"
#include "Serializer/XML/XmlDeserializer.h"

bool ClientRequestConverter::provideClientRequest(ClientRequest& resultData, const std::string& inputData)
{
    bool status{false};

    mConvertStrategy = std::make_unique<JSONSerializer>();
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
