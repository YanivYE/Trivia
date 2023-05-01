#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "IRequestHandler.h"
#include "json.hpp"

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

struct Message
{
	code _code;
	int _dataLength;
	json _data;
}typedef Message;

struct Buffer
{
	std::vector<unsigned char> bytes;
} typedef Buffer;

static class JsonRequestPacketDeserializer
{
public:
	JsonRequestPacketDeserializer();
	~JsonRequestPacketDeserializer();

	LoginRequest deserializeLoginRequest(Buffer buffer);
	SignupRequest deserializeSignupRequest(Buffer buffer);
private:
	nlohmann::json convertBytesToJson(const std::vector<unsigned char>& bytes);
};	