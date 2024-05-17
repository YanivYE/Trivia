#include "../Headers/GameManager.h"

Game* GameManager::createGame(Room* room)
{
    QuestionsList* questions = this->m_database->getQuestions(room->getRoomData().numOfQuestionsInGame);
    Game* game = new Game(questions, getPlayers(room, questions), room->getId());
    this->m_games.push_back(game);
    return game;
}

std::map<LoggedUser, GameData*> GameManager::getPlayers(Room* room, QuestionsList* questions)
{
    std::map<LoggedUser, GameData*> players;
    std::vector<std::string> userNames = room->getAllUsers();
    for (const std::string& name : userNames)
    {
        LoggedUser user(name);
        players[user] = new GameData();
        players[user]->score = 0;
        players[user]->isGameFinished = false;
        players[user]->currentQuestion = questions->head;
    }
    return players;
}

void GameManager::deleteGame(int gameId)
{
    for (auto game = this->m_games.begin(); game != this->m_games.end(); )
    {
        if ((*game)->getGameId() == gameId)
        {
            game = this->m_games.erase(game);
        }
        else
        {
            ++game;
        }
    }
}

Game* GameManager::getGameByID(int id)
{
    for (Game* game : this->m_games)
    {
        if (game->getGameId() == id)
        {
            return game;
        }
    }
}

IDataBase* GameManager::getDataBase()
{
    return this->m_database;
}
