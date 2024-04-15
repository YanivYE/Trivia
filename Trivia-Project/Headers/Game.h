#pragma once

#include "Utilities.h"
#include "Question.h"

struct GameData
{
	Question currentQuestion;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	float averageAnswerTime;
} typedef GameData;

class Game
{
public:
	Game(); // empty ctor
	Game(QuestionsList* questions, std::map<LoggedUser, GameData> players, int gameId); // ctor for game

	Question getQuestionForUser(LoggedUser user);
	int submitAnswer(LoggedUser user, int answerId);
	void removePlayer(LoggedUser user);
	int getGameId();
private:
	QuestionsList* m_questions;
	std::map<LoggedUser, GameData> m_players;
	int m_gameId;
};