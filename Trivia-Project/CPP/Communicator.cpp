#include "..\\Headers\Communicator.h"

JsonResponsePacketSerializer seralizer;
JsonRequestPacketDeserializer deseralizer;

/*
* Function is a constructor for communicator
* Input: none
* Output: none
*/
Communicator::Communicator()
{
	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
	// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	m_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (m_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

/*
* Function is a destructor for communicator
* Input: none
* Output: none
*/
Communicator::~Communicator()
{
	try
	{
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(m_serverSocket);
	}
	catch (...) {}
}

/*
* Function gets a port and starts a new handle requests
* Input: port - the port to listen to
* Output: none
*/
void Communicator::startHandleRequests(int port)
{
	bindAndListen(port);

	while (true)
	{
		// the main thread is only accepting clients 
		// and add then to the list of handlers
		std::cout << "Waiting for client connection request" << std::endl;
		acceptClient();
	}
}

/*
* Function gets a port, binds the socket to the port, and listens for new connections
* Input: port - the port to bind
* Output: none
*/
void Communicator::bindAndListen(int port)
{
	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(port); // port that server will listen for
	sa.sin_family = AF_INET;   // must be AF_INET
	sa.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// Connects between the socket and the configuration (port and etc..)
	if (bind(m_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");

	// Start listening for incoming requests of clients
	if (listen(m_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	std::cout << "Listening on port " << port << std::endl;
}

/*
* Function gets a new socket(client) and handles it(creates new login request)
* Input: m_clientSocket - the client socket
* Output: none
*/
void Communicator::handleNewClient(SOCKET m_clientSocket)
{
	LoginRequestHandler* loginRequestHandler = new LoginRequestHandler();
	RequestInfo info;
	Buffer buffer;
	

	// add client to map of clients
	this->m_clients.insert(std::pair<SOCKET, IRequestHandler*>(m_clientSocket, loginRequestHandler));
	
	// get request id from user
	info.requestId = stoi(binaryToAsciiInt(read(m_clientSocket, BYTE_BIT_LENGTH, 0)));

	if (loginRequestHandler->isRequestRelevant(info))
	{
		if (info.requestId == Login)
		{
			handleLoginRequest(m_clientSocket);
		}
		else
		{
			handleSignUpRequest(m_clientSocket);
		}
	}
	else
	{
		sendErrorResponse(m_clientSocket);
	}
}

/*
* Function gets a client socket and handles login request
* Input: m_clientSocket - client socket
* Output: none
*/
void Communicator::handleLoginRequest(SOCKET m_clientSocket)
{
	std::string request;
	int loginRequestSize = 0;
	Buffer buffer;

	// check message size
	loginRequestSize = stoi(binaryToAsciiInt(read(m_clientSocket, BYTE_BIT_LENGTH * DATA_LENGTH, 0)));

	// get message
	request = read(m_clientSocket, BYTE_BIT_LENGTH * loginRequestSize, 0);
		
	// convert message to bits
	buffer._bytes = std::vector<unsigned char>(request.begin(), request.end());

	LoginRequest loginRequest = deseralizer.deserializeLoginRequest(buffer);

	std::cout << "USERNAME: " << loginRequest.username << std::endl;
	std::cout << "PASSWORD: " << loginRequest.password << std::endl;

	sendLoginResponse(m_clientSocket);
}

/*
* Function gets a client socket and sends login response
* Input: m_clientSocket - client socket
* Output: none
*/
void Communicator::sendLoginResponse(SOCKET m_clientSocket)
{
	LoginResponse loginResponse;
	loginResponse._status = Success;
	Buffer buffer;

	buffer = seralizer.serializeResponse(loginResponse);
	std::string bufferString(buffer._bytes.begin(), buffer._bytes.end()); // convert buffer bits to string

	// send login response
	send(m_clientSocket, bufferString.c_str(), bufferString.length(), 0);
}

/*
* Function gets a client socket and handles sign up request
* Input: m_clientSocket - client socket
* Output: none
*/
void Communicator::handleSignUpRequest(SOCKET m_clientSocket)
{
	std::string request;
	int signUpRequestSize = 0;
	Buffer buffer;

	// read size of message
	signUpRequestSize = stoi(binaryToAsciiInt(read(m_clientSocket, BYTE_BIT_LENGTH * DATA_LENGTH, 0)));
	
	// read message
	request = read(m_clientSocket, BYTE_BIT_LENGTH * signUpRequestSize, 0);
		
	// convert message to bits
	buffer._bytes = std::vector<unsigned char>(request.begin(), request.end());

	SignupRequest signUpRequest = deseralizer.deserializeSignupRequest(buffer);

	std::cout << "USERNAME: " << signUpRequest.username << std::endl;
	std::cout << "PASSWORD: " << signUpRequest.password << std::endl;
	std::cout << "EMAIL: " << signUpRequest.email << std::endl;

	sendSignUpResponse(m_clientSocket);
}

/*
* Function gets a client socket and sends sign up response
* Input: m_clientSocket - client socket
* Output: none
*/
void Communicator::sendSignUpResponse(SOCKET m_clientSocket)
{
	SignUpResponse signUpResponse;
	signUpResponse._status = Success;
	Buffer buffer;

	buffer = seralizer.serializeResponse(signUpResponse);
	std::string bufferString(buffer._bytes.begin(), buffer._bytes.end()); // converts bits vector to buffer string

	// send string of bits
	send(m_clientSocket, bufferString.c_str(), bufferString.length(), 0);
}

/*
* Function gets a client socket and sends error response
* Input: m_clientSocket - client socket
* Output: none
*/
void Communicator::sendErrorResponse(SOCKET m_clientSocket)
{
	Buffer buffer;
	ErrorResponse errorResponse;
	errorResponse._data = "ERROR";

	buffer = seralizer.serializeResponse(errorResponse);
	std::string bufferString(buffer._bytes.begin(), buffer._bytes.end()); // converts bits vector to buffer string 

	// send string of bits
	send(m_clientSocket, bufferString.c_str(), bufferString.length(), 0);
}

/*
* Function gets a socket(client), a message and sends the message to the clinet
* Input: sc - the client socket
*		 message - the message to send
* Output: none
*/
void Communicator::write(const SOCKET sc, const std::string message)
{
	const char* data = message.c_str();

	// try to send message to client
	if (send(sc, data, message.size(), 0) == INVALID_SOCKET)
	{
		throw std::exception("Error while sending message to client");
	}

	std::cout << "Sent a message: " + message + "\n";
}

/*
* Function gets a socket(client), num of bytes of message, flags and returns the message recieved
* Input: sc - the client socket
*		 bytesNum - the number of bytes to read
*		 flags - optional so 0
* Output: the message recieved
*/
std::string Communicator::read(const SOCKET sc, const int bytesNum, const int flags)
{
	if (bytesNum == 0)
	{
		return "";
	}

	// allocate data for message + '\0'
	char* data = new char[bytesNum + 1];

	// get message
	int res = recv(sc, data, bytesNum, flags);

	if (res == INVALID_SOCKET)
	{
		std::string s = "Error while recieving from socket: ";
		s += std::to_string(sc);
		throw std::exception(s.c_str());
	}

	// set end of string
	data[bytesNum] = 0;

	std::string received(data);
	delete[] data; // dellocate

	std::cout << "Received a message: " + received + "\n";

	return received;
}

/*
* Function accepts a new client connection
* Input: none
* Output: none
*/
void Communicator::acceptClient()
{

	// this accepts the client and create a specific socket from server to this client
	// the process will not continue until a client connects to the server
	SOCKET client_socket = accept(m_serverSocket, NULL, NULL);
	if (client_socket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__);

	std::cout << "Client accepted. Server and client can speak" << std::endl;

	// the function that handle the conversation with the client
	std::thread handleThread(&Communicator::handleNewClient, this, client_socket);

	handleThread.detach();
}

std::string Communicator::binaryToAsciiInt(std::string binary_string)
{
	std::vector<std::bitset<8>> bit_groups;
	std::string ascii_string = "";

	// split the binary string into groups of 8 bits
	for (size_t i = 0; i < binary_string.length(); i += 8) 
	{
		std::string bit_group_str = binary_string.substr(i, 8);
		std::bitset<8> bit_group(bit_group_str);
		bit_groups.push_back(bit_group);
	}

	// convert each group of 8 bits to a character and concatenate them into a string
	for (std::bitset<8> bit_group : bit_groups)
	{
		char ascii_char = static_cast<char>(bit_group.to_ulong());
		if(ascii_char != END_OF_STRING)
		{ 
			ascii_string += ascii_char;
		}
	}

	return ascii_string;
}