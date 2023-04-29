#pragma once

#include <string>
#include <vector>

struct Buffer
{
	std::vector<unsigned char> bytes;
};

struct LoginResponse
{
	unsigned int _status;
};

struct SignUpResponse
{
	unsigned int _status;
};

struct ErrorResponse
{
	std::string message;
};

static class JsonResponsePacketSerializer
{
public:
	Buffer serializeResponse(ErrorResponse response);
	Buffer serializeResponse(LoginResponse response);
	Buffer serializeResponse(SignUpResponse response);
};