#pragma once

#include "IDataBase.h"
#include "Structs.h"

class SqliteDatabase : public IDataBase
{
public:
	SqliteDatabase();

	bool open() override;
	bool close() override;
	int doesUserExist(std::string username) override;
	int doesPasswordMatch(std::string username, std::string password) override;
	int addNewUser(std::string username, std::string password, std::string mail) override;
private:
	void createTable();
};