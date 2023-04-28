#include "..\\Headers\Server.h"

/*
* Function is a constructor for server
* Input: none
* Output: none
*/
Server::Server()
{

}

/*
* Function is a destructor for server
* Input: none
* Output: none
*/
Server::~Server()
{
}

/*
* Function gets a port and starts handling new client reuqests for server connection in another thread
* Input: port - the port to start listening from
* Output: none
*/
void Server::run(int port)
{
	std::thread t_connector(&Communicator::startHandleRequests, std::ref(m_communicator), port);

	t_connector.detach();
}
