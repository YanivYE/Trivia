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

namespace TriviaGUI
{
    public partial class roomForm : Form
    {
        ServerHandler serverHandler;
        string admin;
        createRoomMessage info;
        string id;
        bool isAdmin = false;

        public roomForm(string admin, ServerHandler server, createRoomMessage info)
        {
            isAdmin = true;
            InitializeComponent();
            this.admin = admin;
            this.serverHandler = server;
            this.info = info;
        }

        public roomForm(string id, ServerHandler server, string roomNameINPUT, string admin, string maxNumberINPUT, string numQueestionsINPUT, string answerTimeoutINPUT)
        {
            InitializeComponent();
            this.serverHandler = server;

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
            // TODO
            gameQuestionForm game = new gameQuestionForm(answerTimeoutBox.Text, questionsNumBox.Text, 0);
            this.Hide();
            game.Show();
        }

        private void closeRoom_Click(object sender, EventArgs e)
        {

        }
    }
}
