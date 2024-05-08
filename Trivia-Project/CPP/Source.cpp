#pragma comment (lib, "ws2_32.lib")

#include <iostream>
#include <exception>
#include <thread>
#include "../Headers/Server.h"
#include "../Headers/FileHelper.h"
#include "../Headers/WSAInitializer.h"
#include <map>
#include <string>

#define EXIT "EXIT"

int main()
{
	FileHelper file("config.txt");
	WSAInitializer wsaInit;
	Server& myServer = Server::getInstance();;
	std::string input;

	try
	{
		// run server
		myServer.run(stoi(file.GetPort()));

		// get input and check if exit
		while (std::getline(std::cin, input) && input != EXIT);
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unkown error occured" << std::endl;
	}

	// release resources

	return 0;
}
