#include "Game.h"

Game::Game()
{
}

Game::Game(std::vector<Question> questions, std::map<LoggedUser, GameData> players, int gameId)
{
	this->m_questions = questions;
	this->m_players = players;
	this->m_gameId = gameId;
}

Question Game::getQuestionForUser(LoggedUser user)
{
	return this->m_players[user].currentQuestion;
}

void Game::submitAnswer(LoggedUser user, int answerId)
{
	Question currQuestion = this->m_players[user].currentQuestion;
	if (currQuestion.getCorrectAnswerId() == answerId)
	{
		this->m_players[user].correctAnswerCount += 1;
	}
	else
	{
		this->m_players[user].wrongAnswerCount += 1;
	}
}

void Game::removePlayer(LoggedUser user)
{
	this->m_players.erase(user);
}
