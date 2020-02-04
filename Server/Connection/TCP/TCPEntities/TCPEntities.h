#pragma once

#include <netdb.h>

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
