#include "../Headers/Question.h"

Question::Question() {
    this->m_question = "";
}

std::string Question::getQuestion() {
    return this->m_question;
}

std::vector<std::string> Question::getPossibleAnswers() {
    return this->m_possibleAnswers;
}

int Question::getCorrectAnswerId() {
    return CORRECT_ANSWER_ID;
}

void Question::setQuestion(std::string question) {
    this->m_question = question;
}

void Question::setPossibleAnswers(std::vector<std::string> answers) {
    this->m_possibleAnswers = answers;
}

// LinkedList constructor
QuestionsList::QuestionsList() : head(nullptr) {}

// LinkedList destructor
QuestionsList::~QuestionsList() {
    QuestionNode* current = head;
    while (current != nullptr) {
        QuestionNode* next = current->next;
        delete current;
        current = next;
    }
}

// Method to add a question at the end of the list
void QuestionsList::add(const Question& question) {
    QuestionNode* newNode = new QuestionNode(question);
    if (!head) {
        head = newNode;
    }
    else {
        QuestionNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}
