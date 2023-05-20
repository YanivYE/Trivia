#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "IRequestHandler.h"
#include "json.hpp"
#include "..\Headers\Utils.h"
#include <bitset>

using json = nlohmann::json;
using std::string;

static class JsonRequestPacketDeserializer
{
public:
	LoginRequest deserializeLoginRequest(Buffer buffer); // deserailize login request
	SignupRequest deserializeSignupRequest(Buffer buffer); // deserialize sign up request
private:
	nlohmann::json convertBytesToJson(const std::vector<unsigned char>& bytes); // convert bytes vector to json
	std::string binaryToAscii(const std::vector<unsigned char>& bytes); // convert bytes to ascii
};	