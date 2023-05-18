#pragma once

#include "IDataBase.h"
#include "LoggedUser.h"
#include <vector>

class LoginManager
{
public:
	int signup(std::string username, std::string password, std::string mail);
	int login(std::string username, std::string password);
	int signout(std::string username);

private:
	IDataBase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
};