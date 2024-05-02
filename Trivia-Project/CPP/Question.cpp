#include "../Headers/Question.h"

Question::Question() {
    this->m_question = "";
}

std::string Question::getQuestion() {
    return replaceHtmlEntities(this->m_question);
}

std::string Question::replaceHtmlEntities(const std::string& input) {
    std::string result = input;

    // Replace "&#039;" with "'"
    size_t pos = result.find("&#039;");
    while (pos != std::string::npos) {
        result.replace(pos, 6, "'");
        pos = result.find("&#039;", pos + 1);
    }

    // Replace "&quot;" with "\""
    pos = result.find("&quot;");
    while (pos != std::string::npos) {
        result.replace(pos, 6, 1, static_cast<char>(34));
        pos = result.find("&quot;", pos + 1);
    }

    // Replace "&ouml;" with "ö"
    pos = result.find("&ouml;");
    while (pos != std::string::npos) {
        result.replace(pos, 6, "ö");
        pos = result.find("&ouml;", pos + 1);
    }

    return result;
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
