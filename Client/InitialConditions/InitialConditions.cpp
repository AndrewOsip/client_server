#pragma once

#include "InitialConditions.h"

std::string InitialConditions::toJson()
{
    std::string JsonString = "{\"Mathematical_action\":\"" + mMathematical_action +
            "\",\"parameter\": {\"value1\": " + std::to_string(mValue1) + ", \"value2\": " + std::to_string(mValue2) + "}}";

    //std::cout << JsonString << std::endl;

    return JsonString;
}

