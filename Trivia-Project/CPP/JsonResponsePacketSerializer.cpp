#include "..\Headers\JsonResponsePacketSerializer.h"

Buffer JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
{
    Buffer buffer;
    Message message;
    json data;
    data["status"] = response._status;
    message._code = Login;
    message._data = data;
    message._dataLength = data.dump().length();
    buffer._bytes = convertMessageToBuffer(message);
    return buffer;
}
 
Buffer JsonResponsePacketSerializer::serializeResponse(SignUpResponse response)
{
    Buffer buffer;
    Message message;
    json data;
    data["status"] = response._status;
    message._code = SignUp;
    message._data = data;
    message._dataLength = data.dump().length();
    buffer._bytes = convertMessageToBuffer(message);
    return buffer;
}

Buffer JsonResponsePacketSerializer::serializeResponse(ErrorResponse response)
{
    Buffer buffer;
    Message message;
    json data;
    data["message"] = response._data;
    data.size();
    message._code = Error;
    message._data = data;
    message._dataLength = data.dump().length();
    buffer._bytes = convertMessageToBuffer(message);
    return buffer;
}

std::string JsonResponsePacketSerializer::convertIntToBinaryString(int value) 
{
    std::vector<int> reverse, linear;
    std::string bits;

    while (value != 0)
    {
        reverse.push_back(value % 10);
        value /= 10;
    }


    for (int i = reverse.size() - 1; i >= 0; i--)
    {
        linear.push_back(reverse[i]);
    }

    for (int i = 0; i < linear.size(); i++)
    {
        bits += std::bitset<8>(linear[i] + '0').to_string();
    }

    return bits;
}

std::string JsonResponsePacketSerializer::convertJsonToBinaryString(json value)
{
    std::string binaryString;

    for (char c : value.dump()) {
        std::string binaryChar = std::bitset<8>(static_cast<unsigned char>(c)).to_string();
        binaryString += binaryChar;
    }
    return binaryString;
}

std::string JsonResponsePacketSerializer::padBinaryString(const std::string& binaryString, int numBytes) {
    int numBits = numBytes * 8;
    int numZeros = numBits - binaryString.length();
    std::string paddedBinaryString = std::string(numZeros, '0') + binaryString;
    return paddedBinaryString;
}

std::vector<unsigned char> JsonResponsePacketSerializer::binaryStringToBits(const std::string& binaryString) {
    std::vector<unsigned char> bits;

    for (char c : binaryString) {
        if (c == '0') {
            bits.push_back('0');
        }
        else if (c == '1') {
            bits.push_back('1');
        }
        else {
            // Handle invalid characters
            throw std::invalid_argument("Invalid binary string: " + binaryString);
        }
    }

    return bits;
}

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

