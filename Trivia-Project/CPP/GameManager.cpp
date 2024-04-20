#include "../Headers/GameManager.h"

Game GameManager::createGame(Room* room)
{
    QuestionsList* questions = this->m_database->getQuestions(room->getRoomData().numOfQuestionsInGame);
    Game game(questions, getPlayers(room, questions), room->getId());
    this->m_games.push_back(game);
    return game;
}

std::map<LoggedUser, GameData> GameManager::getPlayers(Room* room, QuestionsList* questions)
{
    std::map<LoggedUser, GameData> players;
    std::vector<std::string> userNames = room->getAllUsers();
    for (const std::string& name : userNames)
    {
        LoggedUser user(name);
        players[user] = GameData();
        players[user].averageAnswerTime = 0;
        players[user].correctAnswerCount = 0;
        players[user].wrongAnswerCount = 0;
        players[user].currentQuestion = questions->head->data;
    }
    return players;
}

void GameManager::deleteGame(int gameId)
{
    for (auto game = this->m_games.begin(); game != this->m_games.end(); ++game)
    {
        if (game->getGameId() == gameId)
        {
           game = this->m_games.erase(game);
        }
    }
}

IDataBase* GameManager::getDataBase()
{
    return this->m_database;
}
