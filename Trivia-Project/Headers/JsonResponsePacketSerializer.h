#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <cstring>
#include <bitset>
#include <sstream>

#include "..\Headers\json.hpp"
#include "..\Headers\Utilities.h"

#define CODE_SIZE 1

using json = nlohmann::json;

static class JsonResponsePacketSerializer
{
public:
	Buffer serializeResponse(LoginResponse response); // serialize login response
	Buffer serializeResponse(SignUpResponse response); // serialize sign up response
	Buffer serializeResponse(ErrorResponse response); // serialize error response
private:
	std::string convertIntToBinaryString(int value); // convert int to binrary string
	std::string convertJsonToBinaryString(json value); // json to binrary string
	std::string padBinaryString(const std::string& value, int numBytes); // pad binrary string 
	std::vector<unsigned char> binaryStringToBits(const std::string& binaryString); // binrary string to vector bits
	std::vector<unsigned char> convertMessageToBuffer(Message message); // nessage to buffer of bits
};