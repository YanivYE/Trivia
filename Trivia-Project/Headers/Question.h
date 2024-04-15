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
};

// Define a node in the linked list
struct Node {
	Question data;
	Node* next;

	Node(const Question& q) : data(q), next(nullptr) {}
};

// Define the linked list
class QuestionsList {
public:
	Node* head;

	QuestionsList();
	~QuestionsList();
	void add(const Question& question);
};