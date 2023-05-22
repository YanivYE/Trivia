#include "../Headers/MenuRequestHandler.h"

/*
* Function is a ctor for MenuRequestHandler
* Input: none
* Output: none
*/
MenuRequestHandler::MenuRequestHandler()
{
}

/*
* Function checks if request is relevant
* Input: info - the request info
* Output: false
*/
bool MenuRequestHandler::isRequestRelevant(RequestInfo info)
{
	return false;
}

/*
* Function handles requrst
* Input: info - the request info
* Output: request result
*/
RequestResult MenuRequestHandler::handleRequest(RequestInfo info)
{
	return RequestResult();
}
