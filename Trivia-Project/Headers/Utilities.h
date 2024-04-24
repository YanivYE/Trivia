#pragma once

#include <iostream>
#include <vector>
#include "..\Headers\json.hpp"
#include "Room.h"

class Utilities;
class Room;
struct RoomData;

#define NUM_OF_QUESTIONS 10

using json = nlohmann::json;

enum messageCode { Login = 0b00000001, SignUp = 0b00000010, Logout = 0b00000011, GetRooms = 0b00000100,
	GetPlayersInRoom = 0b00000101, JoinRoom = 0b00000110, CreateRoom = 0b00000111, GetHighScore = 0b00001000,
	GetPersonalStats = 0b00001001, CloseRoom = 0b00001010, StartGame = 0b00001011, GetRoomState = 0b00001100,
	LeaveRoom = 0b00001101, Fail = 0b000001110, Success = 0b00001111, GetGameResult = 0b00001110,
	SubmitAnswer = 0b00001111, GetQuestion = 0b00010000, GetLeaderboardStats = 0b00010000, LeaveGame = 0b00010001
};
enum errorCode {userNotExist = 1, userNameExist, userAlreadyLogedIn, invalidUserName};
enum roomStatusCodes {inGame = 1, waitingToStart};
enum checkAnswer {wrong, correct};

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

struct JoinRoomResponse
{
	unsigned int _status;
	std::string _name;
}typedef JoinRoomResponse;

struct CreateRoomResponse
{
	unsigned int _status;
}typedef CreateRoomResponse;

struct LogoutResponse
{
	unsigned int _status;
}typedef LogoutResponse;

struct GetRoomsResponse
{
	unsigned int _status;
	std::vector<RoomData> _rooms;
}typedef GetRoomsResponse;

struct GetPlayersInRoomResponse
{
	std::vector<std::string> _players;
}typedef GetPlayersInRoomResponse;

struct GetHighScoreResponse
{
	unsigned int _status;
	std::vector<std::string> _statistics;
}typedef GetHighScoreResponse;

struct GetPersonalStatsResponse
{
	unsigned int _status;
	std::vector<std::string> _statistics;
}typedef GetPersonalStatsResponse;

struct Buffer
{
	std::vector<unsigned char> _bytes;
};

struct Message
{
	int _code;
	int _dataLength;
	json _data;
}typedef Message;

struct LoginRequest
{
	std::string _username;
	std::string _password;
} typedef LoginRequest;

struct SignupRequest
{
	std::string _username;
	std::string _password;
	std::string _email;
} typedef SignupRequest;

struct GetPlayersInRoomRequest
{
	unsigned int _roomId;
} typedef GetPlayersInRoomRequest;

struct JoinRoomRequest
{
	unsigned int _roomId;
} typedef JoinRoomRequest;

struct CreateRoomRequest
{
	std::string _roomName;
	unsigned int _maxUsers;
	unsigned int _questionCount;
	unsigned int _answerTimeout;
} typedef CreateRoomRequest;

struct CloseRoomResponse
{
	unsigned int _status;
} typedef CloseRoomResponse;

struct StartGameResponse
{
	unsigned int _status;
} typedef StartGameResponse;

struct GetRoomStateResponse
{
	unsigned int _status;
	bool _hasGameBegun;
	std::vector<std::string> _players;
	unsigned int _questionCount;
	unsigned int _answerTimeout;
	unsigned int _maxPlayers;
} typedef GetRoomStateResponse;

struct LeaveRoomResponse
{
	unsigned int _status;
} typedef LeaveRoomResponse;

struct LeaveGameResponse
{
	unsigned int _status;
} typedef LeaveGameResponse;

struct GetQuestionResponse
{
	unsigned int _status;
	std::string _question;
	std::vector<std::string> _answers;
} typedef GetQuestionResponse;

struct SubmitAnswerResponse
{
	unsigned int _status;
	unsigned int _correctAnswerId;
} typedef SubmitAnswerResponse;

struct PlayerResults
{
	std::string _username;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	unsigned int averageAnswerTime;
} typedef PlayerResults;

struct GetGameResultsResponse
{
	unsigned int _status;
	std::vector<PlayerResults> _results;
} typedef GetGameResultsResponse;

struct SubmitAnswerRequest
{
	unsigned int _answerId;
} typedef SubmitAnswerRequest;

struct GameResultRequest
{
	unsigned int _totalScore;
} typedef GameResultRequest;