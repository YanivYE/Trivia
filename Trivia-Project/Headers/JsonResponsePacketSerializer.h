#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <cstring>
#include <bitset>
#include <sstream>
#include <iostream>

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

	Buffer serializeResponse(LogoutResponse response); // serialize logout reponse
	Buffer serializeResponse(GetRoomsResponse response); // serialize get rooms reponse
	Buffer serializeResponse(GetPlayersInRoomResponse response); // serialize get players in room reponse
	Buffer serializeResponse(JoinRoomResponse response); // serialize join room reponse
	Buffer serializeResponse(CreateRoomResponse response); // serialize create room reponse
	Buffer serializeResponse(GetHighScoreResponse response); // serialize get high score reponse
	Buffer serializeResponse(GetPersonalStatsResponse response); // serialize get personal stats reponse

	Buffer serializeResponse(CloseRoomResponse response); // serialize close room reponse
	Buffer serializeResponse(StartGameResponse response); // serialize start game reponse
	Buffer serializeResponse(GetRoomStateResponse response); // serialize get room state reponse
	Buffer serializeResponse(LeaveRoomResponse response); // serialize leave room reponse


	Buffer serializeResponse(GetGameResultsResponse response); // serialize leave room reponse
	Buffer serializeResponse(SubmitAnswerResponse response); // serialize leave room reponse
	Buffer serializeResponse(GetQuestionResponse response); // serialize leave room reponse
	Buffer serializeResponse(LeaveGameResponse response); // serialize leave room reponse

private:
	Buffer serializeReponseStatus(int code, int status); // serialize response status
	Buffer serializeResponseStats(int status, std::vector<std::string> statistics, std::string typeOfStats, int code); // serialize reponse stats with stats and type of stats

	std::string convertIntToBinaryString(int value); // convert int to binrary string
	std::string convertJsonToBinaryString(json value); // json to binrary string
	std::string padBinaryString(const std::string& value, int numBytes); // pad binrary string 
	std::vector<unsigned char> binaryStringToBits(const std::string& binaryString); // binrary string to vector bits
	std::vector<unsigned char> convertMessageToBuffer(Message message); // nessage to buffer of bits

	std::string vectorToString(std::vector<PlayerResults> vec);
};