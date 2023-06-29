using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TriviaGUI
{
    public partial class lobbyForm : Form
    {
        const int LOGOUT_CODE = 0b00000011;
        const int CODE_BYTES = 1;
        const int LENGTH_BYTES = 4;
        string user;
        ServerHandler server;

        public lobbyForm(string user, ServerHandler server)
        {
            this.user = user;
            this.server = server;
            InitializeComponent();
        }

        private void lobbyForm_Load(object sender, EventArgs e)
        {

        }

        private void lobbyForm_Load_1(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            createRoomForm createRoom = new createRoomForm(server, user);
            this.Hide();
            createRoom.Show();
        }

        private void lobbyForm_Load_2(object sender, EventArgs e)
        {
            username.Text = user;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Socket socket = server.GetSocket(); // Assuming you have the serverHandler instance

            Utillities.sendMessage(socket, serialize());

            string msg = Utillities.recieveMessage(socket);

            if (!msg.Contains(":3"))
            {
                MessageBox.Show("Coldn't logout! Please try again", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                mainForm main = new mainForm();
                main.Show();
                this.Hide();
            }
        }

        string serialize()
        {
            var logoutMsg = new logoutMessage
            {
                username = user
            };

            string jsonString = JsonSerializer.Serialize(logoutMsg);

            jsonString = jsonString.Replace(":", ": ").Replace(",", ", ");

            string message = LOGOUT_CODE.ToString("D8") +
                Utillities.ConvertStringToBinary(jsonString.Length.ToString(), LENGTH_BYTES) +
                Utillities.ConvertStringToBinary(jsonString, jsonString.Length);

            return message;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            joinRoomForm joinRoom = new joinRoomForm(server);
            joinRoom.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            statisticsForm statistics = new statisticsForm(server);
            statistics.Show();
            this.Hide();
        }
    }
}
