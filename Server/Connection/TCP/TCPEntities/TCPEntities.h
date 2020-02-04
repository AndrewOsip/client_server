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

class TCPEntities
{
public:
    int socketDescriptor;
    int newSocketDescriptor;
    int portNumber = 8888;
    socklen_t clientLenght;
    char buffer[256];
    struct sockaddr_in serverAdress, clientAdress;
    ssize_t dataStorage;
};
