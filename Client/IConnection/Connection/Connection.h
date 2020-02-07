#pragma once

#include "IConnection/IConnection.h"

#include <string.h>
#include <unistd.h>
#include <netdb.h>

class Connection : public IConnection
{
public:
    Connection(int networkType, int port, hostent *host) {
        socketInit(networkType, port, host);
    }

    void messageFromUser(InitialEntities& initialData) override;
    void messageToServerSending() override;
    void serverResponseReading() override;

private:
    void socketInit(int networkType, int port, hostent *host);

    int mNetworkType;
    int mPortNumber;
    int mSocketDescriptor;
    int mNewSocketDescriptor;
    int mClientLenght;
    char mBuffer[2048];
    struct sockaddr_in mServerAdress;
    struct hostent *mHost;

};

