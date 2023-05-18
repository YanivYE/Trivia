#include "../Headers/SqliteDatabase.h"

SqliteDatabase::SqliteDatabase()
{
}

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
	const char* usersTableQuery = "CREATE TABLE users (username TEXT NOT NULL, password TEXT NOT NULL, mail TEXT NOT NULL);";

	char* errMessage = nullptr;
	int res = sqlite3_exec(db, usersTableQuery, nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK)
		std::cerr << errMessage;
}

bool SqliteDatabase::close()
{
    int res = sqlite3_close(db);
    db = nullptr;

	return res;
}

int userExistsCallback(void* existsPtr, int argc, char** argv, char** azColName)
{
	int* exists = static_cast<int*>(existsPtr);
	*exists = (argc > 0);
	return 0;
}

int SqliteDatabase::doesUserExist(std::string name)
{
	int exists = False;
	std::string query = "SELECT * FROM users WHERE username = '" + name + "';";

	char* errMessage = nullptr;
	int res = sqlite3_exec(db, query.c_str(), userExistsCallback, &exists, &errMessage);
	if (res != SQLITE_OK)
	{
		std::cerr << errMessage;
		return False;
	}
		
	return exists;
}

int userPasswordCallback(void* existsPtr, int argc, char** argv, char** azColName)
{
	std::string* password = static_cast<std::string*>(existsPtr);
	*password = argv[0];
	return 0;
}

int SqliteDatabase::doesPasswordMatch(std::string name, std::string password)
{
	if (doesUserExist(name))
	{
		std::string userPassword = "";
		std::string query = "SELECT password FROM users WHERE username = '" + name + "';";

		char* errMessage = nullptr;
		int res = sqlite3_exec(db, query.c_str(), userPasswordCallback, &userPassword, &errMessage);
		if (res != SQLITE_OK)
		{
			std::cerr << errMessage;
			return False;
		}
		return password == userPassword;
	}
	else
	{
		std::cerr << "User doesnt exist";
		return False;
	}
}

int SqliteDatabase::addNewUser(std::string name, std::string password, std::string mail)
{
	char* errMessage = nullptr;
	std::string query = "INSERT INTO users (username, password, mail) VALUES ('" + name + "','" + password + "','" + mail + "');";
	int res = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK)
	{
		std::cerr << errMessage;
		return False;
	}
	return True;
}
 