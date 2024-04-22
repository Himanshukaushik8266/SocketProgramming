#include <cxxtest/TestSuite.h>
#include "../NetworkUtilities/Utitlies.h"
#include "../NetworkServer/ServerFunctionalities.h"
#include "../NetworkClient/ClientFunctionalities.h"

class MyTestSuite : public CxxTest::TestSuite {
public:
    void testCreateIPv4Address() {
        // Test createIPv4Address function
        sockaddr_in* address = createIPv4Address("127.0.0.1", 8080);
        TS_ASSERT(address != nullptr);
        delete address;
    }

    void testCreateTCPIpv4Socket() {
        // Test createTCPIpv4Socket function
        int socketFD = createTCPIpv4Socket();
        TS_ASSERT(socketFD >= 0);
        close(socketFD);
    }

    void testAcceptIncomingConnection() {
        // Test acceptIncomingConnection function
        int serverSocketFD = createTCPIpv4Socket();
        auto serverAddress = createIPv4Address("", 2000);
        bind(serverSocketFD, reinterpret_cast<sockaddr *>(serverAddress), sizeof(sockaddr_in));
        listen(serverSocketFD, 10);

        AcceptedSocket* acceptedSocket = acceptIncomingConnection(serverSocketFD);
        TS_ASSERT(acceptedSocket != nullptr);

        close(acceptedSocket->acceptedSocketFD);
        delete acceptedSocket;
        close(serverSocketFD);
        delete serverAddress;
    }
};
//cxxtestgen --error-printer -o TestRunner.cpp Tests.cpp ---------> testrunner.cpp for printing test result on the terminal
// g++ -o tests TestRunner.cpp ../NetworkUtilities/Utitlies.cpp ../NetworkServer/ServerFunctionalities.cpp ../NetworkClient/ClientFunctionalities.cpp -std=c++11 -pthread-------------------------> for creating test object file
