#pragma once

#include <iostream>

class LoggedUser
{
public:
	LoggedUser(std::string username); // logged user ctor
	
	std::string getUsername(); // get username of logged user

	bool operator==(const LoggedUser& other) const; // == operator that checks the username
	bool operator!=(const LoggedUser& other) const; // != operator that checks the username
private:
	std::string m_username; // username of logged user
};