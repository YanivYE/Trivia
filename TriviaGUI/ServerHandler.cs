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

                // Connect to the server
                IPAddress serverIPAddress = IPAddress.Parse("127.0.0.1"); // Replace with the server's IP address
                int serverPort = 8200; // Replace with the server's port
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
