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
	Game* createGame(Room* room); // create new room
	void deleteGame(int gameId); // delete room
	Game* getGameByID(int id);
	IDataBase* getDataBase();

	// get database manager instance
	static GameManager& getInstance(IDataBase* database)
	{
		static GameManager instance(database);
		return instance;
	}

private:
	// ctor
	GameManager(IDataBase* database)
	{
		this->m_database = database;
	}

	// dtor
	~GameManager()
	{
		m_database->close();
	}

	std::map<LoggedUser, GameData*> getPlayers(Room* room, QuestionsList* questions);
	IDataBase* m_database;
	std::vector<Game*> m_games; 
};