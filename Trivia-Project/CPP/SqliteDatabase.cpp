#include "../Headers/SqliteDatabase.h"

bool SqliteDatabase::open()
{
	std::string dbFileName = DB_NAME;
	// get doest DB exists
	int file_exist = _access(dbFileName.c_str(), 0);
	// open DB
	int res = sqlite3_open(dbFileName.c_str(), &db);
	if (res != SQLITE_OK) {
		db = nullptr;
		std::cout << "Failed to open DB" << std::endl;
		return false;
	}
    return true;
}

bool SqliteDatabase::close()
{
    sqlite3_close(db);
    db = nullptr;
}

int SqliteDatabase::doesUserExist(std::string name)
{
	return 0;
}

int SqliteDatabase::doesPasswordMatch(std::string originalPassword, std::string password)
{
	return 0;
}

int SqliteDatabase::addNewUser(std::string name, std::string password, std::string mail)
{
	return 0;
}
