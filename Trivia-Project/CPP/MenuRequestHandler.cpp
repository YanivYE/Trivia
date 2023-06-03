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
	return (info.requestId == CreateRoom) || (info.requestId == GetRooms) || (info.requestId == GetPlayersInRoom)
		|| (info.requestId == JoinRoom) || (info.requestId == GetPersonalStats) || (info.requestId == Logout);
}

/*
* Function gets a request info and handles request
* Input: info - info of request
* Output: request handle result
*/
RequestResult MenuRequestHandler::handleRequest(RequestInfo info)
{
	RequestResult requestResult;

	if (info.requestId == CreateRoom)
	{
		return createRoom(info);
	}
	else if (info.requestId == GetRooms)
	{
		return getRooms(info);
	}
	else if (info.requestId == GetPlayersInRoom)
	{
		return getPlayersInRoom(info);
	}
	else if (info.requestId == JoinRoom)
	{
		return joinRoom(info);
	}
	else if (info.requestId == GetPersonalStats)
	{
		return getPersonalStats(info);
	}
	else if (info.requestId == Logout)
	{
		return signout(info);
	}
	
	return requestResult;
}

RequestResult MenuRequestHandler::returnError(RequestResult& result, std::string errorMsg, JsonResponsePacketSerializer serializer)
{
	ErrorResponse errResponse;
	errResponse._data = errorMsg;

	result.response = serializer.serializeResponse(errResponse);
	return result;
}

RequestResult MenuRequestHandler::createRoom(RequestInfo info)
{
	CreateRoomRequest createRoomRequest;
	RequestResult result;
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;
	int returnCode = 0;

	// try to get create room request
	try
	{
		// deserialize create room request
		createRoomRequest = deserializer.deserializeCreateRoomRequest(info.buffer);
	}
	catch (...)
	{
		return returnError(result, "Error! Couldn't parse login request", serializer);
	}

	try
	{
		RoomData roomData;

		roomData.name = createRoomRequest.roomName;
		roomData.maxPlayers = createRoomRequest.maxUsers;
		roomData.numOfQuestionsInGame = createRoomRequest.questionCount;
		roomData.timePerQuestion = createRoomRequest.answerTimeout;
		
		// try to create room
		returnCode = this->m_handlerFactory->getRoomManager().createRoom(this->m_user, roomData);

		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(m_user);
		}
		else
		{
			return returnError(result, "Error! Couldn't create room!", serializer);
		}

		CreateRoomResponse createRoomResponse;
		createRoomResponse._status = returnCode;

		result.response = serializer.serializeResponse(createRoomResponse);
	}
	catch (std::exception& e)
	{
		return returnError(result, "Error! Couldn't get rooms!", serializer);
	}

	return result;
}

RequestResult MenuRequestHandler::getRooms(RequestInfo info)
{
	RequestResult result;
	int returnCode = 1;
	JsonResponsePacketSerializer serializer;

	try
	{
		GetRoomsResponse getRoomsResponse;

		getRoomsResponse._rooms = this->m_handlerFactory->getRoomManager().getRooms();

		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(m_user);
		}
		else
		{
			return returnError(result, "Error! Couldn't get rooms!", serializer);
		}

		getRoomsResponse._status = returnCode;

		result.response = serializer.serializeResponse(getRoomsResponse);
	}
	catch (std::exception& e)
	{
		return returnError(result, "Error! User couldn't create room!", serializer);
	}

	return result;
}

RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo info)
{
	GetPlayersInRoomRequest getPlayersInRoomRequest;
	RequestResult result;
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;
	int returnCode = 0;

	// try to get players in room request
	try
	{
		// deserialize get players in room request
		getPlayersInRoomRequest = deserializer.deserializeGetPlayersRequest(info.buffer);
	}
	catch (...)
	{
		return returnError(result, "Error! Couldn't parse get players in room request", serializer);
	}

	try
	{
		GetPlayersInRoomResponse getPlayersInRoomResponse;

		getPlayersInRoomResponse._players = this->m_handlerFactory->getRoomManager().getRoom(getPlayersInRoomRequest.roomId).getAllUsers();
		
		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(m_user);
		}
		else
		{
			return returnError(result, "Error! Couldn't get players in room!", serializer);
		}

		result.response = serializer.serializeResponse(getPlayersInRoomResponse);
	}
	catch (std::exception& e)
	{
		return returnError(result, "Error! Couldn't get players in room!", serializer);
	}

	return result;
}

RequestResult MenuRequestHandler::getPersonalStats(RequestInfo info)
{
	RequestResult result;
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;
	int returnCode = 1;

	try
	{
		GetPersonalStatsResponse getPersonalStatsResponse;

		getPersonalStatsResponse._statistics = this->m_handlerFactory->getStatisticsManager().getUserStatistics(m_user.getUsername());

		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(m_user);
		}
		else
		{
			return returnError(result, "Error! Couldn't get personal stats!", serializer);
		}

		result.response = serializer.serializeResponse(getPersonalStatsResponse);
	}
	catch (std::exception& e)
	{
		return returnError(result, "Error! Couldn't get user personal stats!", serializer);
	}

	return result;
}

RequestResult MenuRequestHandler::getHighScore(RequestInfo info)
{
	RequestResult result;
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;
	int returnCode = 1;

	try
	{
		GetHighScoreResponse getHighScoreResponse;

		getHighScoreResponse._statistics = this->m_handlerFactory->getStatisticsManager().getHighScore();

		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(m_user);
		}
		else
		{
			return returnError(result, "Error! Couldn't get high scorre stats!", serializer);
		}

		result.response = serializer.serializeResponse(getHighScoreResponse);
	}
	catch (std::exception& e)
	{
		return returnError(result, "Error! Couldn't get high scorre stats!", serializer);
	}

	return result;
}

RequestResult MenuRequestHandler::joinRoom(RequestInfo info)
{
	JoinRoomRequest joinRoomRequest;
	RequestResult result;
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;
	int returnCode = 0;

	// try to join room request
	try
	{
		// deserialize join in room request
		joinRoomRequest = deserializer.deserializeJoinRoomRequest(info.buffer);
	}
	catch (...)
	{
		return returnError(result, "Error! Couldn't parse join room request", serializer);
	}

	try
	{
		JoinRoomResponse joinRoomResponse;

		joinRoomResponse._status = this->m_handlerFactory->getRoomManager().getRoom(joinRoomRequest.roomId).addUser(m_user);

		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(m_user);
		}
		else
		{
			return returnError(result, "Error! Couldn't join room!", serializer);
		}

		result.response = serializer.serializeResponse(joinRoomResponse);
	}
	catch (std::exception& e)
	{
		return returnError(result, "Error! User couldn't join room!", serializer);
	}

	return result;
}

RequestResult MenuRequestHandler::signout(RequestInfo info)
{
	RequestResult result;
	int returnCode = 1;
	JsonResponsePacketSerializer serializer;

	try
	{
		LogoutResponse logoutResponse;

		logoutResponse._status = this->m_handlerFactory->getLoginManager().logout(m_user.getUsername());

		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(m_user);
		}
		else
		{
			return returnError(result, "Error! Couldn't signout!", serializer);
		}

		result.response = serializer.serializeResponse(logoutResponse);
	}
	catch (std::exception& e)
	{
		return returnError(result, "Error! User couldn't signout!", serializer);
	}

	return result;
}
