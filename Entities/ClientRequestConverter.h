#pragma once

#include <memory>
#include <string>

#include "Parsers/IDataParser.h"
#include "Entities/ClientRequest.h"

class ClientRequestConverter
{
public:
    bool provideClientRequest(ClientRequest& resultData, const std::string& inputData);
private:
    std::unique_ptr<IDataParser> mConvertStrategy;
};
