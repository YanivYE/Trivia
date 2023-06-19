#include "../Headers/Room.h"

int Room::count = 0;

Room::Room()
{
}

/*
* Function is a ctor for a room which gets a name, max players, and time per question.
* Input: name - the name of the room
*		 maxPlayers - the max players for the room
*		 timePerQuestion - how much time per question
*		 numOfQuestionsInGame - number of questions in game
* Output: none
*/
Room::Room(std::string name, unsigned int maxPlayers, unsigned int timePerQuestion, unsigned int numOfQuestionsInGame)
{
	this->m_metadata.id = ++count; // set id as num of instances

	this->m_metadata.isActive = true; // default active

	// set fields
	this->m_metadata.maxPlayers = maxPlayers;
	this->m_metadata.name = name;
	this->m_metadata.numOfQuestionsInGame = numOfQuestionsInGame;
	this->m_metadata.timePerQuestion = timePerQuestion;
}

/*
* Funciton gets a logged user and adds it to the room
* Input: user - logged user to add
* Output: none
*/
int Room::addUser(LoggedUser user)
{
	try
	{
		// sdd user to users vector
		this->m_users.push_back(user);

		return SUCCESS;
	}
	catch (...)
	{
		return FAIL;
	}
}

/*
* Funciton gets a logged user and removes it from the room
* Input: user - logged user to remove
* Output: none
*/
void Room::removeUser(LoggedUser user)
{
	// iterate each user
	for (int i = 0; i < this->m_users.size(); i++)
	{
		// check if its the user to remove
		if (this->m_users[i] == user) 
		{
			this->m_users.erase(this->m_users.begin() + i);
		}
	}
}

/*
* Funciton returns the room data
* Input: none
* Output: room data
*/
RoomData Room::getRoomData()
{
	return this->m_metadata;
}

/*
* Funciton returns the users in the room
* Input: none
* Output: room data
*/
std::vector<std::string> Room::getAllUsers()
{
	std::vector<std::string> users;

	// go on all the users in room
	for (int i = 0; i < this->m_users.size(); i++)
	{
		users.push_back(this->m_users[i].getUsername());
	}

	return users;
}

/*
* Funciton returns if game started
* Input: none
* Output: if game started
*/
bool Room::gameStarted()
{
	return this->isInGame;
}

/*
* Funciton starts game
* Input: none
* Output: none
*/
void Room::startGame()
{
	this->isInGame = true;
}

/*
* Funciton stops game
* Input: none
* Output: none
*/
void Room::stopGame()
{
	this->isInGame = false;
	this->m_users.clear();
}
