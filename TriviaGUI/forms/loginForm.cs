using System;
using System.Data;
using System.Net.Sockets;
using System.Runtime.Serialization.Json;
using System.Text;
using System.Text.Json;

namespace TriviaGUI
{

    public partial class loginForm : Form
    {
        const int LOGIN_CODE = 0b00000001;
        const int LENGTH_BYTES = 4;
        ServerHandler server;

        public loginForm(ServerHandler server)
        {
            InitializeComponent();
            this.server = server;
        }
        private void loginForm_Load(object sender, EventArgs e)
        {

        }

        private void loginForm_Close(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Login_Click(object sender, EventArgs e)
        {
            Socket socket = server.GetSocket(); // Assuming you have the serverHandler instance

            var loginMsg = new loginMessage
            {
                username = usernameBox.Text,
                password = passwordBox.Text
            };

            Utillities.sendMessage(socket, Utillities.serialize(loginMsg, LOGIN_CODE));

            string msg = Utillities.recieveMessage(socket);

            if (!msg.Contains(":1}"))
            {
                MessageBox.Show("Username/Password incorrect or user already connected", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                lobbyForm lobby = new lobbyForm(usernameBox.Text, server);
                lobby.Show();
                this.Hide();
            }
        }

        private void Back_Click(object sender, EventArgs e)
        {
            mainForm main = new mainForm();
            main.Show();
            this.Hide();
        }
    }
}
