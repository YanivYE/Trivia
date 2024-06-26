#include "..\Headers\RoomAdminRequestHandler.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(RequestHandlerFactory* requestHandlerFactory, LoggedUser user, Room* room)
{
    this->m_handleFactory = requestHandlerFactory;
    this->m_roomManager = &requestHandlerFactory->getRoomManager();
    this->m_user = user;
    this->m_room = room;
}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo info)
{
    return info.requestId == CloseRoom || info.requestId == StartGame || info.requestId == GetRoomState;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo info)
{
    if (isRequestRelevant(info))
    {
        switch (info.requestId)
        {
        case CloseRoom:
            return closeRoom(info);
        case StartGame:
            return startGame(info);
        case GetRoomState:
            return getRoomState(info);
        }
    }

}

RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo info)
{
	RequestResult result;
	JsonResponsePacketSerializer serializer;
	int returnCode = 0;
	std::vector<std::string> users = this->m_room->getAllUsers();

	this->m_room->closeRoom();
	this->m_roomManager->deleteRoom(this->m_room->getId());
	for (std::string username : users)
	{
		LoggedUser user(username);

		try
		{
			// try to remove user
			returnCode = this->m_room->removeUser(user);

			if (returnCode == LeaveRoom)
			{
				result.newHandler = this->m_handleFactory->createMenuRequestHandlers(user);

				LeaveRoomResponse leaveRoom;
				leaveRoom._status = returnCode;

				result.response = serializer.serializeResponse(leaveRoom);
			}
			else
			{
				result.newHandler = this->m_handleFactory->createRoomAdminRequestHandler(user, this->m_room);

				ErrorResponse errResponse;
				errResponse._data = "Error! Couldn't remove user from room!";

				result.response = serializer.serializeResponse(errResponse);
			}
		}
		catch (std::exception& e)
		{
			result.newHandler = this->m_handleFactory->createRoomAdminRequestHandler(user, this->m_room);

			ErrorResponse errResponse;
			errResponse._data = "Error! Couldn't remove user from room!";

			result.response = serializer.serializeResponse(errResponse);
		}
	}

	return result;
    
}

RequestResult RoomAdminRequestHandler::startGame(RequestInfo info)
{
	RequestResult result;
	JsonResponsePacketSerializer serializer;
	int returnCode = 0;

	try
	{
		// try to start game
		returnCode = this->m_room->startGame();

		if (returnCode == StartGame)
		{
			Game* game = this->m_handleFactory->getGameManager().createGame(this->m_room);
			result.newHandler = this->m_handleFactory->createGameRequestHandler(this->m_user, game);
			// add a game played in the DB
			this->m_handleFactory->getGameManager().getDataBase()->addNewGame(this->m_user.getUsername());

			StartGameResponse startGame;
			startGame._status = returnCode;

			result.response = serializer.serializeResponse(startGame);
		}
		else
		{
			result.newHandler = this->m_handleFactory->createRoomAdminRequestHandler(this->m_user, this->m_room);

			ErrorResponse errResponse;
			errResponse._data = "Error! Couldn't start game!";

			result.response = serializer.serializeResponse(errResponse);
		}
	}
	catch (std::exception& e)
	{
		result.newHandler = this->m_handleFactory->createRoomAdminRequestHandler(this->m_user, this->m_room);

		ErrorResponse errResponse;
		errResponse._data = "Error! Couldn't start game!";

		result.response = serializer.serializeResponse(errResponse);
	}
	

	return result;
}

RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo info)
{
	RequestResult result;
	JsonResponsePacketSerializer serializer;
	int returnCode = 0;

	try
	{
		// try to get room state
		returnCode = this->m_roomManager->getRoomState(this->m_room->getId());

		result.newHandler = this->m_handleFactory->createRoomAdminRequestHandler(this->m_user, this->m_room);;

		GetRoomStateResponse getRoomState;
		getRoomState._status = returnCode;
		getRoomState._hasGameBegun = returnCode == inGame ? true : false;
		getRoomState._isActive = returnCode == notActive ? false : true;
		if (getRoomState._isActive)
		{
			getRoomState._answerTimeout = this->m_room->getRoomData().timePerQuestion;
			getRoomState._questionCount = this->m_room->getRoomData().numOfQuestionsInGame;
			getRoomState._maxPlayers = this->m_room->getRoomData().maxPlayers;
			getRoomState._players = this->m_room->getAllUsers();
		}

		result.response = serializer.serializeResponse(getRoomState);
	}
	catch (std::exception& e)
	{
		result.newHandler = this->m_handleFactory->createRoomAdminRequestHandler(this->m_user, this->m_room);

		ErrorResponse errResponse;
		errResponse._data = "Error! Couldn't get room state!";

		result.response = serializer.serializeResponse(errResponse);
	}
	

	return result;
}
