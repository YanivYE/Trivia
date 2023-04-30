#include "..\Headers\JsonResponsePacketSerializer.h"

Buffer JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
{
    Buffer buffer;
    Message message;
    message._code = Login;
    // create json with response
    buffer._bytes = convertMessageToBuffer(message);
    return buffer;
}
 
Buffer JsonResponsePacketSerializer::serializeResponse(SignUpResponse response)
{
    Buffer buffer;
    Message message;
    message._code = SignUp;
    // create json with response
    buffer._bytes = convertMessageToBuffer(message);
    return buffer;
}

Buffer JsonResponsePacketSerializer::serializeResponse(ErrorResponse response)
{
    Buffer buffer;
    Message message;
    message._code = Error;
    // create json with response
    buffer._bytes = convertMessageToBuffer(message);
    return buffer;
}

std::vector<unsigned char> JsonResponsePacketSerializer::convertIntToBytes(int32_t value)
{
    std::vector<unsigned char> bytes(sizeof(value));
    std::memcpy(bytes.data(), &value, sizeof(value));
    return bytes;
}

//std::vector<unsigned char> JsonResponsePacketSerializer::convertJsonToBytes(json value)
//{
//    
//}

std::vector<unsigned char> JsonResponsePacketSerializer::convertMessageToBuffer(Message message)
{
    std::vector<unsigned char> code = convertIntToBytes(message._code);
    std::vector<unsigned char> dataLength = convertIntToBytes(message._dataLength);

}

