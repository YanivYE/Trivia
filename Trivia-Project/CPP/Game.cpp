#include "../Headers/Game.h"

Game::Game()
{
}

Game::Game(QuestionsList* questions, std::map<LoggedUser, GameData> players, int gameId)
{
	this->m_questions = questions;
	this->m_players = players;
	this->m_gameId = gameId;
}

QuestionNode* Game::getQuestionForUser(LoggedUser user)
{
	QuestionNode* currentQuestion = this->m_players[user].currentQuestion;
	
	this->m_players[user].currentQuestion = this->m_players[user].currentQuestion->next;

	return currentQuestion;
}

int Game::submitAnswer(LoggedUser user, int answerId)
{
	QuestionNode* currQuestion = this->m_players[user].currentQuestion;
	if (currQuestion->data.getCorrectAnswerId() == answerId)
	{
		this->m_players[user].correctAnswerCount += 1;
	}
	else
	{
		this->m_players[user].wrongAnswerCount += 1;
	}
	return SubmitAnswer;
}

void Game::removePlayer(LoggedUser user)
{
	this->m_players.erase(user);
}

int Game::getGameId()
{
	return this->m_gameId;
}