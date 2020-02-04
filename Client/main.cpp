#include "InitialEntities/InitialEntities.h"

#include "Connection/TCP/TCPEntities/TCPEntities.h"
#include "Connection/TCP/ClientWorker/TCPConnection.h"
#include "InitialConditions/JSONSerialize/JsonInitialConditions.h"

int main()
{
    InitialEntities initialData;
    TCPEntities data;
    TCPConnection tcpConnect;

    std::cout << "Enter Math_action(summ, division, multipl, substr): " << std::endl;
    std::cin >> initialData.mathematical_action;
    std::cout << "Enter first param: " << std::endl;
    std::cin >> initialData.value1;
    std::cout << "Enter second param: " << std::endl;
    std::cin >> initialData.value2;

    JsonInitialConditions jic;
    jic.toJson(initialData);

    data.portNumber = 8888;
    data.server = gethostbyname("0");
    tcpConnect.SocketPointCreate(data);
    tcpConnect.ServerConnecting(data);
    tcpConnect.MessageFromUser(data, initialData);
    tcpConnect.MessageToServerSending(data);
    tcpConnect.ServerResponseReading(data);

    return 0;
}
