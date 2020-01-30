#pragma once

#include "Parsers/IDataParser.h"

class JSONParser : public IDataParser
{
public:
    bool provideClientRequest(ClientRequest& resultData, const std::string& inputData) override;
};
