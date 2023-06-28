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
    public partial class createRoomForm : Form
    {
        ServerHandler server;
        const int CREATE_ROOM_CODE = 0b00000111;
        const int CODE_BYTES = 1;
        const int LENGTH_BYTES = 4;
        createRoomMessage createRoomMsg;

        string user;
        public createRoomForm(ServerHandler server, string user)
        {
            InitializeComponent();
            this.server = server;
            this.user = user;
        }

        private void numPlayers_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsNumber(e.KeyChar);
        }

        private void numQuestions_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsNumber(e.KeyChar);
        }

        private void time_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsNumber(e.KeyChar);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            lobbyForm lobby = new lobbyForm(user, server);
            this.Hide();
            lobby.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            Socket socket = server.GetSocket(); // Assuming you have the serverHandler instance

            Utillities.sendMessage(socket, serialize());

            string msg = Utillities.recieveMessage(socket);

            if (!msg.Contains(":15"))
            {
                MessageBox.Show("Coldn't create room! Please try again", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                roomForm lobby = new roomForm(user, server, createRoomMsg);
                this.Hide();
                lobby.Show();
            }
        }

        string serialize()
        {
            createRoomMsg = new createRoomMessage
            {
                roomName = name.Text,
                maxUsers = numPlayers.Text,
                questionCount = numQuestions.Text,
                answerTimeout = time.Text
            };

            string jsonString = JsonSerializer.Serialize(createRoomMsg);

            jsonString = jsonString.Replace(":", ": ").Replace(",", ", ");

            string message = CREATE_ROOM_CODE.ToString("D8") +
                Utillities.ConvertStringToBinary(jsonString.Length.ToString(), LENGTH_BYTES) +
                Utillities.ConvertStringToBinary(jsonString, jsonString.Length);

            return message;
        }
    }
}
