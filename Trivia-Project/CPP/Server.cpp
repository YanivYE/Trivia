#include "..\\Headers\Server.h"

Server::Server()
{

}

Server::~Server()
{
}

void Server::run(int port)
{
	std::thread t_connector(&Communicator::startHandleRequests, std::ref(m_communicator), port);

	t_connector.detach();
}
