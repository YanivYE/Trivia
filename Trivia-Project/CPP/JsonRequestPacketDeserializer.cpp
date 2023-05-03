#include "../Headers/JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(Buffer buffer)
{
	LoginRequest loginRequest = LoginRequest();
	std::vector<unsigned char> bytes(buffer._bytes.begin() + MESSAGE_OFFSET, buffer._bytes.end());

	json data = convertBytesToJson(bytes);

	loginRequest.username = data["username"];
	loginRequest.password = data["password"];

	return loginRequest;
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(Buffer buffer)
{
	SignupRequest signUpRequest = SignupRequest();
	std::vector<unsigned char> bytes(buffer._bytes.begin() + MESSAGE_OFFSET, buffer._bytes.end());

	json data = convertBytesToJson(bytes);

	signUpRequest.username = data["username"];
	signUpRequest.password = data["password"];
	signUpRequest.email = data["email"];

	return signUpRequest;
}

nlohmann::json JsonRequestPacketDeserializer::convertBytesToJson(const std::vector<unsigned char>& bytes)
{
    std::string json_str(bytes.begin(), bytes.end());
    return nlohmann::json::parse(json_str);
}