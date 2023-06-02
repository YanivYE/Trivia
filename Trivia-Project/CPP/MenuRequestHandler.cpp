#include "../Headers/MenuRequestHandler.h"

/*
* Function is a ctor for MenuRequestHandler
* Input: none
* Output: none
*/
MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory* factory, LoggedUser user)
{
	this->m_user = user;
	this->m_handlerFactory = factory;
	this->m_roomManager = &(factory->getRoomManager());
	this->m_statisticsManager = &(factory->getStatisticsManager());
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
