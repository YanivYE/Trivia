#pragma once

#include "IDataBase.h"
#include "LoggedUser.h"
#include "Utilities.h"
#include <vector>

class LoginManager
{
public:
	LoginManager(); // empty ctor
	LoginManager(IDataBase* database); // ctor with db

	int signup(std::string username, std::string password, std::string mail); // sign up 
	int login(std::string username, std::string password); // login
	int logout(std::string username); // logout

private:
	bool isValidUsername(const std::string& username); // check if username is valid
	IDataBase* m_database; // db
	std::vector<LoggedUser> m_loggedUsers; // logged user vector
};