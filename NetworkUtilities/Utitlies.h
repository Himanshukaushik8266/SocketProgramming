#ifndef SOCKETUTILITIES_SOCKETUTILITIES_H
#define SOCKETUTILITIES_SOCKETUTILITIES_H

#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>

struct sockaddr_in *createIPv4Address(const char *ip, int port);

int createTCPIpv4Socket();

#endif // SOCKETUTILITIES_SOCKETUTILITIES_H
