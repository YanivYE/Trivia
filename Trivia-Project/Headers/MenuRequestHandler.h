#pragma once

#include "IRequestHandler.h";

class MenuRequestHandler : public IRequestHandler
{
public:
	MenuRequestHandler();

	bool isRequestRelevant(RequestInfo info) override;
	RequestResult handleRequest(RequestInfo info) override;

private:

};
