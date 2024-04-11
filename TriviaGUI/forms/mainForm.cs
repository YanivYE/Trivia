using System.Net;
using System;
using System.Net.Sockets;
using System.Windows.Forms;
using TriviaGUI.messages;

namespace TriviaGUI
{
    public partial class mainForm : Form
    {
        ServerHandler serverHandler = new ServerHandler();

        public mainForm()
        {
            InitializeComponent();
        }

        private void mainForm_Load(object sender, EventArgs e)
        {
            // Connect to the server
            DialogResult connected = serverHandler.ConnectToServer();

            if (connected == DialogResult.OK)
            {
                mainForm_Load(sender, e);
            }
            else if (connected == DialogResult.Cancel)
            {
                this.Close();
            }
        }

        private void Login_Click(object sender, EventArgs e)
        {
            loginForm login = new loginForm(serverHandler);
            login.Show();
            this.Hide();
        }

        private void Signup_Click(object sender, EventArgs e)
        {
            signupForm signup = new signupForm(serverHandler);
            signup.Show();
            this.Hide();
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            serverHandler.CloseConnection();
            this.Close();
        }

        private void Title_Click(object sender, EventArgs e)
        {

        }
    }
}