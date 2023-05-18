#pragma once

#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "IDataBase.h"
#include "LoginManager.h"

class RequestHandlerFactory
{
public:
	RequestHandlerFactory(LoginManager loginManager, IDataBase* database);

	LoginRequestHandler* createLoginRequestHandlers();
	MenuRequestHandler* createMenuRequestHandlers();
	LoginManager& getLoginManager();
private:
	LoginManager m_loginManager;
	IDataBase* m_database;
};