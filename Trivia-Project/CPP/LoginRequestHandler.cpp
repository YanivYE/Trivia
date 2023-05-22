#include "../Headers/LoginRequestHandler.h"

LoginRequestHandler::LoginRequestHandler()
{
}

/*
* Function is a ctor for login request handler
* Input: none
* Output: none
*/
LoginRequestHandler::LoginRequestHandler(RequestHandlerFactory* factory)
{
	this->m_handlerFactory = factory;
}

/*
* Function gets a request info and checks if request is relevant
* Input: info - info of request
* Output: is request relevant
*/
bool LoginRequestHandler::isRequestRelevant(RequestInfo info)
{
	return (info.requestId == Login) || (info.requestId == SignUp);
}

/*
* Function gets a request info and checks if request is relevant
* Input: info - info of request
* Output: is request relevant
*/
RequestResult LoginRequestHandler::handleRequest(RequestInfo info)
{
	RequestResult requestResult;

	if (info.requestId == Login)
	{
		requestResult = this->login(info);
	}
	else
	{
		requestResult = this->signup(info);
	}

	return requestResult;
}

RequestResult LoginRequestHandler::login(RequestInfo info)
{
	LoginRequest loginRequest;
	RequestResult result;
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;

	try
	{
		loginRequest = deserializer.deserializeLoginRequest(info.buffer);
	}
	catch (...)
	{
		ErrorResponse errResponse;
		errResponse._data = "Error! Couldn't parse login request";
		result.response = serializer.serializeResponse(errResponse);
		return result;
	}

	try
	{
		int returnCode;
		returnCode = this->m_handlerFactory->getLoginManager().login(loginRequest.username, loginRequest.password);
		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers();
		}
		else
		{
			result.newHandler = this->m_handlerFactory->createLoginRequestHandlers();

			ErrorResponse errResponse;
			errResponse._data = "Error! Username doesn't exist!";

			result.response = serializer.serializeResponse(errResponse);
		}

		LoginResponse loginResponse;
		loginResponse._status = returnCode;

		result.response = serializer.serializeResponse(loginResponse);
	}
	catch (std::exception& e)
	{
		result.newHandler = this->m_handlerFactory->createLoginRequestHandlers();

		ErrorResponse errResponse;
		errResponse._data = "Error! Couldn't log user to server";

		result.response = serializer.serializeResponse(errResponse);
	}

	return result;
}

RequestResult LoginRequestHandler::signup(RequestInfo info)
{
	SignupRequest signupRequest;
	RequestResult result;
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;

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
		int returnCode;
		returnCode = this->m_handlerFactory->getLoginManager().signup(signupRequest.username, signupRequest.password, signupRequest.email);
		
		if (returnCode == Success)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers();
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
