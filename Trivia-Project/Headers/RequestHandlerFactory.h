#pragma once

#include "RoomMemberRequestHandler.h"
#include "RoomAdminRequestHandler.h"
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "Communicator.h"
#include "IDataBase.h"
#include "LoginManager.h"
#include "GameRequestHandler.h"
#include "GameManager.h"

class LoginRequestHandler;
class MenuRequestHandler;
class RoomAdminRequestHandler;
class RoomMemberRequestHandler;
class Communicator;
class GameRequestHandler;

class RequestHandlerFactory
{
public:
	// get instance of request handler factory
	static RequestHandlerFactory& getInstance(IDataBase* database)
	{
		static RequestHandlerFactory instance(database);
		return instance;
	}

	LoginRequestHandler* createLoginRequestHandlers(); // create login request handlers
	MenuRequestHandler* createMenuRequestHandlers(LoggedUser user); // create menu reuqest handlers

	LoginManager& getLoginManager(); // return login manager 
	RoomManager& getRoomManager(); // return room manager
	StatisticsManager& getStatisticsManager(); // return stats manager
	GameManager& getGameManager(); // return game manager

	RoomAdminRequestHandler* createRoomAdminRequestHandler(LoggedUser user, Room& room);
	RoomMemberRequestHandler* createRoomMemberRequestHandler(LoggedUser user, Room& room);
	void setCommunicator(Communicator* communicator);
	void setUser(LoggedUser user);

	GameRequestHandler* createGameRequestHandler(LoggedUser user, Game game);

private:
	// ctor
	RequestHandlerFactory(IDataBase* database) : m_loginManager()
	{
		this->m_database = database;
		this->m_database->open();
		this->m_loginManager = &(LoginManager::getInstance(m_database));
		this->m_statisticsManager = new StatisticsManager(m_database);
		this->m_roomManager = new RoomManager();
		this->m_gameManager = &(GameManager::getInstance(m_database));
	}

	// dtor
	~RequestHandlerFactory()
	{
		this->m_database->close();
	}

	LoginManager* m_loginManager;
	IDataBase* m_database;
	RoomManager* m_roomManager;
	GameManager* m_gameManager;
	StatisticsManager* m_statisticsManager;
	Communicator* m_communicator;
};
