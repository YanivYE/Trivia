#include "SqliteDatabase.h"

bool SqliteDatabase::open()
{
    return false;   
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
