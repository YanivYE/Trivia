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
            username.Text = user;
        }

        private void username_Click(object sender, EventArgs e)
        {

        }

        private void CreateRoom_Click(object sender, EventArgs e)
        {
            createRoomForm createRoom = new createRoomForm(server, user);
            this.Hide();
            createRoom.Show();
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Logout_Click(object sender, EventArgs e)
        {
            Socket socket = server.GetSocket(); // Assuming you have the serverHandler instance

            var logoutMsg = new logoutMessage
            {
                username = user
            };

            Utillities.sendMessage(socket, Utillities.serialize(logoutMsg, LOGOUT_CODE));

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

        private void JoinRoom_Click(object sender, EventArgs e)
        {
            joinRoomForm joinRoom = new joinRoomForm(server, user);
            joinRoom.Show();
            this.Hide();
        }

        private void Stats_Click(object sender, EventArgs e)
        {
            statisticsForm statistics = new statisticsForm(user, server);
            statistics.Show();
            this.Hide();
        }
    }
}
