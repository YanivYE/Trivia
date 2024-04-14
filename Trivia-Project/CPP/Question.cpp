#include "../Headers/Question.h"

Question::Question()
{
    this->m_question = "";
}

std::string Question::getQuestion()
{
    return this->m_question;
}

std::map<unsigned int, std::string> Question::getPossibleAnswers()
{
    unsigned int id = 1;
    std::map<unsigned int, std::string> answersMap;

    for (auto& answer : this->m_possibleAnswers)
    {
        answersMap[id++] = answer;
    }

    return answersMap;
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
