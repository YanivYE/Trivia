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
private:
	SqliteDatabase()
	{
		this->open();
	}

	~SqliteDatabase()
	{
		this->close();
	}

	void createTable(); // create db table
};
