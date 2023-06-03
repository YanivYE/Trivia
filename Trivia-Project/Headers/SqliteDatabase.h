#pragma once

#include "IDataBase.h"
#include "Utilities.h"

class SqliteDatabase : public IDataBase
{
public:
	static SqliteDatabase& getInstance() {
		static SqliteDatabase instance;
		return instance;
	}

	bool open() override; // open db
	bool close() override; // close db
	int doesUserExist(std::string username) override; // check if user exists in db
	int doesPasswordMatch(std::string username, std::string password) override; // check if password matches username pass in db
	int addNewUser(std::string username, std::string password, std::string mail) override; // add new user to db

	// Statistics
	std::list<std::string> getQuestions(int amount) override;
	float getPlayerAverageAnswerTime(std::string username) override;
	int getNumOfCorrectAnswers(std::string uaername) override;
	int getNumOfTotalAnswers(std::string username) override;
	int getNumOfPlayerGames(std::string username) override;
	int getPlayerScore(std::string username) override;
	std::vector<std::string> getHighScores() override;

private:
	SqliteDatabase()
	{
		this->open();
	}

	~SqliteDatabase()
	{
		this->close();
	}

	void createDBTables();
	void createUsersTable(); // create db table
	void createQuestionsTable();
	void insertQuestions();
	void createStatisticsTable();
};
