#include "..\Headers\JsonResponsePacketSerializer.h"

Buffer JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
{
    Buffer buffer;
    Message message;
    json data;
    data["status"] = response._status;
    message._code = Login;
    message._data = data;
    message._dataLength = data.size();
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
    message._dataLength = data.size();
    buffer._bytes = convertMessageToBuffer(message);
    return buffer;
}

Buffer JsonResponsePacketSerializer::serializeResponse(ErrorResponse response)
{
    Buffer buffer;
    Message message;
    json data;
    data["message"] = response._data;
    message._code = Error;
    message._data = data;
    message._dataLength = data.size();
    buffer._bytes = convertMessageToBuffer(message);
    return buffer;
}

std::vector<unsigned char> JsonResponsePacketSerializer::convertIntToBytes(int32_t value)
{
    std::vector<unsigned char> bytes(sizeof(value));
    std::memcpy(bytes.data(), &value, sizeof(value));
    return bytes;
}

std::vector<unsigned char> JsonResponsePacketSerializer::convertJsonToBytes(json value)
{
    std::string json_str = value.dump();
    std::vector<unsigned char> bytes(json_str.begin(), json_str.end());
    return bytes;
}

std::vector<unsigned char> JsonResponsePacketSerializer::convertMessageToBuffer(Message message)
{
    std::vector<unsigned char> dataLength = convertIntToBytes(message._dataLength);
    std::vector<unsigned char> data = convertJsonToBytes(message._data);

    std::vector<unsigned char> buffer;
    buffer.insert(buffer.end(), message._code);
    buffer.insert(buffer.end(), dataLength.begin(), dataLength.end());
    buffer.insert(buffer.end(), data.begin(), data.end());

    return buffer;
}

