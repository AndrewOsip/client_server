#pragma once

#include "InitialEntities/InitialEntities.h"

class IConnection
{
public:
    virtual ~IConnection() = default;
public:
    virtual void messageFromUser(InitialEntities& initialData) = 0;
    virtual void messageToServerSending() = 0;
    virtual void serverResponseReading() = 0;
};
