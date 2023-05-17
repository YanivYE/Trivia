#pragma once

#include "IDataBase.h"

enum boolVal{FALSE, TRUE};

class SqliteDatabase : public IDataBase
{
public:
	bool open() override;
	bool close() override;
	int doesUserExist(std::string name) override;
	int doesPasswordMatch(std::string name, std::string password) override;
	int addNewUser(std::string name, std::string password, std::string mail) override;
private:
	void createTable();
};