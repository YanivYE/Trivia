using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Sockets;
using System.Text.Json;
using TriviaGUI.messages;
using Microsoft.VisualBasic.ApplicationServices;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.TaskbarClock;
using System.Xml.Linq;

namespace TriviaGUI
{
    public partial class roomForm : Form
    {
        ServerHandler server;
        string admin;
        createRoomMessage info;
        string id;
        bool isAdmin = false;

        const int START_GAME_CODE = 0b00001011;

        public roomForm(string admin, ServerHandler server, createRoomMessage info)
        {
            this.isAdmin = true;
            InitializeComponent();
            this.admin = admin;
            this.server = server;
            this.info = info;
        }

        public roomForm(string id, ServerHandler server, string roomNameINPUT, string admin, string maxNumberINPUT, string numQueestionsINPUT, string answerTimeoutINPUT)
        {
            InitializeComponent();
            this.server = server;

            roomName.Text = roomNameINPUT;
            adminBox.Text = admin;
            maxNumberBox.Text = maxNumberINPUT;
            questionsNumBox.Text = numQueestionsINPUT;
            answerTimeoutBox.Text = answerTimeoutINPUT;

            this.id = id;
        }


        private void roomForm_Close(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void roomForm_Load(object sender, EventArgs e)
        {
            if (isAdmin)
            {
                roomName.Text = info.roomName;
                adminBox.Text = admin;
                maxNumberBox.Text = info.maxUsers;
                questionsNumBox.Text = info.questionCount;
                answerTimeoutBox.Text = info.answerTimeout;
            }
            else
            {
            }
        }

        private void StartGame_Click(object sender, EventArgs e)
        {
            Socket socket = server.GetSocket(); // Assuming you have the serverHandler instance

            var startGameMsg = new startGameMessage
            {
                code = START_GAME_CODE
            };

            Utillities.sendMessage(socket, Utillities.serialize(startGameMsg, START_GAME_CODE));

            string msg = Utillities.recieveMessage(socket);

            if (!msg.Contains(":11"))
            {
                MessageBox.Show("Coldn't create room! Please try again", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                gameQuestionForm game = new gameQuestionForm(server, answerTimeoutBox.Text, questionsNumBox.Text, 1, 0);
                this.Hide();
                game.Show();
            }
        }

        private void closeRoom_Click(object sender, EventArgs e)
        {

        }
    }
}
