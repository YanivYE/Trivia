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
	std::vector<std::string> getPossibleAnswers();
	int getCorrectAnswerId();

	void setQuestion(std::string question);
	void setPossibleAnswers(std::vector<std::string> answers);


private:
	std::string m_question;
	std::vector<std::string> m_possibleAnswers;

	std::string replaceHtmlEntities(const std::string& input);
};

// Define a node in the linked list
struct QuestionNode {
	Question data;
	QuestionNode* next;

	QuestionNode(const Question& q) : data(q), next(nullptr) {}
};

// Define the linked list
class QuestionsList {
public:
	QuestionNode* head;

	QuestionsList();
	~QuestionsList();
	void add(const Question& question);
};