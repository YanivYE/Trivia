#include "../Headers/SqliteDatabase.h"

/*
* Function executes an SQL query 
* Input: query - sql query
* callback - callback function
* data - callback function parameter
* Output: query succesful or not
*/
bool SqliteDatabase::executeQuery(std::string query, int(*callback)(void*, int, char**, char**), void* data)
{
	char* errMessage = nullptr;
	// execute query
	int res = sqlite3_exec(db, query.c_str(), callback, data, &errMessage);
	if (res != SQLITE_OK)
	{
		// print error msg
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
* Input: data - additional passed data
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

/*
* Function creates the questions table in data base
* Output: none
*/
void SqliteDatabase::createQuestionsTable()
{
	std::string questionsTableQuery = "CREATE TABLE questions (question TEXT NOT NULL, correct_answer TEXT NOT NULL, wrong_answer_1 TEXT NOT NULL, wrong_answer_2 TEXT NOT NULL, wrong_answer_3 TEXT NOT NULL);";
	executeQuery(questionsTableQuery, nullptr, nullptr);
	// insert questions to data base
	insertQuestions();
}

/*
* Function inserts questions to data base questions table
* Output: none
*/
void SqliteDatabase::insertQuestions()
{
	// python command to run python script to add the questions to data base. the scipt uses an api url to get a 
	// json string of 10 random questions and inserts them to data base
	std::string pythonCommand = "python insertDBquestions.py";

	// run the Python script
	int result = system(pythonCommand.c_str());
}

/*
* Function creates the statistics table in data base
* Output: none
*/
void SqliteDatabase::createStatisticsTable()
{
	std::string statisticsTableQuery = "CREATE TABLE statistics (question TEXT NOT NULL, room_number INTEGER NOT NULL, username TEXT NOT NULL, time INTEGER NOT NULL, is_correct_answer INTEGER NOT NULL, score INTEGER NOT NULL);";
	executeQuery(statisticsTableQuery, nullptr, nullptr);
}

/*
* Function gets a list of questions
* Input: data - additional passed data
* argc - number of collums
* argv - array of strings that contains the values of the columns in the current row of the query result
* azColName - array of strings that contains the names of the columns in the current row of the query result
* Output: code 0
*/
int QuestionsCallback(void* data, int argc, char** argv, char** azColName)
{
	std::list<std::string>* list = static_cast<std::list<std::string>*>(data);
	std::string question;
	for (int i = 0; i < argc; i++) {
		if (std::string(azColName[i]) == "question") {
			question = argv[i];
		}
	}
	// add question to list
	list->push_back(question);

	return 0;
}

/*
* Function gets a list of questions from data base
* Input: amount - the amount of questions to get
* Output: question list
*/
std::list<std::string> SqliteDatabase::getQuestions(int amount)
{
	std::list<std::string> questions;
	std::string getQuestionsQuery = "SELECT * FROM questions LIMIT " + std::to_string(amount) + "; ";
	// run the query with the questions callback function
	executeQuery(getQuestionsQuery, QuestionsCallback, &questions);
	return questions;
}

/*
* Function gets the total time of user
* Input: data - additional passed data
* argc - number of collums
* argv - array of strings that contains the values of the columns in the current row of the query result
* azColName - array of strings that contains the names of the columns in the current row of the query result
* Output: code 0
*/
int timeCallback(void* data, int argc, char** argv, char** azColName)
{
	float* time = static_cast<float*>(data);
	for (int i = 0; i < argc; i++) {
		if (std::string(azColName[i]) == "time") {
			// sum up the time in seconds
			*time += std::atoi(argv[i]);
		}
	}
	return 0;
}

/*
* Function gets the total number of answers of user
* Input: data - additional passed data
* argc - number of collums
* argv - array of strings that contains the values of the columns in the current row of the query result
* azColName - array of strings that contains the names of the columns in the current row of the query result
* Output: code 0
*/
int totalUserAnswersCallBAck(void* data, int argc, char** argv, char** azColName)
{
	float* amount = static_cast<float*>(data);
	// set amount as the number of rows from data base
	*amount = argc;
	return 0;
}

/*
* Function gets a player's average time to answer a question
* Input: username - the player name
* Output: avergae time
*/
float SqliteDatabase::getPlayerAverageAnswerTime(std::string username)
{
	float totalTime = 0, amount = 0;
	std::string query = "SELECT * FROM statistics WHERE username = '" + username + "'; ";
	executeQuery(query, timeCallback, &totalTime);
	executeQuery(query, totalUserAnswersCallBAck, &amount);

	// divide the total time by the amount of questions the user answered
	return totalTime / amount;
}

/*
* Function gets the total number of correct answers of user
* Input: data - additional passed data
* argc - number of collums
* argv - array of strings that contains the values of the columns in the current row of the query result
* azColName - array of strings that contains the names of the columns in the current row of the query result
* Output: code 0
*/
int correctAnswersCallback(void* data, int argc, char** argv, char** azColName)
{
	int* count = static_cast<int*>(data);
	for (int i = 0; i < argc; i++) {
		if (std::string(azColName[i]) == "is_correct_answer") {
			if (std::atoi(argv[i]) == correct)
				// if the answer is correct
			{
				// raise the answers count
				count++;
			}
		}
	}
	return 0;
}

/*
* Function gets a player's number of correct answers
* Input: username - the player name
* Output: correct answers
*/
int SqliteDatabase::getNumOfCorrectAnswers(std::string username)
{
	int correctAnswersCount = 0;
	std::string getCorrectAnswersQuery = "SELECT * FROM statistics WHERE username = '" + username + "'; ";
	executeQuery(getCorrectAnswersQuery, correctAnswersCallback, &correctAnswersCount);
	return correctAnswersCount;
}

/*
* Function gets a player's number of answers
* Input: username - the player name
* Output: answers
*/
int SqliteDatabase::getNumOfTotalAnswers(std::string username)
{
	int amount = 0;
	std::string query = "SELECT * FROM statistics WHERE username = '" + username + "'; ";
	executeQuery(query, totalUserAnswersCallBAck, &amount);
	return amount;
}

/*
* Function gets a player's number of games
* Input: username - the player name
* Output: games
*/
int SqliteDatabase::getNumOfPlayerGames(std::string username)
{
	// divide the number of answers in all games by the number of questions
	return getNumOfTotalAnswers(username) / NUM_OF_QUESTIONS;
}

/*
* Function gets the total acore of a player
* Input: data - additional passed data
* argc - number of collums
* argv - array of strings that contains the values of the columns in the current row of the query result
* azColName - array of strings that contains the names of the columns in the current row of the query result
* Output: code 0
*/
int scoreCallback(void* data, int argc, char** argv, char** azColName)
{
	int* score = static_cast<int*>(data);
	for (int i = 0; i < argc; i++) {
		if (std::string(azColName[i]) == "score") {
			// add to total score
			*score += std::atoi(argv[i]);
		}
	}
	return 0;
}

/*
* Function gets a player's score
* Input: username - the player name
* Output: score
*/
int SqliteDatabase::getPlayerScore(std::string username)
{
	int totalPlayerScore = 0;
	std::string query = "SELECT * FROM statistics WHERE username = '" + username + "'; ";
	executeQuery(query, scoreCallback, &totalPlayerScore);
	return totalPlayerScore;
}

/*
* Function gets the scores of all users 
* Input: data - additional passed data
* argc - number of collums
* argv - array of strings that contains the values of the columns in the current row of the query result
* azColName - array of strings that contains the names of the columns in the current row of the query result
* Output: code 0
*/
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
	// insert a score of user to map
	(*scores).insert(std::make_pair(score, username));

	return 0;
}

/*
* Function gets a the top players scores
* Output: high scores table
*/
std::vector<std::string> SqliteDatabase::getHighScores()
{
	// set a multimap of scores and their users
	std::multimap<int, std::string> usersScores;
	std::string query = "SELECT * FROM statistics";
	executeQuery(query, usersScoresCallback, &usersScores);

	return getHighScoresTable(combineUserScores(usersScores));
}

std::multimap<int, std::string> combineUserScores(const std::multimap<int, std::string>& scoresMap) {
	std::multimap<std::string, int> combinedScoresMap;

	// Combine scores for each username
	for (const auto& pair : scoresMap) {
		const std::string& username = pair.second;
		int score = pair.first;

		// Find the range of scores for the current username
		auto range = combinedScoresMap.equal_range(username);

		// Check if the username already exists in the combined scores map
		bool found = false;
		for (auto it = range.first; it != range.second; ++it) {
			if (it->first == username) {
				// Add the score to the existing entry for the username
				it->second += score;
				found = true;
				break;
			}
		}

		// If the username was not found, add a new entry to the combined scores map
		if (!found) {
			combinedScoresMap.insert(std::make_pair(username, score));
		}
	}

	// Create a new multimap with combined scores as keys and usernames as values
	std::multimap<int, std::string> combinedMap;
	for (const auto& pair : combinedScoresMap) {
		combinedMap.insert(std::make_pair(pair.second, pair.first));
	}

	return combinedMap;
}

/*
* Function gets a the top players scores, in a vector of user score string
* Output: high scores table
*/
std::vector<std::string> SqliteDatabase::getHighScoresTable(std::multimap<int, std::string> scores)
{
	std::vector<std::string> topUsers;
	std::multimap<int, std::string>::iterator it;
	for (it = scores.begin(); it != scores.end(); ++it) 
	{
		std::string userHighScore = it->second + ": " + std::to_string(it->first);
		// add players from the top of the multimap
		topUsers.push_back(userHighScore);
		if (topUsers.size() == 3) 
			// when reached the size of 3, break and stop inserting to vector
			break;
	}
	return topUsers;
}
