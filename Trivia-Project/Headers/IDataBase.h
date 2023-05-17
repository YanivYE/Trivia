#pragma once
#include <string>
#include "sqlite3.h"

#define DB_NAME "MyDB.sqlite"
#include <iostream>
#include <io.h>


class IDataBase
{
public:
	virtual bool open() = 0;
	virtual bool close() = 0;
	virtual int doesUserExist(std::string name) = 0;
	virtual int doesPasswordMatch(std::string originalPassword, std::string password) = 0;
	virtual int addNewUser(std::string name, std::string password, std::string mail) = 0;

	sqlite3* db;
};