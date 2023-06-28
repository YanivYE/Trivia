#pragma once

#include "IRequestHandler.h";
#include "GameManager.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class GameRequestHandler : public IRequestHandler
{
public:
	GameRequestHandler(RequestHandlerFactory* requestHandlerFactory, LoggedUser user, Game game);

	bool isRequestRelevant(RequestInfo info) override;
	RequestResult handleRequest(RequestInfo info) override;
	RequestResult getQuestion(RequestInfo info);
	RequestResult submitAnswer(RequestInfo info);
	RequestResult getGameResults(RequestInfo info);
	RequestResult leaveGame(RequestInfo info);

private:
	Game m_game;
	LoggedUser m_user;
	GameManager* m_gameManager;
	RequestHandlerFactory* m_handleFactory;
};