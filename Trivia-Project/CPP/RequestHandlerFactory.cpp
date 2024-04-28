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

/*
* Function returns rerence to room manager
* Input: none
* Output: refrence to room manager
*/
RoomManager& RequestHandlerFactory::getRoomManager()
{
    return *m_roomManager;
}

/*
* Function returns rerence to statistics manager
* Input: none
* Output: refrence to statistics manager
*/
StatisticsManager& RequestHandlerFactory::getStatisticsManager()
{
    return *m_statisticsManager;
}

RoomAdminRequestHandler* RequestHandlerFactory::createRoomAdminRequestHandler(LoggedUser user, Room* room)
{
    return new RoomAdminRequestHandler(this, user, room);
}

RoomMemberRequestHandler* RequestHandlerFactory::createRoomMemberRequestHandler(LoggedUser user, Room* room)
{
    return new RoomMemberRequestHandler(this, user, room);
}

GameRequestHandler* RequestHandlerFactory::createGameRequestHandler(LoggedUser user, Game* game)
{
    return new GameRequestHandler(this, user, game);
}

GameManager& RequestHandlerFactory::getGameManager()
{
    return *m_gameManager;
}

void RequestHandlerFactory::setCommunicator(Communicator* communicator)
{
    this->m_communicator = communicator;
}

void RequestHandlerFactory::setUser(LoggedUser user)
{
    this->m_communicator->setUser(user);
}
