#include "../Headers/GameRequestHandler.h"

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
    RequestResult result;
    JsonResponsePacketSerializer serializer;
    int returnCode = 0;

    try
    {
        Question question = this->m_game.getQuestionForUser(this->m_user)->data;
        result.newHandler = this->m_handleFactory->createGameRequestHandler(this->m_user, this->m_game);

        if (question.getQuestion() == "")
        {
            ErrorResponse errResponse;
            errResponse._data = "Error! Couldn't get question!";

            result.response = serializer.serializeResponse(errResponse);
        }
        else
        {
            GetQuestionResponse getQuestion;
            getQuestion._status = GetQuestion;
            getQuestion._question = question.getQuestion();
            getQuestion._answers = question.getPossibleAnswers();

            result.response = serializer.serializeResponse(getQuestion);
        }
    }
    catch (std::exception& e)
    {
        result.newHandler = this->m_handleFactory->createGameRequestHandler(this->m_user, this->m_game);

        ErrorResponse errResponse;
        errResponse._data = "Error! Couldn't remove user from room!";

        result.response = serializer.serializeResponse(errResponse);
    }

    return result;
}

RequestResult GameRequestHandler::submitAnswer(RequestInfo info)
{
    SubmitAnswerRequest submitAnswerRequest;
    RequestResult result;
    JsonRequestPacketDeserializer deserializer;
    JsonResponsePacketSerializer serializer;
    int returnCode = 0;

    try
    {
        submitAnswerRequest = deserializer.deserializeSubmitAnswerRequest(info.buffer);
    }
    catch (...)
    {
        ErrorResponse errResponse;
        errResponse._data = "Error! Couldn't parse submit answer request";
        result.response = serializer.serializeResponse(errResponse);
        return result;
    }

    try
    {
        returnCode = this->m_game.submitAnswer(this->m_user, submitAnswerRequest._answerId);

        result.newHandler = this->m_handleFactory->createGameRequestHandler(this->m_user, this->m_game);

        SubmitAnswerResponse submitAnswerResponse;
        submitAnswerResponse._status = returnCode;
        submitAnswerResponse._correctAnswerId = 1;
        result.response = serializer.serializeResponse(submitAnswerResponse);
    }
    catch (std::exception& e)
    {
        result.newHandler = this->m_handleFactory->createGameRequestHandler(this->m_user, this->m_game);

        ErrorResponse errResponse;
        errResponse._data = "Error! Couldn't sign up user to server";

        result.response = serializer.serializeResponse(errResponse);
    }

    return result;
}

RequestResult GameRequestHandler::getGameResults(RequestInfo info)
{
    RequestResult result;
    JsonResponsePacketSerializer serializer;
    int returnCode = 0;

    try
    {        
        std::vector<std::string> results= this->m_handleFactory->getGameManager().getDataBase()->getHighScores();
        if (!results.empty())
        {
            result.newHandler = this->m_handleFactory->createMenuRequestHandlers(this->m_user);
            GetGameResultsResponse getGameResults;
            getGameResults._status = returnCode;

            result.response = serializer.serializeResponse(getGameResults);
        }
        else
        {
            result.newHandler = this->m_handleFactory->createGameRequestHandler(this->m_user, this->m_game);

            ErrorResponse errResponse;
            errResponse._data = "Error! Couldn't get game results!";

            result.response = serializer.serializeResponse(errResponse);
        }
    }
    catch (std::exception& e)
    {
        result.newHandler = this->m_handleFactory->createGameRequestHandler(this->m_user, this->m_game);

        ErrorResponse errResponse;
        errResponse._data = "Error! Couldn't remove user from room!";

        result.response = serializer.serializeResponse(errResponse);
    }

    return result;
}

RequestResult GameRequestHandler::leaveGame(RequestInfo info)
{
    RequestResult result;
    JsonResponsePacketSerializer serializer;
    int returnCode = 0;

    try
    {
        // try to remove user
        returnCode = this->m_handleFactory->getRoomManager().getRoom(this->m_game.getGameId())->removeUser(this->m_user);

        if (returnCode == LeaveRoom)
        {
            result.newHandler = this->m_handleFactory->createMenuRequestHandlers(this->m_user);
            LeaveGameResponse leaveGame;
            leaveGame._status = returnCode;

            result.response = serializer.serializeResponse(leaveGame);
        }
        else
        {
            result.newHandler = this->m_handleFactory->createGameRequestHandler(this->m_user, this->m_game);

            ErrorResponse errResponse;
            errResponse._data = "Error! Couldn't leave game!";

            result.response = serializer.serializeResponse(errResponse);
        }
    }
    catch (std::exception& e)
    {
        result.newHandler = this->m_handleFactory->createGameRequestHandler(this->m_user, this->m_game);

        ErrorResponse errResponse;
        errResponse._data = "Error! Couldn't leave game!";

        result.response = serializer.serializeResponse(errResponse);
    }
    return result;
    
}