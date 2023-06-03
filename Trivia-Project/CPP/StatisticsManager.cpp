#include "../Headers/StatisticsManager.h"

StatisticsManager::StatisticsManager(IDataBase* db)
{
	this->m_database = db;
}

std::vector<std::string> StatisticsManager::getHighScore()
{
	return m_database->getHighScores();
}

std::vector<std::string> StatisticsManager::getUserStatistics(std::string username)
{
	std::vector<std::string> stats;	
	stats.push_back(std::to_string(m_database->getPlayerAverageAnswerTime(username)));
	stats.push_back(std::to_string(m_database->getNumOfCorrectAnswers(username)));
	stats.push_back(std::to_string(m_database->getNumOfTotalAnswers(username)));
	stats.push_back(std::to_string(m_database->getNumOfPlayerGames(username)));
	stats.push_back(std::to_string(m_database->getPlayerScore(username)));
	return stats;
}
