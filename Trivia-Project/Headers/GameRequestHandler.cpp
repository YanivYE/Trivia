#include "GameRequestHandler.h"

GameRequestHandler::GameRequestHandler(RequestHandlerFactory* requestHandlerFactory, LoggedUser user, Game game)
{
    this->m_handleFactory = requestHandlerFactory;
    this->m_gameManager = &requestHandlerFactory->getGameManager();
    this->m_user = user;
    this->m_game = game;
}

bool GameRequestHandler::isRequestRelevant(RequestInfo info)
{
    return info.requestId == LeaveGame || info.requestId == GetQuestion || 
        info.requestId == SubmitAnswer || info.requestId == GetGameResult;
}

RequestResult GameRequestHandler::handleRequest(RequestInfo info)
{
    if (isRequestRelevant(info))
    {
        switch (info.requestId)
        {
        case LeaveGame:
            return leaveGame(info);
        case GetQuestion:
            return getQuestion(info);
        case SubmitAnswer:
            return submitAnswer(info);
        case GetGameResult:
            return getGameResults(info);
        }
    }
}

RequestResult GameRequestHandler::getQuestion(RequestInfo info)
{
    return RequestResult();
}

RequestResult GameRequestHandler::submitAnswer(RequestInfo info)
{
    return RequestResult();
}

RequestResult GameRequestHandler::getGameResults(RequestInfo info)
{
    return RequestResult();
}

RequestResult GameRequestHandler::leaveGame(RequestInfo info)
{
    return RequestResult();
}
