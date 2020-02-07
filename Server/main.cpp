#include "Converter/ClientRequestConverter.h"
#include "Executor/FunctionExecutor.h"
#include "Serializer/JSON/JSONSerializer.h"
#include "Serializer/XML/XMLSerializer.h"
#include "IConnection/IConnection.h"
#include "IConnection/Connection/Connection.h"
#include "IConnection/Connection/TCP/TCP.h"

int main()
{
    TCP tcp;
    ServerResult result;
    Connection conncetion(tcp);
    conncetion.communicateStart();

    ClientRequest requestData;
    ClientRequestConverter converter;

/*
    const char* data ="<xml>\
                            <funcName>multipl</funcName>\
                                <parameter>\
                                    <value1>4</value1>\
                                    <value2>2</value2>\
                                </parameter>\
                       </xml>";
*/
    converter.provideClientRequest(requestData, conncetion.mBuffer);


    FunctionExecutor executor;
    executor.ExecuteCommand(requestData, result);

    JSONSerializer JSer;
    JSer.serializeData(requestData, result);
/*
    XMLSerializer XSer;
    XSer.serializeData(requestData, result);
    return 0;
*/

    conncetion.clientResponseWriting(result);

    return 0;
}

