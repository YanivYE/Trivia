#include "../Headers/Game.h"

Game::Game()
{
}

Game::Game(QuestionsList* questions, std::map<LoggedUser, GameData*> players, int gameId)
{
	this->m_questions = questions;
	this->m_players = players;
	this->m_gameId = gameId;
}

QuestionNode* Game::getQuestionForUser(LoggedUser user)
{
	QuestionNode* currentQuestion = this->m_players[user]->currentQuestion;
	
	this->m_players[user]->currentQuestion = this->m_players[user]->currentQuestion->next;

	return currentQuestion;
}

SubmitAnswerResponse Game::submitAnswer(LoggedUser user, int answerId, int answerPressTime)
{
	SubmitAnswerResponse submitAnswerResponse;
	int answerScore = 0;
	bool isCorrectAnswer = false;
	QuestionNode* currQuestion = this->m_players[user]->currentQuestion;
	if (currQuestion->data.getCorrectAnswerId() == answerId)
	{
		answerScore = 100 * answerPressTime;
		isCorrectAnswer = true;
	}
	this->m_players[user]->score += answerScore;
	submitAnswerResponse._status = SubmitAnswer;
	submitAnswerResponse._isCorretAnswer = isCorrectAnswer;
	submitAnswerResponse._answerScore = answerScore;
	return submitAnswerResponse;
}

void Game::removePlayer(LoggedUser user)
{
	this->m_players.erase(user);
}

int Game::getGameId()
{
	return this->m_gameId;
}

void Game::getGameResult(LoggedUser user)
{
	int highestScore = 0;
	std::string winner = "";
	this->m_players[user]->isGameFinished = true;
	for (auto player : this->m_players)
	{
		if (player.second->score > highestScore)
		{
			highestScore = player.second->score;
			winner = player.first.getUsername();
		}
		if (!player.second->isGameFinished)
		{
			return;
		}
	}

	std::cout << winner;
	// send update to all users
}
