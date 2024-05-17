#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "MenuRequestHandler.h"
#include "Communicator.h"
#include "Utilities.h"
#include <fstream>
#include <iostream>
#include <vector>

class RequestHandlerFactory;

class LoginRequestHandler : public IRequestHandler
{
public:
	LoginRequestHandler(); // empty ctor
	LoginRequestHandler(RequestHandlerFactory* factory); // ctor with request handler factory

    bool isRequestRelevant(RequestInfo info) override; // is login request 
	RequestResult handleRequest(RequestInfo info) override; // handle login request

	RequestResult login(RequestInfo info); // login with info
	RequestResult signup(RequestInfo info); // sign up with info
private:
	RequestHandlerFactory* m_handlerFactory; // request handler factory
};