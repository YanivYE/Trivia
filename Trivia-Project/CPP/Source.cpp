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
	Server& myServer = Server::getInstance();;
	std::string input;

	try
	{
		myServer.run(PORT);
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unkown error occured" << std::endl;
	}

	// get input and check if exit
	while (std::getline(std::cin, input) && input != EXIT);

	// release resources

	return 0;
}
