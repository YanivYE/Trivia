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
	Communicator(); // contructor
	~Communicator(); // desstructor

	void startHandleRequests(int port); // start handling requests to connect from client
	void bindAndListen(int port); // bind and listen server to port
	void handleNewClient(SOCKET m_clientSocket); // handle new client
	void acceptClient(); // accept new client

private:
	SOCKET m_serverSocket;
	std::map<SOCKET, IRequestHandler*> m_clients;
	
	void write(const SOCKET sc, const std::string message); // write messages to client
	std::string read(const SOCKET sc, const int bytesNum, const int flags); // read messages from client
};