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
    public partial class signupForm : Form
    {
        ServerHandler server;
        const int SIGNUP_CODE = 2;
        const int CODE_BYTES = 1;
        const int LENGTH_BYTES = 4;

        public signupForm(ServerHandler server)
        {
            InitializeComponent();
            this.server = server;
        }

        private void signupForm_Close(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void signupForm_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Socket socket = server.GetSocket(); // Assuming you have the serverHandler instance

            Utillities.sendMessage(socket, serialize());

            string msg = Utillities.recieveMessage(socket);

            if (msg[0] == '1')
            {
                mainForm test = new mainForm();
                test.Show();
                this.Hide();
            }
            
        }

        string serialize()
        {
            var signupMsg = new signupMessage
            {
                username = usernameBox.Text,
                password = passBox.Text,
                email = mailBox.Text
            };

            string jsonString = JsonSerializer.Serialize(signupMsg);

            jsonString = jsonString.Replace(":", ": ").Replace(",", ", ");


            string message = Utillities.ConvertStringToBinary(SIGNUP_CODE.ToString(), CODE_BYTES) +
                Utillities.ConvertStringToBinary(jsonString.Length.ToString(), LENGTH_BYTES) +
                Utillities.ConvertStringToBinary(jsonString, jsonString.Length);

            return message;
        }
    }

}
