#pragma once

#include "IDataBase.h"
#include "Utilities.h"

class SqliteDatabase : public IDataBase
{
public:
	// get instance 
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
	std::vector<Question> getQuestions(int amount) override;
	float getPlayerAverageAnswerTime(std::string username) override;
	int getNumOfCorrectAnswers(std::string username) override;
	int getNumOfTotalAnswers(std::string username) override;
	int getNumOfPlayerGames(std::string username) override;
	int getPlayerScore(std::string username) override;
	std::vector<std::string> getHighScores() override;

private:
	// ctor
	SqliteDatabase()
	{
		this->open();
	}

	// dtor
	~SqliteDatabase()
	{
		this->close();
	}
	bool executeQuery(std::string query, int(*callback)(void*, int, char**, char**), void* data); // executr query
	void createDBTables(); // create db tables
	void createUsersTable(); // create user table
	void createQuestionsTable(); // create question tables
	void insertQuestions(); // insert queestions
	void createStatisticsTable(); // create stats table
	std::vector<std::string> getHighScoresTable(std::multimap<int, std::string> scores); // get high score table
	std::multimap<int, std::string> combineUserScores(const std::multimap<int, std::string>& scoresMap);
};
