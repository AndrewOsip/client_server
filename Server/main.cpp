#include <iostream>

#include "Converter/ClientRequestConverter.h"
#include "Executor/FunctionExecutor.h"
#include "Deserializer/JSONDeserializer.h"
#include "Deserializer/XmlDeserializer.h"
#include "Serializer/JSONSerializer.h"
#include "Serializer/XMLSerializer.h"
#include "Entities/ServerResult.h"

int main()
{
    ClientRequest requestData;
    ClientRequestConverter converter;
    ServerResult result;

    const char* data = "{\"Mathematical_action\":\"multipl\",\"parameter\": {\"value1\": 4, \"value2\": 2}}";
    converter.provideClientRequest(requestData, data);
/*
    const char* data ="<xml>\
                            <funcName>multipl</funcName>\
                                <parameter>\
                                    <value1>4</value1>\
                                    <value2>2</value2>\
                                </parameter>\
                       </xml>";

    std::cout << data << std::endl;
    converter.provideClientRequest(requestData, data);
*/
    FunctionExecutor executor;
    executor.ExecuteCommand(requestData, result);

    JSONSerializer JSer;
    JSer.serializeData(requestData, result);
/*
    XMLSerializer XSer;
    XSer.serializeData(requestData);
    return 0;
*/
}

