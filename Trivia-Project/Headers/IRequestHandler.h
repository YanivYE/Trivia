#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include "..\Headers\Structs.h"

// Forward declaration of IRequestHandler
class IRequestHandler;

struct RequestInfo
{
	int requestId;
	time_t receivalTime;
	Buffer buffer;
};

struct RequestResult
{
	IRequestHandler* newHandler;
	Buffer response;
};

class IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo info) = 0;
	virtual RequestResult handleRequest(RequestInfo info) = 0;
};