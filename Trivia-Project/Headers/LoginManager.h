#pragma once

#include "IDataBase.h"
#include "LoggedUser.h"
#include "Utils.h"
#include <vector>

class LoginManager
{
public:
	LoginManager();
	LoginManager(IDataBase* database);

	int signup(std::string username, std::string password, std::string mail);
	int login(std::string username, std::string password);
	int logout(std::string username);

private:
	bool isValidUsername(const std::string& username);
	IDataBase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
};