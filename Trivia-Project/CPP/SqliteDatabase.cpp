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
	std::string usersTableQuery = "CREATE TABLE users (username TEXT NOT NULL, password TEXT NOT NULL, mail TEXT NOT NULL, games_played INTEGER NOT NULL);";
	executeQuery(usersTableQuery, nullptr, nullptr);
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
	// update by scrmbling all question somehow, and adding more
	// python command to run python script to add the questions to data base. the scipt uses an api url to get a 
	// json string of 10 random questions and inserts them to data base
	std::system("python insertDBquestions.py");
	// MIGHT NOT WORK, RUN THE SCRYPT MANUALY
}

/*
* Function creates the statistics table in data base
* Output: none
*/
void SqliteDatabase::createStatisticsTable()
{
	std::string statisticsTableQuery = "CREATE TABLE statistics (username TEXT NOT NULL, time INTEGER NOT NULL, is_correct_answer INTEGER NOT NULL, score INTEGER NOT NULL);";
	executeQuery(statisticsTableQuery, nullptr, nullptr);
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
	std::string addUserQuery = "INSERT INTO users (username, password, mail, games_played) VALUES ('" + name + "','" + password + "','" + mail + "'," + "0" + "); ";
	return executeQuery(addUserQuery, nullptr, nullptr);
}

/*
* Function gets a list of questions
* Input: data - additional passed data
* argc - number of collums
* argv - array of strings that contains the values of the columns in the current row of the query result
* azColName - array of strings that contains the names of the columns in the current row of the query result
* Output: code 0
*/
int QuestionsCallback(void* data, int argc, char** argv, char** azColName) {
	QuestionsList* questions = static_cast<QuestionsList*>(data);
	Question question;
	std::vector<std::string> possibleAnswers(4);
	for (int i = 0; i < argc; i++) {
		if (std::string(azColName[i]) == "question") {
			question.setQuestion(argv[i]);
		}
		if (std::string(azColName[i]) == "correct_answer") {
			possibleAnswers[0] = argv[i];
		}
		if (std::string(azColName[i]) == "wrong_answer_1") {
			possibleAnswers[1] = argv[i];
		}
		if (std::string(azColName[i]) == "wrong_answer_2") {
			possibleAnswers[2] = argv[i];
		}
		if (std::string(azColName[i]) == "wrong_answer_3") {
			possibleAnswers[3] = argv[i];
		}
	}
	question.setPossibleAnswers(possibleAnswers);

	// Add the question to the linked list
	questions->add(question);

	return 0;
}

/*
* Function gets a list of questions from data base
* Input: amount - the amount of questions to get
* Output: question list
*/
QuestionsList* SqliteDatabase::getQuestions(int amount)
{
	QuestionsList* questions = new QuestionsList();
	std::string getQuestionsQuery = "SELECT * FROM questions LIMIT " + std::to_string(amount) + "; ";
	// run the query with the questions callback function
	executeQuery(getQuestionsQuery, QuestionsCallback, questions);
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
			*time += std::atof(argv[i]); // Use atof for float conversion
		}
	}
	return 0;
}

int totalUserAnswersCallBack(void* data, int argc, char** argv, char** azColName)
{
	float* amount = static_cast<float*>(data);
	// Increment amount for each row
	(*amount)++;
	return 0;
}

float SqliteDatabase::getPlayerAverageAnswerTime(std::string username)
{
	float totalTime = 0, amount = 0;
	std::string query = "SELECT time FROM statistics WHERE username = '" + username + "'";
	executeQuery(query, timeCallback, &totalTime);
	executeQuery(query, totalUserAnswersCallBack, &amount);

	// Calculate average time, handling division by zero
	if (amount > 0) {
		return totalTime / amount;
	}
	else {
		// Return some default value or handle the division by zero case appropriately
		return 0.0f; // For example, returning 0 if no answers are found
	}
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
				(*count)++;
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
	std::string getCorrectAnswersQuery = "SELECT is_correct_answer FROM statistics WHERE username = '" + username + "'";
	executeQuery(getCorrectAnswersQuery, correctAnswersCallback, &correctAnswersCount);
	return correctAnswersCount;
}

