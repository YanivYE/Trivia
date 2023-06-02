#include "../Headers/RequestHandlerFactory.h"

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
MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandlers(LoggedUser user)
{
    return new MenuRequestHandler(this, user);
}

/*
* Function returns rerence to login manager
* Input: none
* Output: refrence to login manager
*/
LoginManager& RequestHandlerFactory::getLoginManager()
{
    return *m_loginManager;
}

RoomManager& RequestHandlerFactory::getRoomManager()
{
    return *m_roomManager;
}

StatisticsManager& RequestHandlerFactory::getStatisticsManager()
{
    return *m_statisticsManager;
}
