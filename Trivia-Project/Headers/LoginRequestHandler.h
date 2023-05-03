#pragma once
#include "IRequestHandler.h"
#include <fstream>
#include <iostream>
#include <vector>

class LoginRequestHandler : public IRequestHandler
{
public:
	LoginRequestHandler();

    bool isRequestRelevant(RequestInfo info) override;
	RequestResult handleRequest(RequestInfo info) override;
};