using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TriviaGUI
{
    public partial class loginForm : Form
    {
        ServerHandler server;

        public loginForm(ServerHandler server)
        {
            InitializeComponent();
            this.server = server;
        }

        private void loginForm_Close(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            mainForm main = new mainForm();
            main.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String username = usernameBox.Text;
            String password = passBox.Text;

            Socket socket = server.GetSocket(); // Assuming you have the serverHandler instance

            string message = "Hello, server!";
            byte[] buffer = Encoding.UTF8.GetBytes(message);

            try
            {
                socket.Send(buffer);
                Console.WriteLine("Message sent successfully.");
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error sending message: " + ex.Message);
            }

            /*
             * Socket socket = serverHandler.GetSocket(); // Assuming you have the serverHandler instance

                byte[] buffer = new byte[1024]; // Buffer to store the received data
                int bytesRead;

                try
                {
                    bytesRead = socket.Receive(buffer);
                    string message = Encoding.UTF8.GetString(buffer, 0, bytesRead);
                    Console.WriteLine("Received message: " + message);
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Error receiving message: " + ex.Message);
                }
            */
        }
    }
}
