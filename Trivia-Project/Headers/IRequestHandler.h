#pragma once

#include <iostream>
#include <vector>
#include <ctime>

// Forward declaration of IRequestHandler
class IRequestHandler;

struct Buffer
{
	std::vector<unsigned char> bytes;
};

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

enum code{Login = 1, SignUp, Error};

class IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo info) = 0;
	virtual RequestResult handleRequest(RequestInfo info) = 0;
};