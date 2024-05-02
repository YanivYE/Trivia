#include "../Headers/RoomMemberRequestHandler.h"

RoomMemberRequestHandler::RoomMemberRequestHandler(RequestHandlerFactory* requestHandlerFactory, LoggedUser user, Room* room)
{
    this->m_handleFactory = requestHandlerFactory;
    this->m_roomManager = &requestHandlerFactory->getRoomManager();
    this->m_user = user;
    this->m_room = room;
}

bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo info)
{
    return info.requestId == LeaveRoom || info.requestId == GetRoomState;
}

RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo info)
{
    if (isRequestRelevant(info))
    {
        switch (info.requestId)
        {
        case LeaveRoom:
            return leaveRoom(info);
        case GetRoomState:
            return getRoomState(info);
        }
    }
}

RequestResult RoomMemberRequestHandler::leaveRoom(RequestInfo info)
{
	RequestResult result;
	JsonResponsePacketSerializer serializer;
	int returnCode = 0;

	for (int i = 0; i < this->m_room->getAllUsers().size(); i++)
	{
		LoggedUser user(this->m_room->getAllUsers()[i]);

		try
		{
			// try to remove user
			returnCode = this->m_room->removeUser(user);

			if (returnCode == LeaveRoom)
			{
				result.newHandler = this->m_handleFactory->createMenuRequestHandlers(user);
			}
			else
			{
				result.newHandler = this->m_handleFactory->createRoomMemberRequestHandler(user, this->m_room);

				ErrorResponse errResponse;
				errResponse._data = "Error! Couldn't remove user from room!";

				result.response = serializer.serializeResponse(errResponse);
			}

			LeaveRoomResponse leaveRoom;
			leaveRoom._status = returnCode;

			result.response = serializer.serializeResponse(leaveRoom);
		}
		catch (std::exception& e)
		{
			result.newHandler = this->m_handleFactory->createRoomMemberRequestHandler(user, this->m_room);

			ErrorResponse errResponse;
			errResponse._data = "Error! Couldn't remove user from room!";

			result.response = serializer.serializeResponse(errResponse);
		}
	}

	return result;
}

RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo info)
{
	RequestResult result;
	JsonResponsePacketSerializer serializer;
	int returnCode = 0;

	try
	{
		// try to get room state
		returnCode = this->m_roomManager->getRoomState(this->m_room->getId());

		GetRoomStateResponse getRoomState;
		getRoomState._status = returnCode;
		getRoomState._hasGameBegun = returnCode == inGame ? true : false;
		getRoomState._answerTimeout = this->m_room->getRoomData().timePerQuestion;
		getRoomState._questionCount = this->m_room->getRoomData().numOfQuestionsInGame;
		getRoomState._maxPlayers = this->m_room->getRoomData().maxPlayers;
		getRoomState._players = this->m_room->getAllUsers();

		if (getRoomState._hasGameBegun)
		{
			result.newHandler = this->m_handleFactory->createGameRequestHandler(this->m_user, this->m_handleFactory->getGameManager().getGameByID(this->m_room->getId()));
			// add a game played in the DB
			this->m_handleFactory->getGameManager().getDataBase()->addNewGame(this->m_user.getUsername());
		}
		else
		{
			result.newHandler = this->m_handleFactory->createRoomMemberRequestHandler(this->m_user, this->m_room);
		}

		result.response = serializer.serializeResponse(getRoomState);
	}
	catch (std::exception& e)
	{
		result.newHandler = this->m_handleFactory->createRoomMemberRequestHandler(this->m_user, this->m_room);

		ErrorResponse errResponse;
		errResponse._data = "Error! Couldn't get room state!";

		result.response = serializer.serializeResponse(errResponse);
	}
	

	return result;
}
