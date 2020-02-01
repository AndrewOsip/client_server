#pragma once

#include "IInitialConditions.h"

class InitialConditions : public IInitialConditions
{
public:
    InitialConditions(std::string mathematicalActions, int value1, int value2) :
        mMathematical_action(mathematicalActions),
        mValue1(value1),
        mValue2(value2) {}

    std::string toJson() override;

private:
    std::string mMathematical_action;
    int mValue1;
    int mValue2;
};

