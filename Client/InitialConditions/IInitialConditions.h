#pragma once

#include <string>
#include <iostream>

class IInitialConditions
{
public:
    virtual std::string toJson() = 0;
    virtual ~IInitialConditions() =0;
};
