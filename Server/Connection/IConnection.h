#pragma once

#include "Connection/TCP/TCPEntities/TCPEntities.h"
#include "Entities/ServerResult.h"

class IConnection
{
public:
    virtual void FirstFunctionCall(TCPEntities& data) =0;
    virtual void SocketStructureInitalize(TCPEntities& data) =0;
    virtual void HostAddressBind(TCPEntities& data) =0;
    virtual void ClientsListening(TCPEntities& data) =0;
    virtual void ActualClientConnectionAccept(TCPEntities& data) =0;
    virtual void CommunicateStart(TCPEntities& data) =0;
    virtual void ClientResponseWriting(TCPEntities& data, ServerResult& result) =0;
    virtual ~IConnection() =default;
};
