#include "InitialConditions/JSONSerialize/JsonInitialConditions.h"
#include "InitialEntities/InitialEntities.h"

void JsonInitialConditions::toJson(InitialEntities& initialData)
{
    initialData.JSONAnswer = "{\"Mathematical_action\":\"" + initialData.mathematical_action +
            "\",\"parameter\": {\"value1\": " + std::to_string(initialData.value1) + ", \"value2\": " + std::to_string(initialData.value2) + "}}";
}

