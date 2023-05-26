#pragma once

#include <map>
#include "Room.h"
#include "Utilities.h"

class RoomManager
{
public:
	void createRoom(LoggedUser user, RoomData roomData); // create new room
	void deleteRoom(int ID); // delete room

	unsigned int getRoomState(int ID); // is room in game or waiting for game

	std::vector<RoomData> getRooms(); // return all rooms
	Room& getRoom(int ID); // get room object by id
private:
	std::map<int, Room> m_rooms; // map of rooms and id
};