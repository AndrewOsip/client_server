#include <iostream>

#include "Entities/ClientRequestConverter.h"
#include "Executor/FunctionExecutor.h"
#include "Parsers/JSONParser.h"

int main()
{
    ClientRequest requestData;
    ClientRequestConverter converter;

    const char* data = "{\"funcName\":\"division\",\"params\": {\"value1\": 4, \"value2\": 2}}";
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

    JSONParser JDes;
    JDes.desserializeData(requestData);

    return 0;
}

