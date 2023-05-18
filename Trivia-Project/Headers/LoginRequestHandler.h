#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "MenuRequestHandler.h"
#include "Structs.h"
#include <fstream>
#include <iostream>
#include <vector>

class LoginRequestHandler : public IRequestHandler
{
public:
	LoginRequestHandler(RequestHandlerFactory* factory);

    bool isRequestRelevant(RequestInfo info) override; // is login request 
	RequestResult handleRequest(RequestInfo info) override; // handle login request

	RequestResult login(RequestInfo info);
	RequestResult signup(RequestInfo info);
private:
	RequestHandlerFactory& m_handlerFactory;
};