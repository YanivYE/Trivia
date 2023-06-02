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
	Room(std::string name, unsigned int maxPlayers, unsigned int timePerQuestion, unsigned int numOfQuestionsInGame); // ctor for room

	void addUser(LoggedUser user); // add user to room
	void removeUser(LoggedUser user); // remove user from room

	RoomData getRoomData(); // get room data

	std::vector<std::string> getAllUsers(); // get all users in room

	bool gameStarted(); // did game start
	void startGame(); // start game
	void stopGame(); // stop game
private:
	RoomData m_metadata; // room data
	std::vector<LoggedUser> m_users; // all users in room
	bool isInGame; 

	static int count; // instance to count id of room
};