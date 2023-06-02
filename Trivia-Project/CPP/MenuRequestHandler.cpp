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

	}
	else if (info.requestId == GetPlayersInRoom)
	{

	}
	else if (info.requestId == JoinRoom)
	{

	}
	else if (info.requestId == GetPersonalStats)
	{

	}
	else if (info.requestId == Logout)
	{

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
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(LoggedUser(loginRequest.username));
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
		return returnError(result, "Error! User couldn't create room!", serializer);
	}

	return result;
}

/*
* Function gets a request info and sign ups
* Input: info - info of request
* Output: request result of sign up
*/
RequestResult LoginRequestHandler::signup(RequestInfo info)
{
	SignupRequest signupRequest;
	RequestResult result;
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;
	int returnCode = 0;

	// try to get sign up request
	try
	{
		signupRequest = deserializer.deserializeSignupRequest(info.buffer);
	}
	catch (...)
	{
		ErrorResponse errResponse;
		errResponse._data = "Error! Couldn't parse signup request";
		result.response = serializer.serializeResponse(errResponse);
		return result;
	}

	try
	{
		// try to sign up
		returnCode = this->m_handlerFactory->getLoginManager().signup(signupRequest.username, signupRequest.password, signupRequest.email);

		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(LoggedUser(signupRequest.username));
		}
		else
		{
			result.newHandler = this->m_handlerFactory->createLoginRequestHandlers();
		}

		SignUpResponse signUpResponse;
		signUpResponse._status = returnCode;
		result.response = serializer.serializeResponse(signUpResponse);
	}
	catch (std::exception& e)
	{
		result.newHandler = this->m_handlerFactory->createLoginRequestHandlers();

		ErrorResponse errResponse;
		errResponse._data = "Error! Couldn't sign up user to server";

		result.response = serializer.serializeResponse(errResponse);
	}

	return result;
}
