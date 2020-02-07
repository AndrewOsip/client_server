#pragma once

#include "Entities/ServerResult.h"
#include <iostream>
#include <unistd.h>

class IConnection
{
public:
    virtual ~IConnection() =default;

    virtual void communicateStart() =0;
    virtual void clientResponseWriting(ServerResult& result) =0;

};
