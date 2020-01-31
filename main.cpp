#include <iostream>

#include "Entities/ClientRequestConverter.h"
#include "Executor/FunctionExecutor.h"
#include "Parsers/JSONParser.h"
#include "Serializor/JSONSerializor.h"
#include "Serializor/XMLSerializor.h"

int main()
{
    ClientRequest requestData;
    ClientRequestConverter converter;
/*
    const char* data = "{\"Mathematical_action\":\"multipl\",\"parameter\": {\"value1\": 4, \"value2\": 2}}";
    converter.provideClientRequest(requestData, data);
*/
    const char* data ="<xml>\
                            <funcName>multipl</funcName>\
                                <parameter>\
                                    <value1>4</value1>\
                                    <value2>2</value2>\
                                </parameter>\
                       </xml>";

    std::cout << data << std::endl;
    converter.provideClientRequest(requestData, data);

    FunctionExecutor executor;
    executor.ExecuteCommand(requestData);
/*
    JSONSerializer JSer;
    JSer.serializeData(requestData);
*/
    XMLSerializer XSer;
    XSer.serializeData(requestData);
    return 0;
}

