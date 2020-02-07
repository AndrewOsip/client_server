#include "IConnection/Connection/Connection.h"

//Connection::Connection(int networkType, int port, hostent* host): mPortNumber{port} {}


void Connection::socketInit(int networkType, int port, hostent *host)
{
    this->mHost = host;
    this->mNetworkType = networkType;
    this->mPortNumber = port;
    mSocketDescriptor = socket(AF_INET, mNetworkType, 0);

       if (mSocketDescriptor < 0) {
          perror("ERROR opening socket");
          exit(1);
       }

       if (mHost == nullptr) {
          fprintf(stderr,"ERROR, no such host\n");
          exit(0);
       }

       bzero((char *) &mServerAdress, sizeof(mServerAdress));

       mServerAdress.sin_family = AF_INET;
       bcopy((char *)mHost->h_addr, (char *)&mServerAdress.sin_addr.s_addr, mHost->h_length);
       mServerAdress.sin_port = htons(mPortNumber);

       if (connect(mSocketDescriptor, (struct sockaddr*)&mServerAdress, sizeof(mServerAdress)) < 0) {
             perror("ERROR connecting");
             exit(1);
          }
}

void Connection::messageFromUser(InitialEntities& initialData)
{
    strcpy(mBuffer, initialData.JSONAnswer.c_str());
    std::cout << "message: " << mBuffer << std::endl;
}

void Connection::messageToServerSending()
{
       if (write(mSocketDescriptor, mBuffer, strlen(mBuffer)) < 0) {
          perror("ERROR writing to socket");
          exit(1);
       }
}

void Connection::serverResponseReading()
{
    bzero(mBuffer,2048);

       if (read(mSocketDescriptor, mBuffer, 2047) < 0) {
          perror("ERROR reading from socket");
          exit(1);
       }
       std::cout << mBuffer << std::endl;
}

