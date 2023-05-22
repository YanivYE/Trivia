#include "RequestHandlerFactory.h"

/*
* Function is a ctor for RequestHandlerFactory
* Input: database - the db
* Output: none
*/
RequestHandlerFactory::RequestHandlerFactory(IDataBase* database) : m_loginManager(database)
{
    this->m_database = database;
    this->m_database->open();
}

/*
* Function creates a new login requeest handlers
* Input: none
* Output: pointer to new login requeest handlers
*/
LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandlers()
{
    return new LoginRequestHandler(this);
}

/*
* Function creates a new menu requeest handlers
* Input: none
* Output: pointer to new menu requeest handlers
*/
MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandlers()
{
    return new MenuRequestHandler();
}

/*
* Function returns rerence to login manager
* Input: none
* Output: refrence to login manager
*/
LoginManager& RequestHandlerFactory::getLoginManager()
{
    return m_loginManager;
}
