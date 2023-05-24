#pragma once

#include <iostream>
#include <vector>
#include "LoggedUser.h"

struct RoomData
{
	unsigned int id;
	std::string name;
	unsigned int maxPlayers;
	unsigned int numOfQuestionsInGame;
	unsigned int timePerQuestion;
	unsigned int isActive;
} typedef RoomData;

class Room
{
public:
	void addUser(LoggedUser user);
	void removeUser(LoggedUser user);

	std::vector<std::string> getAllUsers();
private:
	RoomData m_metadata;
	std::vector<LoggedUser> m_users;
};