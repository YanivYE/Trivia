#include "../Headers/LoginRequestHandler.h"

LoginRequestHandler::LoginRequestHandler()
{
}

bool LoginRequestHandler::isRequestRelevant(RequestInfo info)
{
	return (info.requestId == Login) || (info.requestId == SignUp);
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo info)
{
	RequestResult result = RequestResult();
	std::vector<unsigned char> bufBytes;
	Buffer buf = Buffer();

	bufBytes.push_back(info.requestId);
	bufBytes.push_back(info.buffer._bytes.size());
	bufBytes.insert(bufBytes.end(), info.buffer._bytes.begin(), info.buffer._bytes.end());
	
	buf._bytes = bufBytes;

	result.response = buf;
	result.newHandler = nullptr;

	return result;
}