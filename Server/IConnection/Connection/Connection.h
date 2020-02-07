#pragma once

#include <netdb.h>

#include "IConnection/IConnection.h"
#include "Entities/ServerResult.h"

class Connection : IConnection
{
public:
    char mBuffer[1024];
    Connection (int portNumber, int networkType) {
        socketInit(portNumber, networkType);
    }

    void CommunicateStart() override;
    void ClientResponseWriting(ServerResult& result) override;
private:
    void socketInit(int portNumber, int networkType);

    int mNetworkType;
    int mSocketDescriptor;
    int mNewSocketDescriptor;
    int mPortNumber;
    socklen_t mClientLenght;
    struct sockaddr_in mServerAdress, mClientAdress;
    ssize_t mDataStorage;
};
