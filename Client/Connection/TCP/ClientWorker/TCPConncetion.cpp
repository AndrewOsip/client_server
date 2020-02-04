#include "Connection/TCP/TCPEntities/TCPEntities.h"
#include "Connection/TCP/ClientWorker/TCPConnection.h"

void TCPConnection::SocketPointCreate(TCPEntities& data)
{
    data.socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

       if (data.socketDescriptor < 0) {
          perror("ERROR opening socket");
          exit(1);
       }

       if (data.server == nullptr) {
          fprintf(stderr,"ERROR, no such host\n");
          exit(0);
       }

       bzero((char *) &data.serverAdress, sizeof(data.serverAdress));
       data.serverAdress.sin_family = AF_INET;
       bcopy((char *)data.server->h_addr, (char *)&data.serverAdress.sin_addr.s_addr, data.server->h_length);
       data.serverAdress.sin_port = htons(data.portNumber);
}

void TCPConnection::ServerConnecting(TCPEntities& data)
{
    if (connect(data.socketDescriptor, (struct sockaddr*)&data.serverAdress, sizeof(data.serverAdress)) < 0) {
          perror("ERROR connecting");
          exit(1);
       }
}

void TCPConnection::MessageFromUser(TCPEntities& data, InitialEntities& initialData)
{
    strcpy(data.buffer, initialData.JSONAnswer.c_str());
    std::cout << "message: " << data.buffer << std::endl;
}

void TCPConnection::MessageToServerSending(TCPEntities& data)
{
    data.dataStorage = write(data.socketDescriptor, data.buffer, strlen(data.buffer));

       if (data.dataStorage < 0) {
          perror("ERROR writing to socket");
          exit(1);
       }
}

void TCPConnection::ServerResponseReading(TCPEntities& data)
{
    bzero(data.buffer,2048);
       data.dataStorage = read(data.socketDescriptor, data.buffer, 2047);

       if (data.dataStorage < 0) {
          perror("ERROR reading from socket");
          exit(1);
       }
       std::cout << data.buffer << std::endl;
}
