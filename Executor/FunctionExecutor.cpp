#include "Entities/ClientRequest.h"
#include "Executor/FunctionExecutor.h"

#include <string>
#include <functional>

namespace {
const std::map<std::string, std::function<int(int, int)>> STORAGE = {
{"summ", [](int firstValue, int secondValue) { return firstValue + secondValue;}}

};

}

int FunctionExecutor::runCommand(ClientRequest& resultData)
{
    auto firstValueIter = resultData.mapParams.find("value1");
    auto secondValueIter = resultData.mapParams.find("value2");
    if (firstValueIter == std::end(resultData.mapParams) || secondValueIter == std::end(resultData.mapParams)) {
        return 0;
    }
    return STORAGE.at(resultData.functionName)(firstValueIter->second, secondValueIter->second);
}

void FunctionExecutor::ExecuteCommand(ClientRequest& resultData)
{
    int result = runCommand(resultData);

    std::cout << "result of " << resultData.functionName << " = " << result << std::endl;
}



