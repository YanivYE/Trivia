#pragma once

#include "Utilities.h"
#include "Question.h"

struct GameData
{
	QuestionNode* currentQuestion;
	int score;
	bool isGameFinished;
} typedef GameData;

class Game
{
public:
	Game(); // empty ctor
	Game(QuestionsList* questions, std::map<LoggedUser, GameData*> players, int gameId); // ctor for game

	QuestionNode* getQuestionForUser(LoggedUser user);
	SubmitAnswerResponse submitAnswer(LoggedUser user, int answerId, int answerPressTime);
	void removePlayer(LoggedUser user);
	int getGameId();
	void getGameResult(LoggedUser user);
private:
	QuestionsList* m_questions;
	std::map<LoggedUser, GameData*> m_players;
	int m_gameId;
};