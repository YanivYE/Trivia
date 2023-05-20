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
	if (!isValidUsername(username))
	{
		return invalidUserName;
	}
	if (!this->m_database->doesUserExist(username))
	{
		return this->m_database->addNewUser(username, password, mail);
	}
	return userNameExist;
}

int LoginManager::login(std::string username, std::string password)
{
	if (!isValidUsername(username))
	{
		return invalidUserName;
	}
	if (this->m_database->doesUserExist(username) && this->m_database->doesPasswordMatch(username, password))
	{
		if (!(std::find(this->m_loggedUsers.begin(), this->m_loggedUsers.end(), LoggedUser(username)) != this->m_loggedUsers.end()))
		{
			this->m_loggedUsers.push_back(LoggedUser(username));
		}
		return userAlreadyLogedIn;
	}
	return userNotExist;
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

bool isValidUsername(const std::string& username) {
	if (username.length() < 3) {
		return false;
	}

	for (char c : username) {
		if (!std::isalnum(c)) {
			return false;
		}
	}

	return true;
}
