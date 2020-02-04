#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <map>

#include "json/usr/include/rapidjson/document.h"
#include "json/usr/include/rapidjson/writer.h"
#include "json/usr/include/rapidjson/stringbuffer.h"

#include "InitialConditions/JSONSerialize/JsonInitialConditions.h"
#include "InitialEntities/InitialEntities.h"
#include "Connection/IConnection.h"
#include "Connection/TCP/TCPEntities/TCPEntities.h"
#include "Connection/TCP/ClientWorker/TCPConnection.h"


int main()
{

    InitialEntities initialData;

    initialData.value1;
    initialData.value2;
    initialData.mathematical_action;

    std::cout << "Enter Math_action(summ, division, multipl, substr): " << std::endl;
    std::cin >> initialData.mathematical_action;
    std::cout << "Enter first param: " << std::endl;
    std::cin >> initialData.value1;
    std::cout << "Enter second param: " << std::endl;
    std::cin >> initialData.value2;

    TCPEntities data;
    JsonInitialConditions jic;
    jic.toJson(initialData); // <--Данные на отправку

    TCPConnection tcpConnect;
    data.portNumber = 8888;
    const char* name = "0";
    data.server = gethostbyname(name);
    tcpConnect.SocketPointCreate(data);
    tcpConnect.ServerConnecting(data);
    tcpConnect.MessageFromUser(data, initialData);
    tcpConnect.MessageToServerSending(data, initialData);
    tcpConnect.ServerResponseReading(data);


    return 0;
}
