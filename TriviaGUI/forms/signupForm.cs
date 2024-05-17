using System.Net.Sockets;
using System.Text.Json;

namespace TriviaGUI
{
    public partial class signupForm : Form
    {
        ServerHandler server;
        const int SIGNUP_CODE = 0b00000010;
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

            if (msg.Contains(":2"))
            {
                mainForm main = new mainForm();
                this.Hide();
                main.Show();
            }
            else
            {
                MessageBox.Show("Username/Password/Email incorrect!\nUsername must be at least 3 characters, and 1 alphabetic character.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
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


            string message = SIGNUP_CODE.ToString("D8") +
                Utillities.ConvertStringToBinary(jsonString.Length.ToString(), LENGTH_BYTES) +
                Utillities.ConvertStringToBinary(jsonString, jsonString.Length);

            return message;
        }
    }

}
