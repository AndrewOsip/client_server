#include <iostream>

#include "Entities/ClientRequestConverter.h"
#include "Executor/FunctionExecutor.h"

int main()
{
    ClientRequest requestData;
    ClientRequestConverter converter;

    const char* data = "{\"funcName\":\"summ\",\"params\": {\"value1\": 4, \"value2\": 2}}";
    converter.provideClientRequest(requestData, data);
/*
    const char* data = "<xml>\
                            <funcName>multipl</funcName>\
                                <params>\
                                    <value1>4</value1>\
                                    <value2>2</value2>\
                                </params>\
                       </xml>";


    converter.provideClientRequest(requestData, data);
*/
    FunctionExecutor executor;
    executor.ExecuteCommand(requestData);

    return 0;
}

