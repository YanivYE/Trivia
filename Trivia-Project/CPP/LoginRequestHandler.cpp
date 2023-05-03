#include "../Headers/LoginRequestHandler.h"

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
	bufBytes.push_back(info.buffer.bytes.size());
	bufBytes.insert(bufBytes.end(), info.buffer.bytes.begin(), info.buffer.bytes.end());
	
	buf.bytes = bufBytes;

	result.response = buf;
	result.newHandler = nullptr;

	return result;
}