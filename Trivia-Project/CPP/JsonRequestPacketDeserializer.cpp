#include "../Headers/JsonRequestPacketDeserializer.h"

/*
* Function gets a buffer and seserializes it to a login request
* Input: buffer - the buffer to deserialize
* Output: a login request
*/
LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(Buffer buffer)
{
	LoginRequest loginRequest = LoginRequest();
	std::vector<unsigned char> bytes(buffer._bytes.begin(), buffer._bytes.end()); 

	json data = convertBytesToJson(bytes);

	loginRequest.username = data["username"];
	loginRequest.password = data["password"];

	return loginRequest;
}

/*
* Function gets a buffer and seserializes it to a sign up request
* Input: buffer - the buffer to deserialize
* Output: a sign up request
*/
SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(Buffer buffer)
{
	SignupRequest signUpRequest = SignupRequest();
	std::vector<unsigned char> bytes(buffer._bytes.begin(), buffer._bytes.end());

	json data = convertBytesToJson(bytes);

	signUpRequest.username = data["username"];
	signUpRequest.password = data["password"];
	signUpRequest.email = data["email"];

	return signUpRequest;
}

/*
* Function gets a vector of bits and converts it to json
* Input: bytes - a vector of bits
* Output: json object 
*/
nlohmann::json JsonRequestPacketDeserializer::convertBytesToJson(const std::vector<unsigned char>& bytes)
{
    std::string jsonString = binaryToAscii(bytes);
    json j = json::parse(jsonString);

    return j;
}

/*
* Function gets a vector of bits and converts it to a string in ascii
* Input: bytes - a vector of bits
* Output: a string in ascii
*/
std::string JsonRequestPacketDeserializer::binaryToAscii(const std::vector<unsigned char>& bytes)
{
    std::string binary_string(bytes.begin(), bytes.end());

    // Split the binary string into groups of 8 bits
    std::vector<std::bitset<8>> bit_groups;
    for (size_t i = 0; i < binary_string.length(); i += 8) {
        std::string bit_group_str = binary_string.substr(i, 8);
        std::bitset<8> bit_group(bit_group_str);
        bit_groups.push_back(bit_group);
    }

    // Convert each group of 8 bits to a character and concatenate them into a string
    std::string ascii_string = "";
    for (std::bitset<8> bit_group : bit_groups) 
    {
        char ascii_char = static_cast<char>(bit_group.to_ulong());
        ascii_string += ascii_char;
    }

    return ascii_string;
}