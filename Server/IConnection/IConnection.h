#pragma once

#include "Entities/ServerResult.h"
#include <iostream>
#include <unistd.h>

class IConnection
{
public:
    virtual ~IConnection() =default;

    virtual void CommunicateStart() =0;
    virtual void ClientResponseWriting(ServerResult& result) =0;

};
