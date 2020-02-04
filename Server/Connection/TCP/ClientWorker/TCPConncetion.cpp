#include <iostream>
#include <unistd.h>

#include "Connection/TCP/ClientWorker/TCPConnection.h"

void TCPConnection::FirstFunctionCall(TCPEntities& data)
{
    data.socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
       if (data.socketDescriptor < 0) {
          perror("ERROR opening socket");
          exit(1);
       }
}

void TCPConnection::SocketStructureInitalize(TCPEntities& data)
{
    bzero((char *) &data.serverAdress, sizeof(data.serverAdress));
       data.portNumber = 8888;
       data.serverAdress.sin_family = AF_INET;
       data.serverAdress.sin_addr.s_addr = INADDR_ANY;
       data.serverAdress.sin_port = htons(data.portNumber);
}

void TCPConnection::HostAddressBind(TCPEntities& data)
{
    if (bind(data.socketDescriptor, (struct sockaddr *) &data.serverAdress, sizeof(data.serverAdress)) < 0) {
          perror("ERROR on binding");
          exit(1);
       }
}

void TCPConnection::ClientsListening(TCPEntities& data)
{
    listen(data.socketDescriptor,5);
       data.clientLenght = sizeof(data.clientAdress);
}

void TCPConnection::ActualClientConnectionAccept(TCPEntities& data)
{
    data.newSocketDescriptor = accept(data.socketDescriptor, (struct sockaddr *)&data.clientAdress, &data.clientLenght);
       if (data.newSocketDescriptor < 0) {
          perror("ERROR on accept");
          exit(1);
       }
}

void TCPConnection::CommunicateStart(TCPEntities& data)
{
    bzero(data.buffer,256);
    data.dataStorage = read(data.newSocketDescriptor, data.buffer, 255);
       if (data.dataStorage < 0) {
          perror("ERROR reading from socket");
          exit(1);
       }
    std::cout << "message:" << data.buffer << std::endl;
}

void TCPConnection::ClientResponseWriting(TCPEntities& data, ServerResult& result)
{
    std::string clientAnswerString = "Result of " + result.operationName + " = " + std::to_string(result.operationResult);
    strcpy(data.buffer, clientAnswerString.c_str());
    data.dataStorage = write(data.newSocketDescriptor,data.buffer,50);
       if (data.dataStorage < 0) {
          perror("ERROR writing to socket");
          exit(1);
       }
}




