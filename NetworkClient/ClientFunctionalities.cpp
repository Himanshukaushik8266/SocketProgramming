#include "ClientFunctionalities.h"

void readConsoleEntriesAndSendToServer(int socketFD)
{
    char name[1024];
    std::cout << "Please enter your name: ";
    std::cin.getline(name, 1024);

    char buffer[1024];
    while (true)
    {
        std::cout << "Type and we will send (type 'exit' to quit): ";
        std::cin.getline(buffer, 1024);

        if (strcmp(buffer, "exit") == 0)
        {
            break;
        }

        std::stringstream ss;
        ss << name << ": " << buffer;
        std::string message = ss.str();

        ssize_t amountWasSent = send(socketFD, message.c_str(), message.size(), 0);
    }
}

void startListeningAndPrintMessagesOnNewThread(int socketFD)
{
    std::thread listenThread(listenAndPrint, socketFD);
    listenThread.detach();
}

void listenAndPrint(int socketFD)
{
    char buffer[1024];

    while (true)
    {
        ssize_t amountReceived = recv(socketFD, buffer, 1024, 0);

        if (amountReceived > 0)
        {
            buffer[amountReceived] = 0;
            std::cout << "Response was: " << buffer << std::endl;
        }

        if (amountReceived <= 0)
        {
            break;
        }
    }

    close(socketFD);
}
