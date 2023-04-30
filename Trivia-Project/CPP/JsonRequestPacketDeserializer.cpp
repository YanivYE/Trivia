#include "../Headers/JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(Buffer buffer)
{
	RequestInfo* info = bufferToRequestInfo(buffer);
	return LoginRequest();
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(Buffer buffer)
{
	return SignupRequest();
}

RequestInfo* JsonRequestPacketDeserializer::bufferToRequestInfo(Buffer buffer)
{
	std::vector<unsigned char> msgBuffer = buffer.bytes;

	std::vector<unsigned char> subBuffer(msgBuffer.begin() + MSG_OFFSET, msgBuffer.end());

	RequestInfo* info = new RequestInfo;

	info->requestId = buffer.bytes[CODE_INDEX];
	info->receivalTime = time(nullptr);

	info->buffer.bytes = subBuffer;
}