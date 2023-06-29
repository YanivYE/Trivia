#pragma once

#include "Utilities.h"
#include "IDataBase.h"
#include "Game.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>

class GameManager
{
public:
	Game createGame(Room room); // create new room
	void deleteGame(int gameId); // delete room

	IDataBase* getDataBase();

private:
	std::map<LoggedUser, GameData> getPlayers(Room room);
	IDataBase* m_database;
	std::vector<Game> m_games; 
};