#include "IConnection/Connection/Connection.h"

void Connection::socketInit(int portNumber, int networkType) {

    this->mPortNumber = portNumber;
    this->mNetworkType = networkType;
    mSocketDescriptor = socket(AF_INET, mNetworkType, 0);
       if (mSocketDescriptor < 0) {
          perror("ERROR opening socket");
          exit(1);
       }

    bzero((char *) &mServerAdress, sizeof(mServerAdress));
    mServerAdress.sin_family = AF_INET;
    mServerAdress.sin_addr.s_addr = INADDR_ANY;
    mServerAdress.sin_port = htons(mPortNumber);

    if (bind(mSocketDescriptor, (struct sockaddr *) &mServerAdress, sizeof(mServerAdress)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(mSocketDescriptor,5);
    mClientLenght = sizeof(mClientAdress);
    mNewSocketDescriptor = accept(mSocketDescriptor, (struct sockaddr *)&mClientAdress, &mClientLenght);
    if (mNewSocketDescriptor < 0) {
        perror("ERROR on accept");
        exit(1);
    }
}

void Connection::communicateStart()
{
    bzero(mBuffer,1024);
    mDataStorage = read(mNewSocketDescriptor, mBuffer, 1023);
       if (mDataStorage < 0) {
          perror("ERROR reading from socket");
          exit(1);
       }
    std::cout << "message:" << mBuffer << std::endl;
}

void Connection::clientResponseWriting(ServerResult& result)
{
    std::string clientAnswerString = "Result of " + result.operationName + " = " + std::to_string(result.operationResult);
    strcpy(mBuffer, clientAnswerString.c_str());
       if (write(mNewSocketDescriptor,mBuffer,50) < 0) {
          perror("ERROR writing to socket");
          exit(1);
       }
    strcpy(result.buffer, clientAnswerString.c_str());
}


