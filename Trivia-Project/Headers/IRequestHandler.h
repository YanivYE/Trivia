#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include "..\Headers\Utilities.h"

// Forward declaration of IRequestHandler
class IRequestHandler;

// request info struct
struct RequestInfo
{
	int requestId;
	time_t receivalTime;
	Buffer buffer;
};

// request result struct
struct RequestResult
{
	IRequestHandler* newHandler;
	Buffer response;
};

class IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo info) = 0; // is request relevant
	virtual RequestResult handleRequest(RequestInfo info) = 0; // handle request
};