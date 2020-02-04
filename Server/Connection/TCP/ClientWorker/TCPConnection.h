#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "Connection/IConnection.h"

class TCPConnection : public IConnection
{
public:
    void FirstFunctionCall(TCPEntities& data) override;
    void SocketStructureInitalize(TCPEntities& data) override;
    void HostAddressBind(TCPEntities& data) override;
    void ClientsListening(TCPEntities& data) override;
    void ActualClientConnectionAccept(TCPEntities& data) override;
    void CommunicateStart(TCPEntities& data) override;
    void ClientResponseWriting(TCPEntities& data, ServerResult& result) override;

};
