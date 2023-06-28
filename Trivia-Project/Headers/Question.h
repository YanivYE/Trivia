#pragma once
#include <iostream>
#include <vector>

#define CORRECT_ANSWER_ID 1

class Question
{
public:
	std::string getQuestion();
	std::vector<std::string> getPossibleAnswers();
	int getCorrectAnswerId();

	void setQuestion(std::string question);
	void setPossibleAnswers(std::vector<std::string> answers);


private:
	std::string m_question;
	std::vector<std::string> m_possibleAnswers;
};