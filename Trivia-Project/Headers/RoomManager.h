#pragma once

#include <map>
#include "Room.h"

class RoomManager
{
public:
private:
	std::map<int, Room> m_rooms;
};