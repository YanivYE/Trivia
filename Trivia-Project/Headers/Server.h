#pragma once

#include "Communicator.h"

class Server
{
public:
	Server();
	~Server();

	void run(int port);

private:
	Communicator m_communicator;
};