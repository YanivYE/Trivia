#pragma once

#include <WinSock2.h>
#include <iostream>
#include <map>
#include <string>
#include <exception>
#include <thread>
#include "LoginRequestHandler.h"


class Communicator
{
public:
	Communicator();
	~Communicator();

	void startHandleRequests(int port);
	void bindAndListen(int port);
	void handleNewClient(SOCKET m_clientSocket);
	void acceptClient();
private:
	SOCKET m_serverSocket;
	std::map<SOCKET, IRequestHandler*> m_clients;

	void write(const SOCKET sc, const std::string message);
	std::string read(const SOCKET sc, const int bytesNum, const int flags);
};