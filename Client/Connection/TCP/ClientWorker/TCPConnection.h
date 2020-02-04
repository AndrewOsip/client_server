#pragma once

#include "Connection/IConnection.h"
#include "Connection/TCP/TCPEntities/TCPEntities.h"

#include "lib/json/usr/include/rapidjson/document.h"
#include "lib/json/usr/include/rapidjson/writer.h"
#include "lib/json/usr/include/rapidjson/stringbuffer.h"

class TCPConnection : public IConnection
{
public:
    void SocketPointCreate(TCPEntities& data) override;
    void ServerConnecting(TCPEntities& data) override;
    void MessageFromUser(TCPEntities& data, InitialEntities& initialData) override;
    void MessageToServerSending(TCPEntities& data) override;
    void ServerResponseReading(TCPEntities& data) override;
};
