#pragma once

#include <string>
#include <netdb.h>

#include "Connection/TCP/TCPEntities/TCPEntities.h"

class IConnection
{
public:
    virtual void SocketPointCreate(TCPEntities& data) =0;
    virtual void ServerConnecting(TCPEntities& data) =0;
    virtual void MessageFromUser(TCPEntities& data, InitialEntities& initialData) =0;
    virtual void MessageToServerSending(TCPEntities& data, InitialEntities& initialData) =0;
    virtual void ServerResponseReading(TCPEntities& data) =0;

    virtual ~IConnection() =default;
};
