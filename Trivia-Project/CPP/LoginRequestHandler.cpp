#include "../Headers/LoginRequestHandler.h"

/*
* Function is an empty ctor for LoginRequestHandler
* Input: none
* Output: none
*/
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
* Function gets a request info and handles request
* Input: info - info of request
* Output: request handle result
*/
RequestResult LoginRequestHandler::handleRequest(RequestInfo info)
{
	RequestResult requestResult;

	if (info.requestId == Login)
	{
		// set login request result
		requestResult = this->login(info);
	}
	else
	{
		// set signup request result
		requestResult = this->signup(info);
	}

	return requestResult;
}

/*
* Function gets a request info and logins 
* Input: info - info of request
* Output: request result of login
*/
RequestResult LoginRequestHandler::login(RequestInfo info)
{
	LoginRequest loginRequest;
	RequestResult result;
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;
	int returnCode = 0;

	// try to get login request
	try
	{
		// deserialize login request
		loginRequest = deserializer.deserializeLoginRequest(info.buffer);
	}
	catch (...)
	{
		ErrorResponse errResponse;
		errResponse._data = "Error! Couldn't parse login request";

		// serialize error response
		result.response = serializer.serializeResponse(errResponse);
		return result;
	}

	try
	{
		// try to login
		returnCode = this->m_handlerFactory->getLoginManager().login(loginRequest._username, loginRequest._password);

		if (returnCode == Login)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(LoggedUser(loginRequest._username));
			this->m_handlerFactory->setUser(LoggedUser(loginRequest._username));

			LoginResponse loginResponse;
			loginResponse._status = returnCode;

			result.response = serializer.serializeResponse(loginResponse);
		}
		else
		{
			result.newHandler = this->m_handlerFactory->createLoginRequestHandlers();

			ErrorResponse errResponse;
			errResponse._data = "Error! Username doesn't exist!";

			result.response = serializer.serializeResponse(errResponse);
		}
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
		returnCode = this->m_handlerFactory->getLoginManager().signup(signupRequest._username, signupRequest._password, signupRequest._email);
		
		if (returnCode == SignUp)
		{
			result.newHandler = this->m_handlerFactory->createMenuRequestHandlers(LoggedUser(signupRequest._username));
			SignUpResponse signUpResponse;
			signUpResponse._status = returnCode;
			result.response = serializer.serializeResponse(signUpResponse);
		}
		else
		{
			result.newHandler = this->m_handlerFactory->createLoginRequestHandlers();
			ErrorResponse errResponse;
			errResponse._data = "Error! Couldn't sign up user to server";

			result.response = serializer.serializeResponse(errResponse);
		}
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