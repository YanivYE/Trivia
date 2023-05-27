#include "../Headers/RoomManager.h"

/*
* Function creates a new rooms with a user and by room data
* Input: user - the user that created the room
*		 roomData - the room data
* Output: none
*/
void RoomManager::createRoom(LoggedUser user, RoomData roomData)
{
	Room room(roomData.name, roomData.maxPlayers, roomData.timePerQuestion);

	room.addUser(user);

	// add new room to map
	m_rooms.insert(std::pair<int, Room>(roomData.id, room));
}

/*
* Function deletes room by id
* Input: ID - the id of the room to delete
* Output: none
*/
void RoomManager::deleteRoom(int ID)
{
	m_rooms[ID].stopGame();
	m_rooms.erase(ID);
}

/*
* Function returns room state by room id
* Input: ID - the id of the room to gets its state
* Output: the room state
*/
unsigned int RoomManager::getRoomState(int ID)
{
	if (this->m_rooms[ID].gameStarted())
	{
		return inGame;
	}
	
	return waitingToStart;
}

/*
* Function returns all the rooms
* Input: none
* Output: vector of all the rooms
*/
std::vector<RoomData> RoomManager::getRooms()
{
	RoomData data;
	std::vector<RoomData> rooms;

	for (auto i : m_rooms)
	{
		// add room to vector
		rooms.push_back(i.second.getRoomData());
	}

	return rooms;
}

/*
* Function returns a room by id
* Input: id - the id of the room to return
* Output: the room by id
*/
Room& RoomManager::getRoom(int ID)
{
	for (auto i : m_rooms)   
	{
		// check if id is this
		if (i.first == ID)
		{
			return i.second;
		}
	}
}