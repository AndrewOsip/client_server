#pragma once

#include "InitialConditions/IInitialConditions.h"

class JsonInitialConditions : public IInitialConditions
{
public:
    void toJson(InitialEntities& initialData) override;
};

