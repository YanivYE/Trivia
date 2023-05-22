#include "LoginManager.h"

/*
* Function is an empty ctor for login manager
* Input: none 
* Output: none
*/
LoginManager::LoginManager()
{
}

/*
* Function is a ctor for login manager and gets a db
* Input: database - the db for login manager
* Output: none
*/
LoginManager::LoginManager(IDataBase* database)
{
	this->m_database = database;
}

/*
* Function gets an username, password, mail and signs up 
* Input: username, password, mail
* Output: code for signup result
*/
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

/*
* Function gets an username, password and logins
* Input: username, password
* Output: code for login result
*/
int LoginManager::login(std::string username, std::string password)
{
	if (!isValidUsername(username))
	{
		return invalidUserName;
	}

	if (this->m_database->doesUserExist(username) && this->m_database->doesPasswordMatch(username, password))
	{
		// check if username is already logged in
		if (!(std::find(this->m_loggedUsers.begin(), this->m_loggedUsers.end(), LoggedUser(username)) != this->m_loggedUsers.end()))
		{
			this->m_loggedUsers.push_back(LoggedUser(username));

			return Success;
		}

		return userAlreadyLogedIn;
	}
	return userNotExist;
}

/*
* Function gets an username and logs out
* Input: username
* Output: code for logout result
*/
int LoginManager::logout(std::string username)
{
	// go on each logged user
	for (std::vector<LoggedUser>::iterator user = this->m_loggedUsers.begin(); user != this->m_loggedUsers.end(); ++user) 
	{
		// if username is there
		if ((*user).getUsername() == username)
		{
			this->m_loggedUsers.erase(user);
			return true;
		}
	}
	return false;
}

/*
* Function gets an username and checks if username is valid
* Input: username
* Output: if username is valid
*/
bool LoginManager::isValidUsername(const std::string& username)
{
	// check if username length is less than 3
	if (username.length() < 3) 
	{
		return false;
	}

	// go on each char
	for (char c : username) 
	{
		// if char is num/upper/lower case letter
		if (!std::isalnum(c)) 
		{
			return false;
		}
	}
	
	// valid usernmae
	return true;
}
