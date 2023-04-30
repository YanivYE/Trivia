#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "IRequestHandler.h"

using std::string;

#define CODE_INDEX 0
#define MSG_OFFSET 5

struct LoginRequest
{
	string username;
	string password;
} typedef LoginRequest;

struct SignupRequest
{
	string username;
	string password;
	string email;
} typedef SignupRequest;

struct Buffer
{
	std::vector<unsigned char> bytes;
} typedef Buffer;

static class JsonRequestPacketDeserializer
{
public:
	JsonRequestPacketDeserializer();
	~JsonRequestPacketDeserializer();

	LoginRequest deserializeLoginRequest(Buffer buffer);
	SignupRequest deserializeSignupRequest(Buffer buffer);
private:
	RequestInfo* bufferToRequestInfo(Buffer buffer);
};	