#pragma once

#include <string>
#include <map>

class ClientRequest
{
public:
    std::string functionName;
    std::map<std::string, int> mapParams;
    int resultOperation;
};
