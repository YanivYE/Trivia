#include "../Headers/RoomManager.h"

void RoomManager::createRoom(LoggedUser user, RoomData roomData)
{
	Room room(roomData.name, roomData.maxPlayers, roomData.timePerQuestion);

	room.addUser(user);

	m_rooms.insert(std::pair<int, Room>(roomData.id, room));
}

void RoomManager::deleteRoom(int ID)
{
	m_rooms.erase(ID);
}

unsigned int RoomManager::getRoomState(int ID)
{
	if (m_rooms[ID].getAllUsers().size() > 1)
	{
		return inGame;
	}

	return waitingToStart;
}

std::vector<RoomData> RoomManager::getRooms()
{
	RoomData data;
	std::vector<RoomData> rooms;

	for (auto i : m_rooms)
	{
		rooms.push_back(i.second.getRoomData());
	}

	return rooms;
}

Room& RoomManager::getRoom(int ID)
{
	for (auto i : m_rooms)   
	{
		if (i.first == ID)
		{
			return i.second;
		}
	}
}
