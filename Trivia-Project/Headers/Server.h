#pragma once

#include "Communicator.h"

class Server
{
public:
	Server(); // constructor for server
	~Server(); // desturctor for server

	void run(int port); // run server

private:
	Communicator m_communicator;
};