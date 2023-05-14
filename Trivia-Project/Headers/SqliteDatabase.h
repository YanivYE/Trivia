#pragma once

#include "IDataBase.h"

class SqliteDatabase : public IDataBase
{
	bool open() override;
	bool close() override;
	int doesUserExist(std::string name) override;
	int doesPasswordMatch(std::string originalPassword, std::string password) override;
	int addNewUser(std::string name, std::string password, std::string mail) override;
};