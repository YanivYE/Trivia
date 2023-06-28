#include "../Headers/Question.h"

std::string Question::getQuestion()
{
    return this->m_question;
}

std::vector<std::string> Question::getPossibleAnswers()
{
    return this->m_possibleAnswers;
}

int Question::getCorrectAnswerId()
{
    return CORRECT_ANSWER_ID;
}

void Question::setQuestion(std::string question)
{
    this->m_question = question;
}

void Question::setPossibleAnswers(std::vector<std::string> answers)
{
    this->m_possibleAnswers = answers;
}
