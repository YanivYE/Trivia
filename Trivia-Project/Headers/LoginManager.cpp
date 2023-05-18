#include "LoginManager.h"

LoginManager::LoginManager()
{
}

LoginManager::LoginManager(IDataBase* database)
{
	this->m_database = database;
}

int LoginManager::signup(std::string username, std::string password, std::string mail)
{
	return this->m_database->addNewUser(username, password, mail);
}

int LoginManager::login(std::string username, std::string password)
{
	if (this->m_database->doesUserExist(username) && this->m_database->doesPasswordMatch(username, password))
	{
		this->m_loggedUsers.push_back(LoggedUser(username));
		return True;
	}
	return False;
}

int LoginManager::logout(std::string username)
{
	for (std::vector<LoggedUser>::iterator user = this->m_loggedUsers.begin(); user != this->m_loggedUsers.end(); ++user) 
	{
		if ((*user).getUsername() == username)
		{
			this->m_loggedUsers.erase(user);
			return True;
		}
	}
	return False;
}
