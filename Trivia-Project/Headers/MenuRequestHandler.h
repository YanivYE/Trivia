#pragma once

#include "IRequestHandler.h";

class MenuRequestHandler : public IRequestHandler
{
public:
	MenuRequestHandler(); // ctor

	bool isRequestRelevant(RequestInfo info) override; // is request relevant
	RequestResult handleRequest(RequestInfo info) override; // hand request

private:

};
