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
	RequestHandlerFactory(IDataBase* database);

	LoginRequestHandler* createLoginRequestHandlers();
	MenuRequestHandler* createMenuRequestHandlers();

	LoginManager& getLoginManager();
private:
	LoginManager m_loginManager;
	IDataBase* m_database;
};