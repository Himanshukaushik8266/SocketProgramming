#include "Utitlies.h"

struct sockaddr_in *createIPv4Address(const char *ip, int port)
{
    auto address = new sockaddr_in{};
    std::memset(address, 0, sizeof(sockaddr_in));
    address->sin_family = AF_INET;
    address->sin_port = htons(port);

    if (ip[0] == '\0')
    {
        address->sin_addr.s_addr = INADDR_ANY;
    }
    else
    {
        inet_pton(AF_INET, ip, &address->sin_addr);
    }

    return address;
}

int createTCPIpv4Socket()
{
    return socket(AF_INET, SOCK_STREAM, 0);
}
