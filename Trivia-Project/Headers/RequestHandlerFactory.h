#pragma once

#include "RoomMemberRequestHandler.h"
#include "RoomAdminRequestHandler.h"
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "IDataBase.h"
#include "LoginManager.h"

class LoginRequestHandler;
class MenuRequestHandler;
class RoomAdminRequestHandler;

class RequestHandlerFactory
{
public:
	// get instance of request handler factory
	static RequestHandlerFactory& getInstance(IDataBase* database)
	{
		static RequestHandlerFactory instance(database);
		return instance;
	}

	// destroy of request handler factory
	static void destroyInstance() {
		RequestHandlerFactory& instance = getInstance(nullptr);
		delete& instance;
	}

	LoginRequestHandler* createLoginRequestHandlers(); // create login request handlers
	MenuRequestHandler* createMenuRequestHandlers(LoggedUser user); // create menu reuqest handlers

	LoginManager& getLoginManager(); // return login manager 
	RoomManager& getRoomManager(); // return room manager
	StatisticsManager& getStatisticsManager(); // return stats manager

	RoomAdminRequestHandler* createRoomAdminRequestHandler(LoggedUser user, Room room);
	RoomMemberRequestHandler* createRoomMemberRequestHandler(LoggedUser user, Room room);
private:
	// ctor
	RequestHandlerFactory(IDataBase* database) : m_loginManager()
	{
		this->m_database = database;
		this->m_database->open();
		this->m_loginManager = &(LoginManager::getInstance(m_database));
		this->m_statisticsManager = new StatisticsManager(m_database);
		this->m_roomManager = new RoomManager();
	}

	// dtor
	~RequestHandlerFactory()
	{
		destroyInstance();
		this->m_database->close();
	}

	LoginManager* m_loginManager;
	IDataBase* m_database;
	RoomManager* m_roomManager;
	StatisticsManager* m_statisticsManager;
};
