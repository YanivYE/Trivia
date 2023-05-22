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
	RequestHandlerFactory(IDataBase* database); // ctor for request handler factory

	LoginRequestHandler* createLoginRequestHandlers(); // create login request handlers
	MenuRequestHandler* createMenuRequestHandlers(); // create menu request handlers

	LoginManager& getLoginManager(); // return login manager
private:
	LoginManager m_loginManager; // login manager
	IDataBase* m_database; // db
};