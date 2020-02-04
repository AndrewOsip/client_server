#pragma once

#include <netdb.h>

#include "InitialEntities/InitialEntities.h"

class TCPEntities
{
public:
    int socketDescriptor;
    int newSocketDescriptor;
    int portNumber;
    int clientLenght;
    char buffer[2048];
    struct sockaddr_in serverAdress;
    struct hostent *server;
    int dataStorage;
};

