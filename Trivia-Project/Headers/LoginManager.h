#pragma once

#include "IDataBase.h"
#include "LoggedUser.h"
#include "Utilities.h"
#include <vector>

class LoginManager
{
public:
	static LoginManager& getInstance(IDataBase* database)
	{
		static LoginManager instance(database);
		return instance;
	}

	int signup(std::string username, std::string password, std::string mail);
	int login(std::string username, std::string password);
	int logout(std::string username);

private:
	LoginManager(IDataBase* database)
	{
		this->m_database = database;
	}

	~LoginManager()
	{
		m_database->close();
	}

	bool isValidUsername(const std::string& username);

	IDataBase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
};
