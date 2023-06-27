#pragma once

#include "Communicator.h"
#include "SqliteDatabase.h"
#include "RequestHandlerFactory.h"

class Server
{
public:
	// get instance server
	static Server& getInstance() {
		static Server instance;
		return instance;
	}

	void run(int port); // run server

private:
	Server() {
		// Private constructor to prevent direct instantiation
		m_database = &(SqliteDatabase::getInstance());
		m_handlerFactory = &(RequestHandlerFactory::getInstance(this->m_database));
		m_communicator = &(Communicator::getInstance(this->m_handlerFactory));
	}

	// dtor
	~Server() {
		m_database->close();
	}

	Communicator* m_communicator; // communicator object
	IDataBase* m_database; // data base object
	RequestHandlerFactory* m_handlerFactory; // request handler factory object
};
