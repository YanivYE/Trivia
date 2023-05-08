#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <cstring>
#include <bitset>
#include <sstream>

#include "..\Headers\json.hpp"
#include "..\Headers\Structs.h"

#define CODE_SIZE 1

using json = nlohmann::json;

struct LoginResponse
{
	unsigned int _status;
}typedef LoginResponse;

struct SignUpResponse
{
	unsigned int _status;
}typedef SignUpResponse;

struct ErrorResponse
{
	std::string _data;
}typedef ErrorResponse;

static class JsonResponsePacketSerializer
{
public:
	Buffer serializeResponse(LoginResponse response);
	Buffer serializeResponse(SignUpResponse response);
	Buffer serializeResponse(ErrorResponse response);
private:
	std::string convertIntToBinaryString(int value);
	std::string convertJsonToBinaryString(json value);
	std::string padBinaryString(const std::string& value, int numBytes);
	std::vector<unsigned char> binaryStringToBits(const std::string& binaryString);
	std::vector<unsigned char> convertMessageToBuffer(Message message);
};