#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "IRequestHandler.h"
#include "json.hpp"
#include "..\Headers\Utilities.h"
#include <bitset>

using json = nlohmann::json;
using std::string;

static class JsonRequestPacketDeserializer
{
public:
	LoginRequest deserializeLoginRequest(Buffer buffer); // deserailize login request
	SignupRequest deserializeSignupRequest(Buffer buffer); // deserialize sign up request

	GetPlayersInRoomRequest deserializeGetPlayersRequest(Buffer buffer); // deserailize get players request
	JoinRoomRequest deserializeJoinRoomRequest(Buffer buffer); // deserailize join room request
	CreateRoomRequest deserializeCreateRoomRequest(Buffer buffer); // deserailize create room request

	SubmitAnswerRequest deserializeSubmitAnswerRequest(Buffer buffer); // deserailize submit answer request
private:
	nlohmann::json convertBytesToJson(const std::vector<unsigned char>& bytes); // convert bytes vector to json
	std::string binaryToAscii(const std::vector<unsigned char>& bytes); // convert bytes to ascii
};	