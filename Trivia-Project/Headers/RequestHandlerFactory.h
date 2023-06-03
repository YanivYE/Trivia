#pragma once

#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "IDataBase.h"
#include "LoginManager.h"

class LoginRequestHandler;
class MenuRequestHandler;

class RequestHandlerFactory
{
public:
	static RequestHandlerFactory& getInstance(IDataBase* database)
	{
		static RequestHandlerFactory instance(database);
		return instance;
	}

	static void destroyInstance() {
		RequestHandlerFactory& instance = getInstance(nullptr);
		delete& instance;
	}

	LoginRequestHandler* createLoginRequestHandlers();
	MenuRequestHandler* createMenuRequestHandlers(LoggedUser user);

	LoginManager& getLoginManager();
	RoomManager& getRoomManager();
	StatisticsManager& getStatisticsManager();

private:
	RequestHandlerFactory(IDataBase* database) : m_loginManager()
	{
		this->m_database = database;
		this->m_database->open();
		this->m_loginManager = &(LoginManager::getInstance(m_database));
		this->m_statisticsManager = new StatisticsManager(m_database);
		this->m_roomManager = new RoomManager();
	}

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
