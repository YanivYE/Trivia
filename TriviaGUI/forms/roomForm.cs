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
            adminLabel.Text = admin;
            maxNumber.Text = maxNumberINPUT;
            numQuestions.Text = numQueestionsINPUT;
            answerTimeout.Text = answerTimeoutINPUT;

            this.id = id;
        }


        private void roomForm_Close(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void roomForm_Load(object sender, EventArgs e)
        {
            if(isAdmin)
            {
                roomName.Text = info.roomName;
                adminLabel.Text = admin;
                maxNumber.Text = info.maxUsers;
                numQuestions.Text = info.questionCount;
                answerTimeout.Text = info.answerTimeout;
            }
            else 
            {
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            gameQuestionForm game = new gameQuestionForm(answerTimeout.Text, numQuestions.Text, 0);
            this.Hide();
            game.Show();
        }
    }
}
