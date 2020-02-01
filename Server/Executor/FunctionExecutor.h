#pragma once

#include <iostream>

#include "Executor/IExecutor.h"

class FunctionExecutor : public IExecutor
{
public:
    void ExecuteCommand(ClientRequest& resultData) override;

private:
    int runCommand(ClientRequest& resultData);
};
