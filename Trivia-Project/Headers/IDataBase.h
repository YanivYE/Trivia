#pragma once
#include <string>
#include <iostream>
#include <io.h>
#include <stdio.h>
#include <cstdlib>
#include "sqlite3.h"
#include <vector>
#include <list>
#include <map>
#include <cstdlib>
#include "Question.h"


#define DB_NAME "MyDB.sqlite"


class IDataBase
{
public:	
	// base data base funcs
	virtual bool open() = 0;
	virtual bool close() = 0; 
	virtual int doesUserExist(std::string username) = 0;
	virtual int doesPasswordMatch(std::string username, std::string password) = 0;
	virtual int addNewUser(std::string username, std::string password, std::string mail) = 0;
	
	// Statistics
	virtual int addStatistic(std::string username, std::string time, std::string isCorrectAnswer, std::string score) = 0;
	virtual QuestionsList* getQuestions(int amount) = 0;
	virtual float getPlayerAverageAnswerTime(std::string username) = 0;
	virtual int getNumOfCorrectAnswers(std::string uaername) = 0;
	virtual int getNumOfWrongAnswers(std::string username) = 0;
	virtual int getNumOfPlayerGames(std::string username) = 0;
	virtual int getPlayerTotalScore(std::string username) = 0;
	virtual std::multimap<int, std::string> getLeaderboard() = 0;
	virtual int addNewGame(std::string username) = 0;

	sqlite3* db; // db
};
