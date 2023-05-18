#pragma once

#include <iostream>
#include <vector>
#include "..\Headers\json.hpp"

using json = nlohmann::json;

enum messageCode { Login = 1, SignUp, Error };
enum statusCode {Fail = -1, Success = 1};
enum boolVal {False, True };

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