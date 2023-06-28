#include "GameManager.h"

Game GameManager::createGame(Room room)
{
    Game game(m_database->getQuestions(room.getRoomData().numOfQuestionsInGame), getPlayers(room), room.getId());
    this->m_games.push_back(game);
    return game;
}

std::map<LoggedUser, GameData> GameManager::getPlayers(Room room)
{
    std::map<LoggedUser, GameData> players;
    std::vector<std::string> userNames = room.getAllUsers();
    for (std::string name : userNames)
    {
        LoggedUser user(name);
        players[user] = GameData();
        players[user].averageAnswerTime = 0;
        players[user].correctAnswerCount = 0;
        players[user].wrongAnswerCount = 0;
        players[user].currentQuestion = Question();
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
