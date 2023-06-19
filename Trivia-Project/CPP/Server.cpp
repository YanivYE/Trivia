#include "..\\Headers\Server.h"

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
