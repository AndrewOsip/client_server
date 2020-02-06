#include "Executor/FunctionExecutor.h"

#include <functional>

const std::map<std::string, std::function<int(int, int)>> STORAGE = {
{"summ", [](int firstValue, int secondValue) { return firstValue + secondValue;}},
{"division", [](int firstValue, int secondValue) { return firstValue / secondValue;}},
{"multipl", [](int firstValue, int secondValue) { return firstValue * secondValue;}},
{"subtr", [](int firstValue, int secondValue) { return firstValue - secondValue;}}
};

int FunctionExecutor::runCommand(ClientRequest& resultData)
{
    auto firstValueIter = resultData.mapParams.find("value1");
    auto secondValueIter = resultData.mapParams.find("value2");
    if (firstValueIter == std::end(resultData.mapParams) || secondValueIter == std::end(resultData.mapParams)) {
        return 0;
    }
    
    int resultOperation{0};
    auto findIter = STORAGE.find(resultData.functionName);
    if (findIter != std::end(STORAGE)) {
        resultOperation = findIter->second(firstValueIter->second, secondValueIter->second);
    }

    return resultOperation;
}

void FunctionExecutor::ExecuteCommand(ClientRequest& resultData, ServerResult& result)
{
    result.operationResult = runCommand(resultData);
}
