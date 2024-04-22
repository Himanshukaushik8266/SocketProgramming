#ifndef SERVERFUNCTIONALITIES_H
#define SERVERFUNCTIONALITIES_H
#include "../NetworkUtilities/Utitlies.h"
#include <iostream>
#include <unistd.h>
#include <thread>

struct AcceptedSocket
{
    int acceptedSocketFD;
    sockaddr_in address;
    int error;
    bool acceptedSuccessfully;
};


void receiveAndPrintIncomingData(int socketFD);

void startAcceptingIncomingConnections(int serverSocketFD);

AcceptedSocket *acceptIncomingConnection(int serverSocketFD);

#endif // SERVERFUNCTIONALITIES_H
