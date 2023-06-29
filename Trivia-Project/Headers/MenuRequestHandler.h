#pragma once

#include "IRequestHandler.h";
#include "RoomManager.h";
#include "StatisticsManager.h";
#include "RequestHandlerFactory.h";
#include "Utilities.h"

class JsonResponsePacketSerializer;
class RequestHandlerFactory;

class MenuRequestHandler : public IRequestHandler
{
public:
	MenuRequestHandler(RequestHandlerFactory* factory, LoggedUser user); // ctor

	bool isRequestRelevant(RequestInfo info) override; // is request relevant
	RequestResult handleRequest(RequestInfo info) override; // handle request

	RequestResult signout(RequestInfo info); // signout request
	RequestResult getRooms(RequestInfo info); // get rooms request
	RequestResult getPlayersInRoom(RequestInfo info); // get players in room request
	RequestResult getPersonalStats(RequestInfo info); // get personal stats request
	RequestResult getLeaderboard(RequestInfo info); // get personal stats request
	RequestResult getHighScore(RequestInfo info); // get high score request
	RequestResult joinRoom(RequestInfo info); // join room request
	RequestResult createRoom(RequestInfo info); // create room request
private:
	// return error 
	RequestResult returnError(RequestResult& result, std::string errorMsg, JsonResponsePacketSerializer serializer);

	LoggedUser m_user; // logged user
	RoomManager* m_roomManager; // room manager 
	StatisticsManager* m_statisticsManager; // stats manager
	RequestHandlerFactory* m_handlerFactory; // request handler
};
