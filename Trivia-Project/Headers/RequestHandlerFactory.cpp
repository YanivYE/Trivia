#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDataBase* database) : m_loginManager(database)
{
    this->m_database = database;
    this->m_database->open();
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandlers()
{
    return new LoginRequestHandler(this);
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandlers()
{
    return new MenuRequestHandler();
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
    return m_loginManager;
}
