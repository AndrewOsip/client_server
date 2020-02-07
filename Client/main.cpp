#include "InitialEntities/InitialEntities.h"

#include "IConnection/IConnection.h"
#include "IConnection/Connection/Connection.h"
#include "IConnection/Connection/TCP/TCP.h"
#include "InitialConditions/JSONSerialize/JsonInitialConditions.h"

int main()
{
    //Connection::Connection(int networkType, int port)
    //Connection(tcp.mPortNumber,tcp.mPortNumber, tcp.mHost);

    InitialEntities initialData;

    std::cout << "Enter Math_action(summ, division, multipl, substr): " << std::endl;
    std::cin >> initialData.mathematical_action;
    std::cout << "Enter first param: " << std::endl;
    std::cin >> initialData.value1;
    std::cout << "Enter second param: " << std::endl;
    std::cin >> initialData.value2;

    JsonInitialConditions jic;
    jic.toJson(initialData);
    TCP tcp;
    Connection connect(tcp);
    connect.messageFromUser(initialData);
    connect.messageToServerSending();
    connect.serverResponseReading();


    return 0;
}
