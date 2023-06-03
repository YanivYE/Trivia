#include "../Headers/SqliteDatabase.h"


bool SqliteDatabase::executeQuery(std::string query, int(*callback)(void*, int, char**, char**), void* data)
{
	char* errMessage = nullptr;
	// execute query
	int res = sqlite3_exec(db, query.c_str(), callback, data, &errMessage);
	if (res != SQLITE_OK)
	{
		std::cerr << errMessage;
		return false;
	}
	return true;
}

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
		createDBTables();
	}
	return true;
}

void SqliteDatabase::createDBTables()
{
	createUsersTable();
	createQuestionsTable();
	createStatisticsTable();
}

/*
* Function opens a data base for the program
* Output: data base opened or not
*/
void SqliteDatabase::createUsersTable()
{
	std::string usersTableQuery = "CREATE TABLE users (username TEXT NOT NULL, password TEXT NOT NULL, mail TEXT NOT NULL);";
	executeQuery(usersTableQuery, nullptr, nullptr);
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
	std::string userExistsQuery = "SELECT * FROM users WHERE username = '" + name + "';";

	if (!executeQuery(userExistsQuery, userExistsCallback, &exists))
	{
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
		std::string passwordsMatchQuery = "SELECT password FROM users WHERE username = '" + name + "';";

		if (!executeQuery(passwordsMatchQuery, userPasswordCallback, &userPassword))
		{
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
	std::string addUserQuery = "INSERT INTO users (username, password, mail) VALUES ('" + name + "','" + password + "','" + mail + "');";
	return executeQuery(addUserQuery, nullptr, nullptr);
}

void SqliteDatabase::createQuestionsTable()
{
	std::string questionsTableQuery = "CREATE TABLE questions (question TEXT NOT NULL, correct_answer TEXT NOT NULL, wrong_answer_1 TEXT NOT NULL, wrong_answer_2 TEXT NOT NULL, wrong_answer_3 TEXT NOT NULL);";
	executeQuery(questionsTableQuery, nullptr, nullptr);
	insertQuestions();
}

void SqliteDatabase::insertQuestions()
{
	std::string pythonCommand = "python insertDBquestions.py";

	// Run the Python script
	int result = system(pythonCommand.c_str());
}

void SqliteDatabase::createStatisticsTable()
{
	const char* statisticsTableQuery = "CREATE TABLE statistics (question TEXT NOT NULL, room_number INTEGER NOT NULL, username TEXT NOT NULL, time INTEGER NOT NULL, is_correct_answer INTEGER NOT NULL, score INTEGER NOT NULL);";
	executeQuery(statisticsTableQuery, nullptr, nullptr);
}

int QuestionsCallback(void* data, int argc, char** argv, char** azColName)
{
	std::list<std::string>* list = static_cast<std::list<std::string>*>(data);
	std::string question;
	for (int i = 0; i < argc; i++) {
		if (std::string(azColName[i]) == "question") {
			question = argv[i];
		}
	}
	list->push_back(question);

	return 0;
}


std::list<std::string> SqliteDatabase::getQuestions(int amount)
{
	std::list<std::string> questions;
	std::string getQuestionsQuery = "SELECT * FROM questions LIMIT " + std::to_string(amount) + "; ";
	executeQuery(getQuestionsQuery, QuestionsCallback, &questions);
	return questions;
}

int timeCallback(void* data, int argc, char** argv, char** azColName)
{
	float* time = static_cast<float*>(data);
	for (int i = 0; i < argc; i++) {
		if (std::string(azColName[i]) == "time") {
			*time += std::atoi(argv[i]);
		}
	}
	return 0;
}

int totalUserAnswersCallBAck(void* data, int argc, char** argv, char** azColName)
{
	float* amount = static_cast<float*>(data);
	*amount = argc;
	return 0;
}

float SqliteDatabase::getPlayerAverageAnswerTime(std::string username)
{
	float totalTime = 0;
	float amount = 0;
	std::string query = "SELECT * FROM statistics WHERE username = '" + username + "'; ";
	executeQuery(query, timeCallback, &totalTime);
	executeQuery(query, totalUserAnswersCallBAck, &amount);

	return totalTime / amount;
}

int correctAnswersCallback(void* data, int argc, char** argv, char** azColName)
{
	int* count = static_cast<int*>(data);
	for (int i = 0; i < argc; i++) {
		if (std::string(azColName[i]) == "is_correct_answer") {
			if (std::atoi(argv[i]) == correct)
			{
				count++;
			}
		}
	}
	return 0;
}

int SqliteDatabase::getNumOfCorrectAnswers(std::string username)
{
	int correctAnswersCount = 0;
	std::string getCorrectAnswersQuery = "SELECT * FROM statistics WHERE username = '" + username + "'; ";
	executeQuery(getCorrectAnswersQuery, correctAnswersCallback, &correctAnswersCount);
	return correctAnswersCount;
}

int SqliteDatabase::getNumOfTotalAnswers(std::string username)
{
	int amount = 0;
	std::string query = "SELECT * FROM statistics WHERE username = '" + username + "'; ";
	executeQuery(query, totalUserAnswersCallBAck, &amount);
	return amount;
}

int SqliteDatabase::getNumOfPlayerGames(std::string username)
{
	return getNumOfTotalAnswers(username) / NUM_OF_QUESTIONS;
}


int scoreCallback(void* data, int argc, char** argv, char** azColName)
{
	int* score = static_cast<int*>(data);
	for (int i = 0; i < argc; i++) {
		if (std::string(azColName[i]) == "score") {
			*score += std::atoi(argv[i]);
		}
	}
	return 0;
}

int SqliteDatabase::getPlayerScore(std::string username)
{
	int totalPlayerScore = 0;
	std::string query = "SELECT * FROM statistics WHERE username = '" + username + "'; ";
	executeQuery(query, scoreCallback, &totalPlayerScore);
	return totalPlayerScore;
}

int usersScoresCallback(void* data, int argc, char** argv, char** azColName)
{
	std::string username = "";
	int score = 0;
	std::multimap<int, std::string>* scores = static_cast<std::multimap<int, std::string>*>(data);
	for (int i = 0; i < argc; i++) {
		if (std::string(azColName[i]) == "username") {
			username = argv[i];
		}
		else if (std::string(azColName[i]) == "score") {
			score = std::atoi(argv[i]);
		}	
	}
	(*scores).insert(std::make_pair(score, username));

	return 0;
}

std::vector<std::string> SqliteDatabase::getHighScores()
{
	std::multimap<int, std::string> usersScores;
	std::string query = "SELECT * FROM statistics";
	executeQuery(query, usersScoresCallback, &usersScores);

	return getHighScoresTable(usersScores);
}

std::vector<std::string> getHighScoresTable(std::multimap<int, std::string> scores)
{
	std::vector<std::string> topUsers;
	std::multimap<int, std::string>::iterator it;
	for (it = scores.begin(); it != scores.end(); ++it) 
	{
		std::string userHighScore = it->second + ": " + std::to_string(it->first);
		topUsers.push_back(userHighScore);
		if (topUsers.size() == 5) 
			break;
	}
	return topUsers;
}
