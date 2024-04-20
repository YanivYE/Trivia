#pragma once

#include "IRequestHandler.h"
#include "RoomManager.h"
#include "LoginRequestHandler.h"
#include "Utilities.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class RoomAdminRequestHandler : public IRequestHandler
{
public:
	RoomAdminRequestHandler(RequestHandlerFactory* requestHandlerFactory, LoggedUser user, Room& room);

	bool isRequestRelevant(RequestInfo info) override;
	RequestResult handleRequest(RequestInfo info) override;
	RequestResult closeRoom(RequestInfo info);
	RequestResult startGame(RequestInfo info);
	RequestResult getRoomState(RequestInfo info);
	
private:
	Room m_room;
	LoggedUser m_user;
	RoomManager* m_roomManager;
	RequestHandlerFactory* m_handleFactory;

};