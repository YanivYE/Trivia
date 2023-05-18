#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(LoginManager loginManager, IDataBase* database)
{
    m_loginManager = loginManager;
    m_database = database;
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
