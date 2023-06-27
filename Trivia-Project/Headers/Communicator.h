#pragma once

#include <WinSock2.h>
#include <iostream>
#include <map>
#include <string>
#include <exception>
#include <sstream>
#include <thread>
#include "LoginRequestHandler.h"
#include "RequestHandlerFactory.h"
#include "JsonResponsePacketSerializer.h"
#include "JsonRequestPacketDeserializer.h"

#define MAX_READ 1024
#define ZERO_ASCII '0'
#define DATA_LENGTH 4
#define END_OF_STRING_LEN 1
#define END_OF_STRING '\0'
#define BYTE_BIT_LENGTH 8

class Communicator
{
public:
	// get instance of communicator
	static Communicator& getInstance(RequestHandlerFactory* factory) {
		static Communicator instance(factory);
		return instance;
	}

	void startHandleRequests(int port); // start handling requests to connect from client
	void bindAndListen(int port); // bind and listen server to port
	void handleNewClient(SOCKET m_clientSocket); // handle new client
	void acceptClient(); // accept new client

private:
	SOCKET m_serverSocket; // server socket
	std::map<SOCKET, IRequestHandler*> m_clients; // clients sockets and handlers
	RequestHandlerFactory* m_handlerFactory; // request handler

	// ctor
	Communicator(RequestHandlerFactory* factory)
		: m_handlerFactory(factory)
	{
		// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
		// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
		m_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		m_handlerFactory = factory;

		if (m_serverSocket == INVALID_SOCKET)
			throw std::exception(__FUNCTION__ " - socket");
	}

	// dtor
	~Communicator()
	{
		try
		{
			// the only use of the destructor should be for freeing 
			// resources that was allocated in the constructor
			closesocket(m_serverSocket);
		}
		catch (...) {}
	}

	void sendErrorResponse(SOCKET m_clientSocket, ErrorResponse errorResponse); // send error response

	RequestInfo getInfo(SOCKET m_clientSocket); // get info from client

	std::string binaryToAsciiInt(std::string binary_string); // convert binrary string to int by ascii
	void write(const SOCKET sc, const std::string message); // write messages to client
	std::string read(const SOCKET sc, const int bytesNum, const int flags); // read messages from client
};
