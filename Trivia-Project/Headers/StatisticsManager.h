#pragma once

#include <stdio.h>
#include <vector>
#include "IDataBase.h"

class StatisticsManager
{
public:
	// ctor
	StatisticsManager(IDataBase* db);

	// get high score
	std::multimap<int, std::string> getLeaderboard();
	std::vector<std::string> getUserStatistics(std::string username); // get user stats
private:
	IDataBase* m_database; // db
};	