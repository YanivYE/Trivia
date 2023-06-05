#pragma once

#include "IDataBase.h"
#include "LoggedUser.h"
#include "Utilities.h"
#include <vector>

class LoginManager
{
public:
	// get login manager instance
	static LoginManager& getInstance(IDataBase* database)
	{
		static LoginManager instance(database);
		return instance;
	}

	int signup(std::string username, std::string password, std::string mail); // signup
	int login(std::string username, std::string password); // login 
	int logout(std::string username); // logout

private:
	// ctor
	LoginManager(IDataBase* database)
	{
		this->m_database = database;
	}

	// dtor
	~LoginManager()
	{
		m_database->close();
	}

	bool isValidUsername(const std::string& username); // is username valid

	IDataBase* m_database; // db
	std::vector<LoggedUser> m_loggedUsers; // vector of logged users
};
