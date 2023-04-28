#pragma once

#include <WinSock2.h>
#include <iostream>
#include <map>
#include "IRequestHandler.h"

class Communicator
{
public:
	void startHandleRequests();
	void bindAndListen(int port);
	void handleNewClient(SOCKET m_serverSocket);
private:
	SOCKET m_serverSocket;
	std::map<SOCKET, IRequestHandler*> m_clients;
};