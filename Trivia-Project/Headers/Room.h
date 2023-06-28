#pragma once

#include <iostream>
#include <vector>
#include "LoggedUser.h"
#include "Utilities.h"

#define SUCCESS 1
#define FAIL -1

struct RoomData
{
	unsigned int id;
	std::string name;
	unsigned int maxPlayers;
	unsigned int numOfQuestionsInGame;
	unsigned int timePerQuestion;
	unsigned int isActive;
} typedef RoomData;

class RoomManager;

class Room
{
public:
	Room(); // empty ctor
	Room(std::string name, unsigned int maxPlayers, unsigned int timePerQuestion, unsigned int numOfQuestionsInGame); // ctor for room

	int addUser(LoggedUser user); // add user to room
	int removeUser(LoggedUser user); // remove user from room

	void setId();

	RoomData getRoomData(); // get room data

	std::vector<std::string> getAllUsers(); // get all users in room

	bool gameStarted(); // did game start
	int startGame(); // start game
	void stopGame(); // stop game

	int getId();
private:
	RoomData* m_metadata; // room data
	std::vector<LoggedUser>* m_users; // all users in room
	bool isInGame; 

	static int count; // instance to count id of room
};