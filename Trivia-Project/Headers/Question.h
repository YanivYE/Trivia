#pragma once
#include <iostream>
#include <vector>
#include <map>

#define CORRECT_ANSWER_ID 1

class Question
{
public:
	Question();

	std::string getQuestion();
	std::map<unsigned int, std::string> getPossibleAnswers();
	int getCorrectAnswerId();

	void setQuestion(std::string question);
	void setPossibleAnswers(std::vector<std::string> answers);


private:
	std::string m_question;
	std::vector<std::string> m_possibleAnswers;
};