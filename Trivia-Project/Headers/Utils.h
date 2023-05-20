#pragma once

#include <iostream>
#include <vector>
#include "..\Headers\json.hpp"

using json = nlohmann::json;

enum messageCode { Login = 1, SignUp, Error };
enum statusCode {Fail = -1, Success = 1};
enum errorCode{userNotExist = 100, userNameExist, userAlreadyLogedIn, invalidUserName};
enum boolVal {False, True };


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