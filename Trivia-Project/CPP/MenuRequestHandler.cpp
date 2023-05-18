#include "../Headers/MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler()
{
}

bool MenuRequestHandler::isRequestRelevant(RequestInfo info)
{
	return false;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo info)
{
	return RequestResult();
}
