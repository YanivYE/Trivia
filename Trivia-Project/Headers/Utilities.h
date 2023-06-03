#pragma once

#include <iostream>
#include <vector>
#include "..\Headers\json.hpp"
#include "Room.h"

using json = nlohmann::json;

enum messageCode { Login = 1, SignUp, Logout, GetRooms, GetPlayersInRoom, JoinRoom, CreateRoom, GetHighScore, GetPersonalStats, Error};
enum statusCode {Fail = -1, Success = 1};
enum errorCode {userNotExist = 100, userNameExist, userAlreadyLogedIn, invalidUserName};
enum roomStatusCodes {inGame = 200, waitingToStart};
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
