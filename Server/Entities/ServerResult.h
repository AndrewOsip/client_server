#pragma once

#include <string>
#include <string.h>

class ServerResult
{
public:
    std::string operationName;
    int operationResult;
    std::string answer;
    char buffer[1024];
};
