#pragma comment (lib, "ws2_32.lib")

#include <iostream>
#include <exception>
#include <thread>
#include "../Headers/Server.h"
#include "../Headers/WSAInitializer.h"
#include <map>
#include <string>

#define PORT 8200
#define EXIT "EXIT"

int main()
{
	WSAInitializer wsaInit;
	Server myServer;
	std::string input;

	try
	{
		myServer.run(PORT);
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}

	while (std::getline(std::cin, input) && input != EXIT);

	// release resources

	return 0;
}