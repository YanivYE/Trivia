#pragma once

#include <iostream>
#include <vector>
#include "..\Headers\json.hpp"

using json = nlohmann::json;

enum code { Login = 1, SignUp, Error };

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