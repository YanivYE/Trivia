#pragma once

#include "Communicator.h"
#include "SqliteDatabase.h"
#include "RequestHandlerFactory.h"

class Server
{
public:
	static Server& getInstance() {
		static Server instance;
		return instance;
	}

	void run(int port); // run server

private:
	Server() {
		// Private constructor to prevent direct instantiation
		m_database = new SqliteDatabase();
		m_handlerFactory = new RequestHandlerFactory(this->m_database);
		m_communicator = new Communicator(this->m_handlerFactory);
	}

	~Server() {
		delete m_communicator;
		delete m_database;
		delete m_handlerFactory;
	}

	Communicator* m_communicator; // communicator object
	IDataBase* m_database; // data base object
	RequestHandlerFactory* m_handlerFactory; // request handler factory object
};
