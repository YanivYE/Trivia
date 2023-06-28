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
	Game(std::vector<Question> questions, std::map<LoggedUser, GameData> players, int gameId); // ctor for game

	Question getQuestionForUser(LoggedUser user);
	void submitAnswer(LoggedUser user, int answerId);
	void removePlayer(LoggedUser user);
	int getGameId();
private:
	std::vector<Question> m_questions; 
	std::map<LoggedUser, GameData> m_players;
	int m_gameId;
};