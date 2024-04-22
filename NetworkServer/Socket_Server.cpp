#include "ServerFunctionalities.h"

int main()
{
    int serverSocketFD = createTCPIpv4Socket();
    auto serverAddress = createIPv4Address("", 2000);

    int result = bind(serverSocketFD, reinterpret_cast<sockaddr *>(serverAddress), sizeof(sockaddr_in));
    if (result == 0)
    {
        std::cout << "Socket was bound successfully" << std::endl;
    }

    int listenResult = listen(serverSocketFD, 10);

    startAcceptingIncomingConnections(serverSocketFD);

    shutdown(serverSocketFD, SHUT_RDWR);
    return 0;
}
