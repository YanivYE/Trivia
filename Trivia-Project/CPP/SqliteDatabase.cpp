#include "../Headers/SqliteDatabase.h"

/*
* Function opens a data base for the program
* Output: data base opened or not
*/
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

/*
* Function opens a data base for the program
* Output: data base opened or not
*/
void SqliteDatabase::createTable()
{
	const char* usersTableQuery = "CREATE TABLE users (username TEXT NOT NULL, password TEXT NOT NULL, mail TEXT NOT NULL);";

	char* errMessage = nullptr;
	// execute query
	int res = sqlite3_exec(db, usersTableQuery, nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK)
		std::cerr << errMessage;
}

/*
* Function closes the data base 
* Output: data base closed or not
*/
bool SqliteDatabase::close()
{
    int res = sqlite3_close(db);
    db = nullptr;

	return res;
}

/*
* Function gets if a user exists
* Input: data - additional passed data, in this case, an album list
* argc - number of collums
* argv - array of strings that contains the values of the columns in the current row of the query result
* azColName - array of strings that contains the names of the columns in the current row of the query result
* Output: code 0
*/
int userExistsCallback(void* existsPtr, int argc, char** argv, char** azColName)
{
	int* exists = static_cast<int*>(existsPtr);
	*exists = (argc > 0);
	return 0;
}


/*
* Function checks if a user exists
* Input: name - the user name
* Output: user exists or not
*/
int SqliteDatabase::doesUserExist(std::string name)
{
	int exists = false;
	std::string query = "SELECT * FROM users WHERE username = '" + name + "';";

	char* errMessage = nullptr;
	// execute query
	int res = sqlite3_exec(db, query.c_str(), userExistsCallback, &exists, &errMessage);
	if (res != SQLITE_OK)
	{
		std::cerr << errMessage;
		return false;
	}
		
	return exists;
}

/*
* Function gets the user password
* Input: data - additional passed data, in this case, an album list
* argc - number of collums
* argv - array of strings that contains the values of the columns in the current row of the query result
* azColName - array of strings that contains the names of the columns in the current row of the query result
* Output: code 0
*/
int userPasswordCallback(void* existsPtr, int argc, char** argv, char** azColName)
{
	std::string* password = static_cast<std::string*>(existsPtr);
	*password = argv[0];
	return 0;
}

/*
* Function checks if a user password is equivilant to a given password
* Input: name - the user name
* password - a given password
* Output: password match or not
*/
int SqliteDatabase::doesPasswordMatch(std::string name, std::string password)
{
	if (doesUserExist(name))
		// if the user exists
	{
		std::string userPassword = "";
		std::string query = "SELECT password FROM users WHERE username = '" + name + "';";

		char* errMessage = nullptr;
		// execute query
		int res = sqlite3_exec(db, query.c_str(), userPasswordCallback, &userPassword, &errMessage);
		if (res != SQLITE_OK)
		{
			std::cerr << errMessage;
			return false;
		}
		// return if the passwords match
		return password == userPassword;
	}
	else
	{
		std::cerr << "User doesnt exist";
		return false;
	}
}

/*
* Function adds a new user
* Input: name - the user name
* password - a given password
* mail - user namil
* Output: user added or not
*/
int SqliteDatabase::addNewUser(std::string name, std::string password, std::string mail)
{
	char* errMessage = nullptr;
	std::string query = "INSERT INTO users (username, password, mail) VALUES ('" + name + "','" + password + "','" + mail + "');";
	// execute query
	int res = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK)
	{
		std::cerr << errMessage;
		return false;
	}
	return true;
}
 