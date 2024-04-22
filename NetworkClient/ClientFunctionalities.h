#ifndef CLIENTFUNCTIONALITIES_H
#define CLIENTFUNCTIONALITIES_H
#include <iostream>
#include <unistd.h>
#include <thread>
#include <sstream>
#include <cstring>
#include "../NetworkUtilities/Utitlies.h"

void readConsoleEntriesAndSendToServer(int socketFD);
void startListeningAndPrintMessagesOnNewThread(int fd);
void listenAndPrint(int socketFD);

#endif // CLIENTFUNCTIONALITIES_H
