#pragma once

#include "IRequestHandler.h"
#include "RoomManager.h"
#include "Room.h"

class RequestHandlerFactory;

class RoomMemberRequestHandler : public IRequestHandler
{
public:
	bool isRequestRelevant(RequestInfo info);
	RequestResult handleRequest(RequestInfo info);
	RequestResult leaveRoom(RequestInfo info);
	RequestResult getRoomState(RequestInfo info);

private:
	Room m_room;
	LoggedUser m_user;
	RequestHandlerFactory& m_handlerFactory;
	RoomManager m_roomManager;

};