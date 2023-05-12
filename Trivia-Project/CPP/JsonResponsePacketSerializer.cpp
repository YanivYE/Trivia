#include "..\Headers\JsonResponsePacketSerializer.h"

/*
* Function gets a login response and returns a buffer of the serialized response
* Input: response - the login reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
{
    Buffer buffer;
    Message message;
    json data;

    data["status"] = response._status;
    message._code = Login;
    message._data = data;
    message._dataLength = data.dump().length(); 

    buffer._bytes = convertMessageToBuffer(message); // convert message to bytes

    return buffer;
}
 
/*
* Function gets a sign up response and returns a buffer of the serialized response
* Input: response - the sign up reponse
* Output: a buffer of the serialized response
*/
Buffer JsonResponsePacketSerializer::serializeResponse(SignUpResponse response)
{
    Buffer buffer;
    Message message;
    json data;

    data["status"] = response._status;
    message._code = SignUp;
    message._data = data;
    message._dataLength = data.dump().length(); // convert message to bytes

    buffer._bytes = convertMessageToBuffer(message);

    return buffer;
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
    data.size();
    message._code = Error;
    message._data = data;
    message._dataLength = data.dump().length(); // convert message to bytes

    buffer._bytes = convertMessageToBuffer(message);

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
    std::vector<unsigned char> code = binaryStringToBits(padBinaryString(convertIntToBinaryString(message._code), 1));
    std::vector<unsigned char> dataLength = binaryStringToBits(padBinaryString(convertIntToBinaryString(message._dataLength), 4));
    std::vector<unsigned char> data = binaryStringToBits(padBinaryString(convertJsonToBinaryString(message._data), message._dataLength));

    std::vector<unsigned char> buffer;
    buffer.insert(buffer.end(), code.begin(), code.end());
    buffer.insert(buffer.end(), dataLength.begin(), dataLength.end());
    buffer.insert(buffer.end(), data.begin(), data.end());

    return buffer;
}

