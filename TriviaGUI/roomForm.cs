using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TriviaGUI
{
    public partial class roomForm : Form
    {
        ServerHandler serverHandler;
        string admin;
        createRoomMessage info;
        public roomForm(string admin, ServerHandler server, createRoomMessage info)
        {
            InitializeComponent();
            this.admin = admin;
            this.serverHandler = server;
            this.info = info;
        }
        
        public roomForm(string admin, ServerHandler server)
        {
            InitializeComponent();
            this.admin = admin;
            this.serverHandler = server;
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
            adminLabel.Text = admin;
            maxNumber.Text = info.maxUsers;
            numQuestions.Text = info.questionCount;
            answerTimeout.Text = info.answerTimeout;
        }

        private void button3_Click(object sender, EventArgs e)
        {

        }
    }
}
