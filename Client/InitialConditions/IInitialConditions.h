#pragma once

#include <string>
#include <iostream>

#include "InitialEntities/InitialEntities.h"

class IInitialConditions
{
public:
    virtual void toJson(InitialEntities& initialData) = 0;
    virtual ~IInitialConditions() =default;
};
