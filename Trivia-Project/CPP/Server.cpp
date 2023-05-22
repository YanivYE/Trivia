#include "..\\Headers\Server.h"

/*
* Function is a constructor for server
* Input: none
* Output: none
*/
Server::Server()
{
	m_database = new SqliteDatabase();
	m_handlerFactory = new RequestHandlerFactory(this->m_database);
	m_communicator = new Communicator(this->m_handlerFactory);
}

/*
* Function is a destructor for server
* Input: none
* Output: none
*/
Server::~Server()
{
	delete(this->m_communicator);
}

/*
* Function gets a port and starts handling new client reuqests for server connection in another thread
* Input: port - the port to start listening from
* Output: none
*/
void Server::run(int port)
{
	std::thread t_connector(&Communicator::startHandleRequests, this->m_communicator, port);

	t_connector.detach();
}
