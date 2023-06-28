#pragma once

#include "Utilities.h"
#include "IDataBase.h"
#include "Game.h"

class GameManager
{
public:
	Game createGame(Room room); // create new room
	void deleteGame(int gameId); // delete room

private:
	IDataBase* m_database;
	std::vector<Game> m_games; // map of rooms and id
};