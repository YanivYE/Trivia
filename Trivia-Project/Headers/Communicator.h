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
	Communicator(RequestHandlerFactory* factory); // contructor
	~Communicator(); // desstructor

	void startHandleRequests(int port); // start handling requests to connect from client
	void bindAndListen(int port); // bind and listen server to port
	void handleNewClient(SOCKET m_clientSocket); // handle new client
	void acceptClient(); // accept new client

private:
	SOCKET m_serverSocket; // server socket
	std::map<SOCKET, IRequestHandler*> m_clients; // clients sockets and handlers
	RequestHandlerFactory* m_handlerFactory;

	void handleLoginRequest(SOCKET m_clientSocket); // handle login request
	void sendLoginResponse(SOCKET m_clientSocket); // send login response
	void handleSignUpRequest(SOCKET m_clientSocket); // handle sign up request
	void sendSignUpResponse(SOCKET m_clientSocket); // send signup response
	void sendErrorResponse(SOCKET m_clientSocket, ErrorResponse errorResponse); // send error response

	RequestInfo getInfo(SOCKET m_clientSocket);

	std::string binaryToAsciiInt(std::string binary_string); // convert binrary string to int by ascii
	void write(const SOCKET sc, const std::string message); // write messages to client
	std::string read(const SOCKET sc, const int bytesNum, const int flags); // read messages from client
};