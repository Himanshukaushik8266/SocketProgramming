#include "ClientFunctionalities.h"

int main()
{
    int socketFD = createTCPIpv4Socket();
    auto address = createIPv4Address("127.0.0.1", 2000);

    int result = connect(socketFD, reinterpret_cast<sockaddr *>(address), sizeof(sockaddr_in));
    if (result == 0)
    {
        std::cout << "Connection was successful" << std::endl;
    }

    startListeningAndPrintMessagesOnNewThread(socketFD);

    readConsoleEntriesAndSendToServer(socketFD);

    close(socketFD);
    return 0;
}
