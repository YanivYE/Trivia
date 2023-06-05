#include "../Headers/LoggedUser.h"

// empty ctor
LoggedUser::LoggedUser()
{
}

/*
* Function is a ctor for logged user and gets a username to set as field
* Input: username - the logged user
* Output: none
*/
LoggedUser::LoggedUser(std::string username)
{
	this->m_username = username;
}

/*
* Function returns logged user, username
* Input: none
* Output: username
*/
std::string LoggedUser::getUsername()
{
	return this->m_username;
}

/*
* Function is == operator and check if usernames are the same
* Input: none
* Output: if usernames are the same
*/
bool LoggedUser::operator==(const LoggedUser& other) const
{
	return this->m_username == other.m_username;
}

/*
* Function is != operator and check if usernames aren't the same
* Input: none
* Output: if usernames aren't the same
*/
bool LoggedUser::operator!=(const LoggedUser& other) const
{
	return this->m_username != other.m_username;
}
