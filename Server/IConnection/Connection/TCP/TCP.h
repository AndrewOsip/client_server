#pragma once

#include "IConnection/Connection/Connection.h"

class TCP : public Connection
{
public:
    TCP(): Connection(8888, SOCK_STREAM) {}
};
