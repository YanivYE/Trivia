#pragma once

#include <map>
#include "Room.h"
#include "Utilities.h"

class RoomManager
{
public:
	void createRoom(LoggedUser user, RoomData roomData);
	void deleteRoom(int ID);

	unsigned int getRoomState(int ID);

	std::vector<RoomData> getRooms();
	Room& getRoom(int ID);
private:
	std::map<int, Room> m_rooms;
};