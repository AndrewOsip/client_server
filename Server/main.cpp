#include "Converter/ClientRequestConverter.h"
#include "Executor/FunctionExecutor.h"
#include "Serializer/JSON/JSONSerializer.h"
#include "Serializer/XML/XMLSerializer.h"
#include "Connection/TCP/ClientWorker/TCPConnection.h"
#include "Connection/TCP/TCPEntities/TCPEntities.h"
#include "Connection/IConnection.h"

int main()
{
    TCPEntities data;
    TCPConnection tcpConnect;
    ServerResult result;
    tcpConnect.FirstFunctionCall(data);
    tcpConnect.SocketStructureInitalize(data);
    tcpConnect.HostAddressBind(data);
    tcpConnect.ClientsListening(data);
    tcpConnect.ActualClientConnectionAccept(data);
    tcpConnect.CommunicateStart(data);


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
    converter.provideClientRequest(requestData, data.buffer);

    FunctionExecutor executor;
    executor.ExecuteCommand(requestData, result);

    JSONSerializer JSer;
    JSer.serializeData(requestData, result);
/*
    XMLSerializer XSer;
    XSer.serializeData(requestData, result);
    return 0;
*/
    tcpConnect.ClientResponseWriting(data, result);
}