int wrongAnswersCallback(void* data, int argc, char** argv, char** azColName)
{
	int* count = static_cast<int*>(data);
	for (int i = 0; i < argc; i++) {
		if (std::string(azColName[i]) == "is_correct_answer") {
			if (std::atoi(argv[i]) == wrong)
				// if the answer is wrong
			{
				// raise the answers count
				(*count)++;
			}
		}
	}
	return 0;
}

int SqliteDatabase::getNumOfWrongAnswers(std::string username)
{
	int wrongAnswersCount = 0;
	std::string getWrongAnswersQuery = "SELECT is_correct_answer FROM statistics WHERE username = '" + username + "'";
	executeQuery(getWrongAnswersQuery, wrongAnswersCallback, &wrongAnswersCount);
	return wrongAnswersCount;
}


// Define the callback function outside the class or as static within the class
int gamesPlayedCallback(void* data, int argc, char** argv, char** azColName)
{
	int* totalGamesPlayed = static_cast<int*>(data);
	*totalGamesPlayed = std::stoi(argv[0]); // Assuming number_of_games is the first column
	return 0;
}

/*
* Function gets a player's number of games
* Input: username - the player name
* Output: games
*/
int SqliteDatabase::getNumOfPlayerGames(std::string username)
{
	int gamesNum = 0;
	std::string getPlayedGamesQuery = "SELECT games_played FROM users WHERE username = '" + username + "'";
	executeQuery(getPlayedGamesQuery, gamesPlayedCallback, &gamesNum);
	return gamesNum;
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
int SqliteDatabase::getPlayerTotalScore(std::string username)
{
	int totalPlayerScore = 0;
	std::string query = "SELECT * FROM statistics WHERE username = '" + username + "'; ";
	executeQuery(query, scoreCallback, &totalPlayerScore);
	return totalPlayerScore;
}


int SqliteDatabase::addStatistic(std::string username, std::string time, std::string isCorrectAnswer, std::string score)
{
	std::string addStatsQuery = "INSERT INTO statistics (username, time, is_correct_answer, score) VALUES ('" + username + "','" + time + "','" + isCorrectAnswer + "','" + score + "');";
	return executeQuery(addStatsQuery, nullptr, nullptr);
}

int SqliteDatabase::addNewGame(std::string username)
{
	std::string addNewGameQuery = "UPDATE users SET games_played = games_played + 1 WHERE username = '" + username + "'";
	return executeQuery(addNewGameQuery, nullptr, nullptr);
}


/*
* Function gets the scores of all users
* Input: data - additional passed data
* argc - number of collums
* argv - array of strings that contains the values of the columns in the current row of the query result
* azColName - array of strings that contains the names of the columns in the current row of the query result
* Output: code 0
*/
int usersScoresCallback(void* data, int argc, char** argv, char** colNames) {
	std::multimap<int, std::string>* leaders = static_cast<std::multimap<int, std::string>*>(data);
	if (argc == 2) {
		std::string username = argv[0];
		int totalScore = std::stoi(argv[1]);
		leaders->insert(std::make_pair(totalScore, username)); // Note the order of insertion
	}
	return 0;
}

/*
* Function gets a the top players scores
* Output: high scores table
*/
std::multimap<int ,std::string> SqliteDatabase::getLeaderboard()
{
	std::multimap<int, std::string> leaders; // Note the change to multimap with score as key
	std::string query = "SELECT username, SUM(score) AS total_score "
		"FROM statistics "
		"GROUP BY username "
		"ORDER BY total_score DESC "
		"LIMIT 3";
	executeQuery(query, usersScoresCallback, &leaders);
	return leaders;
}

