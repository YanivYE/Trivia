#include <iostream>
#include <exception>
#include <thread>
#include "Server.h"
#include <map>
#include <string>

#define PORT 8200
#define EXIT "EXIT"

int main()
{
	Server myServer;
	std::string input;

	try
	{
		std::thread t_connector(&Server::run, std::ref(myServer), PORT);

		t_connector.detach();
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}

	while (std::getline(std::cin, input) && input != EXIT);

	// release resources

	return 0;
}