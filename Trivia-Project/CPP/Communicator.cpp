#include "..\\Headers\Communicator.h"

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
	JsonResponsePacketSerializer seralizer;
	JsonRequestPacketDeserializer deseralizer;
	Buffer buffer;
	std::string loginRequestSize, loginRequest;

	// add client to map of clients
	this->m_clients.insert(std::pair<SOCKET, IRequestHandler*>(m_clientSocket, loginRequestHandler));
	
	info.requestId = stoi(binaryToAsciiInt(read(m_clientSocket, BYTE_BIT_LENGTH, 0)));

	if (loginRequestHandler->isRequestRelevant(info))
	{
		loginRequestSize = read(m_clientSocket, BYTE_BIT_LENGTH * DATA_LENGTH, 0);
		loginRequestSize = binaryToAsciiInt(loginRequestSize);
		int loginRequestSizeInt = stoi(loginRequestSize);

		loginRequest = read(m_clientSocket, BYTE_BIT_LENGTH * loginRequestSizeInt, 0);
		
		buffer._bytes = std::vector<unsigned char>(loginRequest.begin(), loginRequest.end());

		LoginRequest loginRequest = deseralizer.deserializeLoginRequest(buffer);

		std::cout << loginRequest.username << std::endl;
		std::cout << loginRequest.password << std::endl;
	}
	else
	{
		ErrorResponse errorResponse;
		errorResponse._data = "Error! Code not login request.";

		Buffer buffer = seralizer.serializeResponse(errorResponse);
		std::string bufferString(buffer._bytes.begin(), buffer._bytes.end());

		send(m_clientSocket, bufferString.c_str(), bufferString.length(), 0);
	}
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
	// Split the binary string into groups of 8 bits
	std::vector<std::bitset<8>> bit_groups;
	for (size_t i = 0; i < binary_string.length(); i += 8) 
	{
		std::string bit_group_str = binary_string.substr(i, 8);
		std::bitset<8> bit_group(bit_group_str);
		bit_groups.push_back(bit_group);
	}

	// Convert each group of 8 bits to a character and concatenate them into a string
	std::string ascii_string = "";
	for (std::bitset<8> bit_group : bit_groups) {
		char ascii_char = static_cast<char>(bit_group.to_ulong());
		if(ascii_char != END_OF_STRING)
		{ 
			ascii_string += ascii_char;
		}
	}

	std::cout << ascii_string << std::endl;

	return ascii_string;
}