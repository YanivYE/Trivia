#pragma once

#include <iostream>

class LoggedUser
{
public:
	LoggedUser(std::string username);
	
	std::string getUsername();

	bool operator==(const LoggedUser& other) const;
	bool operator!=(const LoggedUser& other) const;
private:
	std::string m_username;
};