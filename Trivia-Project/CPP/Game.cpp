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

Question Game::getQuestionForUser(LoggedUser user)
{
	Question currentQuestion = this->m_players[user].currentQuestion;
	// set next question
	this->m_questions->head = this->m_questions->head->next;
	if (this->m_questions->head)
	{
		this->m_players[user].currentQuestion = this->m_questions->head->data;
	}

	return currentQuestion;
}

int Game::submitAnswer(LoggedUser user, int answerId)
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
