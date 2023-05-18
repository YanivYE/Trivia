#pragma once

#include "Communicator.h"
#include "SqliteDatabase.h"
#include "RequestHandlerFactory.h"

class Server
{
public:
	Server(); // constructor for server
	~Server(); // desturctor for server

	void run(int port); // run server

private:
	Communicator* m_communicator; // communicator object
	IDataBase* m_database;
	RequestHandlerFactory* m_handlerFactory;
};