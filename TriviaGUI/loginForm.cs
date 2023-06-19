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
        const int LOGIN_CODE = 1;
        const int CODE_BYTES = 1;
        const int LENGTH_BYTES = 4;
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
            Socket socket = server.GetSocket(); // Assuming you have the serverHandler instance

            Utillities.sendMessage(socket, serialize());

            string msg = Utillities.recieveMessage(socket);


            if(msg.Contains(":9"))
            {
                MessageBox.Show("Username/Password incorrect", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                lobbyForm lobby = new lobbyForm(usernameBox.Text);
                lobby.Show();
                this.Hide();
            }
        }

        string serialize()
        {
            var loginMsg = new loginMessage
            {
                username = usernameBox.Text,
                password = passBox.Text
            };

            string jsonString = JsonSerializer.Serialize(loginMsg);

            jsonString = jsonString.Replace(":", ": ").Replace(",", ", ");


            string message = Utillities.ConvertStringToBinary(LOGIN_CODE.ToString(), CODE_BYTES) +
                Utillities.ConvertStringToBinary(jsonString.Length.ToString(), LENGTH_BYTES) +
                Utillities.ConvertStringToBinary(jsonString, jsonString.Length);

            return message;
        }
    }
}
