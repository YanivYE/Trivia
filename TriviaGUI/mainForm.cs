using System.Net;
using System;
using System.Net.Sockets;
using System.Windows.Forms;

namespace TriviaGUI
{
public partial class mainForm : Form
    {
        ServerHandler serverHandler = new ServerHandler();

        public mainForm()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Connect to the server
            DialogResult connected = serverHandler.ConnectToServer("127.0.0.1", 8200);

            if (connected == DialogResult.OK)
            {
                Form1_Load(sender, e);
            }
            else if (connected == DialogResult.Cancel)
            {
                this.Close();
            }
    }

        private void button1_Click(object sender, EventArgs e)
        {
            loginForm login = new loginForm(serverHandler);
            login.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            signupForm signup = new signupForm(serverHandler);
            signup.Show();
            this.Hide();
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            serverHandler.CloseConnection();
            this.Close();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}