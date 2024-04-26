#pragma once

#include <iostream>

class LoggedUser
{
public:
	LoggedUser(); // logged user ctor
	LoggedUser(std::string username); // logged user ctor
	
	std::string getUsername() const; // get username of logged user

	bool operator==(const LoggedUser& other) const; // == operator that checks the username
	bool operator!=(const LoggedUser& other) const; // != operator that checks the username
	bool operator<(const LoggedUser& other) const; // != operator that checks the username
private:
	std::string m_username; // username of logged user
};