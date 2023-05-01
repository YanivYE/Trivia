#include "../Headers/LoginRequestHandler.h"

bool LoginRequestHandler::isRequestRelevant(RequestInfo info)
{
	return (info.requestId == Login) || (info.requestId == SignUp);
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo info)
{
	// TODO: SERIALIZE
	return RequestResult();
}