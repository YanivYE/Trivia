using System;
using System.Net.Sockets;
using System.Net;

namespace TriviaGUI
{
    public class ServerHandler
    {
        Socket socket;

        public DialogResult ConnectToServer()
        {

            try
            {
                // Create a TCP/IP socket
                this.socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                FileHandler handler = new FileHandler();
                handler.readFile();

                // Connect to the server
                IPAddress serverIPAddress = IPAddress.Parse(handler.serverIp);
                int serverPort = handler.port;
                this.socket.Connect(new IPEndPoint(serverIPAddress, serverPort));

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
            if (this.socket != null && this.socket.Connected)
            {
                this.socket.Shutdown(SocketShutdown.Both);
                this.socket.Close();
            }
        }

        public Socket GetSocket()
        {
            return this.socket;
        }
    }
}
