#include "ServerFunctionalities.h"
AcceptedSocket acceptedSockets[10];
int acceptedSocketsCount = 0;

void startAcceptingIncomingConnections(int serverSocketFD)
{
    while (true)
    {
        auto clientSocket = acceptIncomingConnection(serverSocketFD);
        acceptedSockets[acceptedSocketsCount++] = *clientSocket;

        std::thread receiveThread(receiveAndPrintIncomingData, clientSocket->acceptedSocketFD);
        receiveThread.detach();
    }
}

void receiveAndPrintIncomingData(int socketFD)
{
    char buffer[1024];

    while (true)
    {
        ssize_t amountReceived = recv(socketFD, buffer, 1024, 0);

        if (amountReceived > 0)
        {
            buffer[amountReceived] = 0;
            std::cout << "Received: " << buffer << std::endl;

            for (int i = 0; i < acceptedSocketsCount; i++)
            {
                if (acceptedSockets[i].acceptedSocketFD != socketFD)
                {
                    send(acceptedSockets[i].acceptedSocketFD, buffer, strlen(buffer), 0);
                }
            }
        }

        if (amountReceived <= 0)
        {
            break;
        }
    }

    close(socketFD);
}

AcceptedSocket *acceptIncomingConnection(int serverSocketFD)
{
    sockaddr_in clientAddress;
    socklen_t clientAddressSize = sizeof(sockaddr_in);
    int clientSocketFD = accept(serverSocketFD, reinterpret_cast<sockaddr *>(&clientAddress), &clientAddressSize);

    auto acceptedSocket = new AcceptedSocket{};
    acceptedSocket->address = clientAddress;
    acceptedSocket->acceptedSocketFD = clientSocketFD;
    acceptedSocket->acceptedSuccessfully = clientSocketFD > 0;

    if (!acceptedSocket->acceptedSuccessfully)
    {
        acceptedSocket->error = clientSocketFD;
    }

    return acceptedSocket;
}