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

	switch (info.requestId)
	{
	case CreateRoom:
		return createRoom(info);
		break;  
	case GetRooms:
		return getRooms(info);
		break;
	case GetPlayersInRoom:
		return getPlayersInRoom(info);
		break;
	case JoinRoom:
		return joinRoom(info);
		break;
	case GetPersonalStats:
		return getPersonalStats(info);
		break;
	case GetLeaderboardStats:
		return getHighScore(info);
		break;
	case Logout:
		return signout(info);
		break;
	}
	
	return requestResult;
}

/*
* Function gets a request result, err msg, serializer and returns a serializer request result
* Input: result - the current request result info
*		 errorMsg - error msg
*		 serializer - the serializer
* Output: a get players in room request
*/
RequestResult MenuRequestHandler::returnError(RequestResult& result, std::string errorMsg, JsonResponsePacketSerializer serializer)
{
	ErrorResponse errResponse;
	errResponse._data = errorMsg;

	result.response = serializer.serializeResponse(errResponse);
	return result;
} 

/*
* Function gets a info to deserialize and returns a request result of creating a room
* Input: info - the info to desializer to request result
* Output: a create room request result
*/
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
		// get room data
		RoomData roomData;

		roomData.name = createRoomRequest._roomName;
		roomData.maxPlayers = createRoomRequest._maxUsers;
		roomData.numOfQuestionsInGame = createRoomRequest._questionCount;
		roomData.timePerQuestion = createRoomRequest._answerTimeout;
		
		// try to create room
		returnCode = this->m_handlerFactory->getRoomManager().createRoom(this->m_user, roomData);

		// create menu request handler for user if success
		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createRoomAdminRequestHandler(m_user, this->m_roomManager->getRoom(roomData.id));
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

/*
* Function gets a info to deserialize and returns a request result of get rooms
* Input: info - the info to desializer to request result
* Output: a get rooms request result
*/
RequestResult MenuRequestHandler::getRooms(RequestInfo info)
{
	RequestResult result;
	int returnCode = Success;
	JsonResponsePacketSerializer serializer;

	try
	{
		// get rooms from room manager
		GetRoomsResponse getRoomsResponse;

		getRoomsResponse._rooms = this->m_handlerFactory->getRoomManager().getRooms();

		// if success create menu request handlers
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

/*
* Function gets a info to deserialize and returns a request result of get players in room
* Input: info - the info to desializer to request result
* Output: a get players in room request result
*/
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
		// get playser from room 
		GetPlayersInRoomResponse getPlayersInRoomResponse;

		getPlayersInRoomResponse._players = this->m_handlerFactory->getRoomManager().getRoom(getPlayersInRoomRequest._roomId).getAllUsers();
		
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

/*
* Function gets a info to deserialize and returns a request result of get personal stats
* Input: info - the info to desializer to request result
* Output: a get personal stats request result
*/
RequestResult MenuRequestHandler::getPersonalStats(RequestInfo info)
{
	RequestResult result;
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;
	int returnCode = Success;

	try
	{
		// get personal stats
		GetPersonalStatsResponse getPersonalStatsResponse;

		getPersonalStatsResponse._statistics = this->m_handlerFactory->getStatisticsManager().getUserStatistics(m_user.getUsername());

		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(m_user);
		}
		else
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(m_user);
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

/*
* Function gets a info to deserialize and returns a request result of get get high score
* Input: info - the info to desializer to request result
* Output: a get high score request result
*/
RequestResult MenuRequestHandler::getHighScore(RequestInfo info)
{
	RequestResult result;
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;
	int returnCode = Success;

	try
	{
		// get high score
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

/*
* Function gets a info to deserialize and returns a request result of get join room
* Input: info - the info to desializer to request result
* Output: a join room request result
*/
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
		// join rooms 
		JoinRoomResponse joinRoomResponse;

		joinRoomResponse._status = this->m_handlerFactory->getRoomManager().getRoom(joinRoomRequest._roomId).addUser(m_user);
		joinRoomResponse._name = this->m_handlerFactory->getRoomManager().getRoom(joinRoomRequest._roomId).getRoomData().name;

		if (joinRoomResponse._status == Success)
		{
			result.newHandler = this->m_handlerFactory->createRoomMemberRequestHandler(m_user, this->m_handlerFactory->getRoomManager().getRoom(joinRoomRequest._roomId));
		}
		else
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(m_user);
			return returnError(result, "Error! Couldn't join room! maybe full :0", serializer);
		}

		joinRoomResponse._name = this->m_handlerFactory->getRoomManager().getRoom(joinRoomRequest._roomId).getRoomData().name;
		result.response = serializer.serializeResponse(joinRoomResponse);
	}
	catch (std::exception& e)
	{
		result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(m_user);
		return returnError(result, "Error! User couldn't join room!", serializer);
	}

	return result;
}

/*
* Function gets a info to deserialize and returns a request result of signout
* Input: info - the info to desializer to request result
* Output: a signout request result
*/
RequestResult MenuRequestHandler::signout(RequestInfo info)
{
	RequestResult result;
	JsonResponsePacketSerializer serializer;

	try
	{
		// logout
		LogoutResponse logoutResponse;

		logoutResponse._status = this->m_handlerFactory->getLoginManager().logout(m_user.getUsername());

		if (logoutResponse._status == Logout)
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
