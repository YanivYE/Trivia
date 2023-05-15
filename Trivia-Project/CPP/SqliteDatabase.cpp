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
	if (file_exist != 0)
	{
		// create DB table
		createTable();
	}
    return true;
}

void SqliteDatabase::createTable()
{
	// sql query
	const char* usersTableQuery = "CREATE TABLE users (username TEXT NOT NULL, password TEXT NOT NULL, mail TEXT NOT NULL);";

	char* errMessage = nullptr;
	int res = sqlite3_exec(db, usersTableQuery, nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK)
		std::cerr << errMessage;
}

bool SqliteDatabase::close()
{
    sqlite3_close(db);
    db = nullptr;
}

int userExistsCallback(void* existsPtr, int argc, char** argv, char** azColName)
{
	bool* exists = static_cast<bool*>(existsPtr);
	*exists = (argc > 0);
	return (*exists) ? 1 : 0;
}

int SqliteDatabase::doesUserExist(std::string name)
{
	int exists = FALSE;
	std::string query = "SELECT * FROM users WHERE username = '" + name + "';";

	char* errMessage = nullptr;
	int res = sqlite3_exec(db, query.c_str(), userExistsCallback, &exists, &errMessage);
	if (res != SQLITE_OK)
	{
		std::cerr << errMessage;
		return FALSE;
	}
		
	return exists;
}

int SqliteDatabase::doesPasswordMatch(std::string originalPassword, std::string password)
{
	return 0;
}

int SqliteDatabase::addNewUser(std::string name, std::string password, std::string mail)
{
	char* errMessage = nullptr;
	std::string query = "INSERT INTO users (username, password, mail) VALUES ('" + name + "','" + password + "','" + mail + "');";
	int res = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK)
		std::cerr << errMessage;
}
