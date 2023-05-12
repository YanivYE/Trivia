#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "IRequestHandler.h"
#include "json.hpp"
#include "..\Headers\Structs.h"
#include <bitset>

using json = nlohmann::json;
using std::string;

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

static class JsonRequestPacketDeserializer
{
public:
	LoginRequest deserializeLoginRequest(Buffer buffer); // deserailize login request
	SignupRequest deserializeSignupRequest(Buffer buffer); // deserialize sign up request
private:
	nlohmann::json convertBytesToJson(const std::vector<unsigned char>& bytes); // convert bytes vector to json
	std::string binaryToAscii(const std::vector<unsigned char>& bytes); // convert bytes to ascii
};	