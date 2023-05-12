#include "../Headers/LoginRequestHandler.h"

/*
* Function is a ctor for login request handler
* Input: none
* Output: none
*/
LoginRequestHandler::LoginRequestHandler()
{
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
	RequestResult result = RequestResult();
	std::vector<unsigned char> bufBytes;
	Buffer buf = Buffer();

	bufBytes.push_back(info.requestId);
	bufBytes.push_back(info.buffer._bytes.size());
	bufBytes.insert(bufBytes.end(), info.buffer._bytes.begin(), info.buffer._bytes.end()); // add bytes from info
	
	buf._bytes = bufBytes;

	result.response = buf;
	result.newHandler = nullptr; // handler null for now

	return result;
}