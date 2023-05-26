#include "../Headers/Room.h"

int Room::count = 0;

Room::Room(std::string name, unsigned int maxPlayers, unsigned int timePerQuestion)
{
	this->m_metadata.id = ++count;
	this->m_metadata.isActive = true;
	this->m_metadata.maxPlayers = maxPlayers;
	this->m_metadata.name = name;
	this->m_metadata.numOfQuestionsInGame = NUM_OF_QUESTIONS;
	this->m_metadata.timePerQuestion = timePerQuestion;
}

void Room::addUser(LoggedUser user)
{
	this->m_users.push_back(user);
}

void Room::removeUser(LoggedUser user)
{
	for (int i = 0; i < this->m_users.size(); i++)
	{
		if (this->m_users[i] == user) 
		{
			this->m_users.erase(this->m_users.begin() + i);
		}
	}
}

RoomData Room::getRoomData()
{
	return this->m_metadata;
}

std::vector<std::string> Room::getAllUsers()
{
	std::vector<std::string> users;

	for (int i = 0; i < this->m_users.size(); i++)
	{
		users.push_back(this->m_users[i].getUsername());
	}

	return users;
}
