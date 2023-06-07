using System;
using System.Net.Sockets;
using System.Net;

namespace TriviaGUI
{
    internal class ServerHandler()
    {
        Socket socket;

        public DialogResult ConnectToServer(string ipAddress, int port)
        {
            try
            {
                // Create a TCP/IP socket
                Socket clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                FileHandler handler = new FileHandler();
                handler.readFile();

                // Connect to the server
                IPAddress serverIPAddress = IPAddress.Parse(handler.serverIp);
                int serverPort = handler.port;
                clientSocket.Connect(new IPEndPoint(serverIPAddress, serverPort));

                return DialogResult.Yes;
            }
            catch (Exception ex)
            {
                DialogResult result = MessageBox.Show("Couldn't Connect To Server\nOk - Try Again\nCancel - Close Client", "Error!",
                        MessageBoxButtons.OKCancel, MessageBoxIcon.Error);

                return result;
            }

        }

        public void CloseConnection()
        {
            if (socket != null && socket.Connected)
            {
                socket.Shutdown(SocketShutdown.Both);
                socket.Close();
            }
        }
    }
}
