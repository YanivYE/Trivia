#include "GameManager.h"

Game GameManager::createGame(Room room)
{
    Game game(m_database->getQuestions(), room.getAllUsers(), room.getId());
    return game;
}

void GameManager::deleteGame(int gameId)
{
}
