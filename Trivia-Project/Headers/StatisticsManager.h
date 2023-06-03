#pragma once

#include <stdio.h>
#include <vector>
#include "IDataBase.h"

class StatisticsManager
{
public:
	StatisticsManager(IDataBase* db);

	std::vector<std::string> getHighScore();
	std::vector<std::string> getUserStatistics(std::string username);
private:
	IDataBase* m_database;
};	