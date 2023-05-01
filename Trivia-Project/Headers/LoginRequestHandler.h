#pragma once
#include "IRequestHandler.h"
#include <fstream>

class LoginRequestHandler : public IRequestHandler
{
public:
    bool isRequestRelevant(RequestInfo info) override;
	RequestResult handleRequest(RequestInfo info) override;
};