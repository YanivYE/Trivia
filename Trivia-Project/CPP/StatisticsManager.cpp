#include "../Headers/StatisticsManager.h"

/*
* Function is ctor for stats manager
* Input: db - data base 
* Output: none
*/
StatisticsManager::StatisticsManager(IDataBase* db)
{
	this->m_database = db;
}

/*
* Function returns high scores from db
* Input: none
* Output: high scores
*/
std::multimap<int, std::string> StatisticsManager::getLeaderboard()
{
	return m_database->getLeaderboard();
}

/*
* Function gets a user name and retrusn its stats
* Input: username - the user - username
* Output: user's stats
*/
std::vector<std::string> StatisticsManager::getUserStatistics(std::string username)
{
	std::vector<std::string> stats;	

	// get all stats
	stats.push_back(std::to_string(m_database->getNumOfPlayerGames(username)));
	stats.push_back(std::to_string(m_database->getNumOfCorrectAnswers(username)));
	stats.push_back(std::to_string(m_database->getNumOfWrongAnswers(username)));
	stats.push_back(std::to_string(m_database->getPlayerAverageAnswerTime(username)));


	return stats;
}
