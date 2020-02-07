#pragma once

#include "IConnection/Connection/Connection.h"

class TCP : public Connection
{
public:
    TCP(): Connection(SOCK_STREAM, 8888, gethostbyname("0")) {}
};
