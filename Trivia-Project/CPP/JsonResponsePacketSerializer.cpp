#include "..\Headers\JsonResponsePacketSerializer.h"


/*
* Function gets a login response and returns a buffer of the serialized response
* Input: response - the login reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
{
    return serializeReponseStatus(Login, response._status);
}
 
/*
* Function gets a sign up response and returns a buffer of the serialized response
* Input: response - the sign up reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(SignUpResponse response)
{
    return serializeReponseStatus(SignUp, response._status);
}

/*
* Function gets a error response and returns a buffer of the serialized response
* Input: response - the error reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(ErrorResponse response)
{
    Buffer buffer;
    Message message;
    json data;
    
    data["message"] = response._data;
    message._code = Fail;
    message._data = data;
    message._dataLength = data.dump().length(); // convert message to bytes

    buffer._bytes = convertMessageToBuffer(message);

    return buffer;
}

/*
* Function gets a logout response and returns a buffer of the serialized response
* Input: response - the logout reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(LogoutResponse response)
{
    return serializeReponseStatus(Logout, response._status);
}

/*
* Function gets a get rooms response and returns a buffer of the serialized response
* Input: response - the get rooms reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(GetRoomsResponse response)
{
    Buffer buffer;
    Message message;
    json data;
    std::string rooms;
    
    data["status"] = response._status;

    // add all the room names
    for (int i = 0; i < response._rooms.size(); i++)
    {
        rooms += response._rooms[i].name + ", ";
    }

    data["Rooms"] = rooms.substr(0, rooms.size() - 1);

    message._code = GetRooms;
    message._data = data;
    message._dataLength = data.dump().length(); // convert message to bytes

    buffer._bytes = convertMessageToBuffer(message);

    return buffer;
}

/*
* Function gets a get players in room response and returns a buffer of the serialized response
* Input: response - the get players in room reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse response)
{
    Buffer buffer;
    Message message;
    json data;
    std::string players;

    // add all the player names
    for (int i = 0; i < response._players.size(); i++)
    {
        players += response._players[i] + ", ";
    }

    data["PlayersInRoom"] = players.substr(0, players.size() - 1);

    message._code = GetPlayersInRoom;
    message._data = data;
    message._dataLength = data.dump().length(); // convert message to bytes

    buffer._bytes = convertMessageToBuffer(message);

    return buffer;
}

/*
* Function gets a join room response and returns a buffer of the serialized response
* Input: response - the join room reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(JoinRoomResponse response)
{
    Buffer buffer;
    Message message;
    json data;

    std::string players;

    // add all the player names
    for (int i = 0; i < response._room->getAllUsers().size(); i++)
    {
        players += response._room->getAllUsers()[i] + ", ";
    }

    data["status"] = response._status;
    data["hasGameBegun"] = response._room->gameStarted();
    data["maxPlayers"] = response._room->getRoomData().maxPlayers;
    data["roomName"] = response._room->getRoomData().name;
    data["players"] = players.substr(0, players.size() - 1); 
    data["numQuestions"] = response._room->getRoomData().numOfQuestionsInGame;
    data["answerTimeOut"] = response._room->getRoomData().timePerQuestion;


    message._code = JoinRoom;
    message._data = data;
    message._dataLength = data.dump().length(); // convert message to bytes

    buffer._bytes = convertMessageToBuffer(message);

    return buffer;

    return serializeReponseStatus(JoinRoom, response._status);
}

/*
* Function gets a create room response and returns a buffer of the serialized response
* Input: response - the create room reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(CreateRoomResponse response)
{
    return serializeReponseStatus(CreateRoom, response._status);
}

/*
* Function gets a get high score response and returns a buffer of the serialized response
* Input: response - the get high score reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(GetHighScoreResponse response)
{
    return serializeResponseStats(response._status, response._statistics, "HighScores", GetPersonalStats);
}

/*
* Function gets a get personal stats response and returns a buffer of the serialized response
* Input: response - the get personal stats reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(GetPersonalStatsResponse response)
{
    return serializeResponseStats(response._status, response._statistics, "UserStatistics", GetPersonalStats);
}

Buffer JsonResponsePacketSerializer::serializeResponse(CloseRoomResponse response)
{
    return serializeReponseStatus(CloseRoom, response._status);
}

Buffer JsonResponsePacketSerializer::serializeResponse(StartGameResponse response)
{
    return serializeReponseStatus(StartGame, response._status);
}

Buffer JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse response)
{
    Buffer buffer;
    Message message;
    json data;

    std::string players;

    // add all the player names
    for (int i = 0; i < response._players.size(); i++)
    {
        players += response._players[i] + ", ";
    }

    data["status"] = response._status;
    data["hasGameBegun"] = response._hasGameBegun;
    data["players"] = players.substr(0, players.size() - 1);
    data["AnswerCount"] = response._questionCount;
    data["answerTimeOut"] = response._answerTimeout;


    message._code = GetRoomState;
    message._data = data;
    message._dataLength = data.dump().length(); // convert message to bytes

    buffer._bytes = convertMessageToBuffer(message);

    return buffer;
}

Buffer JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse response)
{
    return serializeReponseStatus(LeaveRoom, response._status);
}

Buffer JsonResponsePacketSerializer::serializeResponse(GetGameResultsResponse response)
{
    Buffer buffer;
    Message message;
    json data;
    data["status"] = response._status;
    data["Results"] = vectorToString(response._results);

    message._code = GetGameResult;
    message._data = data;
    message._dataLength = data.dump().length(); // convert message to bytes

    buffer._bytes = convertMessageToBuffer(message);

    return buffer;
}

std::string JsonResponsePacketSerializer::vectorToString(std::vector<PlayerResults> vec)
{
    std::string resultsString = "";
    for (auto& playerResult : vec) {
        resultsString += playerResult._username + ", " +
            std::to_string(playerResult.correctAnswerCount) + ", " +
            std::to_string(playerResult.wrongAnswerCount) + ", " +
            std::to_string(playerResult.averageAnswerTime) + "\n";
    }
    return resultsString;
}

Buffer JsonResponsePacketSerializer::serializeResponse(SubmitAnswerResponse response)
{
    Buffer buffer;
    Message message;
    json data;

    data["status"] = response._status;
    data["ID"] = response._correctAnswerId;

    message._code = SubmitAnswer;
    message._data = data;
    message._dataLength = data.dump().length(); // convert message to bytes

    buffer._bytes = convertMessageToBuffer(message);

    return buffer;
}

Buffer JsonResponsePacketSerializer::serializeResponse(GetQuestionResponse response)
{
    Buffer buffer;
    Message message;
    json data;

    data["status"] = response._status;
    data["question"] = response._question;
    data["Answers"] = response._answers;


    message._code = GetQuestion;
    message._data = data;
    message._dataLength = data.dump().length(); // convert message to bytes

    buffer._bytes = convertMessageToBuffer(message);

    return buffer;
}

Buffer JsonResponsePacketSerializer::serializeResponse(LeaveGameResponse response)
{
    return serializeReponseStatus(LeaveGame, response._status);
}

/*
* Function gets a status, stats, type of stats, and code of a message and returns a buffer of the serialized response
* Input: status - the status code
*        statistics - vector of string of stats
*        typeOfStats - type of stats
*        code - the code of the message
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponseStats(int status, std::vector<std::string> statistics, std::string typeOfStats, int code)
{
    Buffer buffer;
    Message message;
    json data;
    std::string stats;

    data["status"] = status;

    // add all the stats
    for (int i = 0; i < statistics.size(); i++)
    {
        stats += statistics[i] + ", ";
    }

    // get stats without last char
    data[typeOfStats] = stats.substr(0, stats.size() - 1);

    message._code = code;
    message._data = data;
    message._dataLength = data.dump().length(); // convert message to bytes

    buffer._bytes = convertMessageToBuffer(message);

    return buffer;
}

/*
* Function gets a code, status and serializes a status with a message code to a buffer
* Input: code - the code of the message
*        status - the status of the json
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeReponseStatus(int code, int status)
{
    Buffer buffer;
    Message message;
    json data;

    data["status"] = status;
    message._code = code;
    message._data = data;
    message._dataLength = data.dump().length();

    buffer._bytes = convertMessageToBuffer(message); // convert message to bytes

    return buffer;
}

/*
* Function gets an int value and converts it to a binrary string
* Input: value - the value to convert
* Output: a binrary string of the value
*/
std::string JsonResponsePacketSerializer::convertIntToBinaryString(int value) 
{
    std::vector<int> reverse, linear;
    std::string bits;

    // get reversed vector of digits from value
    while (value != 0)
    {
        reverse.push_back(value % 10);
        value /= 10;
    }

    // get linear vector of reversed vector
    for (int i = reverse.size() - 1; i >= 0; i--)
    {
        linear.push_back(reverse[i]);
    }

    // convert each digit to ascii binrary string
    for (int i = 0; i < linear.size(); i++)
    {
        bits += std::bitset<8>(linear[i] + '0').to_string();
    }

    return bits;
}

