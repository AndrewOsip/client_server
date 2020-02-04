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
#include "Connection/TCP/TCPEntities/TCPEntities.h"

class TCPConnection : public IConnection
{
public:
    void SocketPointCreate(TCPEntities& data) override;
    void ServerConnecting(TCPEntities& data) override;
    void MessageFromUser(TCPEntities& data, InitialEntities& initialData) override;
    void MessageToServerSending(TCPEntities& data, InitialEntities& initialData) override;
    void ServerResponseReading(TCPEntities& data) override;
};
