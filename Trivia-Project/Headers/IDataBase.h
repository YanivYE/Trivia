#pragma once
#include <string>
#include <iostream>
#include <io.h>
#include <stdio.h>
#include <cstdlib>
#include "sqlite3.h"


#define DB_NAME "MyDB.sqlite"


class IDataBase
{
public:
	virtual bool open() = 0;
	virtual bool close() = 0; 
	virtual int doesUserExist(std::string username) = 0;
	virtual int doesPasswordMatch(std::string username, std::string password) = 0;
	virtual int addNewUser(std::string username, std::string password, std::string mail) = 0;

	sqlite3* db; // db
};