/*
* Function gets a json object and convert it to a binrary string
* Input: value - the json object
* Output: a binrary string
*/
std::string JsonResponsePacketSerializer::convertJsonToBinaryString(json value)
{
    std::string binaryString;

    for (char c : value.dump()) 
    {
        std::string binaryChar = std::bitset<8>(static_cast<unsigned char>(c)).to_string();
        binaryString += binaryChar;
    }
    return binaryString;
}

/*
* Function gets a binary string and number of bytes, and returns a padded binrary string
* Input: binaryString - the binrary string to pad
*        numBytes - the num of bytes to pad by
* Output: the padded string
*/
std::string JsonResponsePacketSerializer::padBinaryString(const std::string& binaryString, int numBytes) 
{
    int numBits = numBytes * 8;
    int numZeros = numBits - binaryString.length();

    std::string paddedBinaryString = std::string(numZeros, '0') + binaryString;

    return paddedBinaryString;
}

/*
* Function gets a binrary string and converts it to a vector of bits
* Input: binaryString - a string of binrary nums
* Output: a vector of bits
*/
std::vector<unsigned char> JsonResponsePacketSerializer::binaryStringToBits(const std::string& binaryString) 
{
    std::vector<unsigned char> bits;

    for (char c : binaryString) 
    {
        if (c == '0')
        {
            bits.push_back('0');
        }
        else if (c == '1')
        {
            bits.push_back('1');
        }
        else 
        {
            // handle invalid characters
            throw std::invalid_argument("Invalid binary string: " + binaryString);
        }
    }

    return bits;
}

/*
* Function gets a message and converts it to a buffer of bits
* Input: message - the message to convert
* Output: a buffer of bits
*/
std::vector<unsigned char> JsonResponsePacketSerializer::convertMessageToBuffer(Message message)
{
    std::vector<unsigned char> code = binaryStringToBits(std::bitset<8>(message._code).to_string());
    std::vector<unsigned char> dataLength = binaryStringToBits(padBinaryString(convertIntToBinaryString(message._dataLength), 4));
    std::vector<unsigned char> data = binaryStringToBits(padBinaryString(convertJsonToBinaryString(message._data), message._dataLength));

    std::vector<unsigned char> buffer;
    buffer.insert(buffer.end(), code.begin(), code.end());
    buffer.insert(buffer.end(), dataLength.begin(), dataLength.end());
    buffer.insert(buffer.end(), data.begin(), data.end());

    return buffer;
}

