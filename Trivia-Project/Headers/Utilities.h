#pragma once

#include <iostream>
#include <vector>
#include "..\Headers\json.hpp"
#include "Room.h"

using json = nlohmann::json;

enum messageCode { Login = 1, SignUp, Logout, getRooms, getPlayersInRoom, joinRoom, createRoom, getHighScore, getPersonalStats, Error};
enum statusCode {Fail = -1, Success = 1};
enum errorCode{userNotExist = 100, userNameExist, userAlreadyLogedIn, invalidUserName};
enum roomStatusCodes{inGame = 200, waitingToStart};

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

struct getHighScoreResponse
{
	unsigned int _status;
	std::vector<std::string> _statistics;
}typedef getHighScoreResponse;

struct getPersonalStatsResponse
{
	unsigned int _status;
	std::vector<std::string> _statistics;
}typedef getPersonalStatsResponse;

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
	std::string username;
	std::string password;
} typedef LoginRequest;

struct SignupRequest
{
	std::string username;
	std::string password;
	std::string email;
} typedef SignupRequest;