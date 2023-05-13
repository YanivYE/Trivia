#pragma once
#include "IRequestHandler.h"
#include <fstream>
#include <iostream>
#include <vector>

class LoginRequestHandler : public IRequestHandler
{
public:
	LoginRequestHandler(); // empty ctor

    bool isRequestRelevant(RequestInfo info) override; // is login request 
	RequestResult handleRequest(RequestInfo info) override; // handle login request
};