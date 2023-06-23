#pragma once

#include "IRequestHandler.h"
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
	RoomManager m_roomManager;
	RequestHandlerFactory& m_handlerFactory;
};