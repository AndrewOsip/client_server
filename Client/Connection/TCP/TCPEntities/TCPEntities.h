#pragma once

#include <string>
#include <netdb.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "InitialEntities/InitialEntities.h"

class TCPEntities
{
public:
    int socketDescriptor;
    int newSocketDescriptor;
    int portNumber;
    int clientLenght;
    char buffer[100000];
    struct sockaddr_in serverAdress;
    struct hostent *server;
    int dataStorage;
};

