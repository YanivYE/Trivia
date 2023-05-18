#pragma once

#include "IDataBase.h"
#include "LoggedUser.h"
#include "Structs.h"
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
	IDataBase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
};