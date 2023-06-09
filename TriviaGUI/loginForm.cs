using System;
using System.Data;
using System.Net.Sockets;
using System.Runtime.Serialization.Json;
using System.Text;
using System.Text.Json;


namespace TriviaGUI
{

    public partial class loginForm : Form
    {
        const int LOGIN_CODE = 1;
        const int CODE_BYTES = 1;
        const int LENGTH_BYTES = 4;
        ServerHandler server;

        public loginForm(ServerHandler server)
        {
            InitializeComponent();
            this.server = server;
        }

        private void loginForm_Close(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            mainForm main = new mainForm();
            main.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Socket socket = server.GetSocket(); // Assuming you have the serverHandler instance

            var loginMsg = new loginMessage
            {
                password = passBox.Text,
                username = usernameBox.Text
            };

            var stream1 = new MemoryStream();
            var ser = new DataContractJsonSerializer(typeof(loginMessage));

            ser.WriteObject(stream1, loginMsg);
            stream1.Position = 0;
            var jsonString = new StreamReader(stream1).ReadToEnd();

            string message = ConvertStringToBinary(LOGIN_CODE.ToString(), CODE_BYTES) +
                ConvertStringToBinary(jsonString.Length.ToString(), LENGTH_BYTES) +
                ConvertStringToBinary(jsonString, jsonString.Length);

            byte[] buffer = Encoding.UTF8.GetBytes(message);

            try
            {
                socket.Send(buffer);
                Console.WriteLine("Message sent successfully.");
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error sending message: " + ex.Message);
            }

            /*
             * Socket socket = serverHandler.GetSocket(); // Assuming you have the serverHandler instance

                byte[] buffer = new byte[1024]; // Buffer to store the received data
                int bytesRead;

                try
                {
                    bytesRead = socket.Receive(buffer);
                    string message = Encoding.UTF8.GetString(buffer, 0, bytesRead);
                    Console.WriteLine("Received message: " + message);
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Error receiving message: " + ex.Message);
                }
            */
        }

        public static string ConvertStringToBinary(string inputString, int byteCount)
        {
            StringBuilder binaryString = new StringBuilder();
            int byteLength = 0;

            foreach (char c in inputString)
            {
                int asciiValue = (int)c;
                string binaryValue = Convert.ToString(asciiValue, 2).PadLeft(8, '0');

                // Check if adding the current character exceeds the byte count
                if (byteLength + binaryValue.Length > byteCount * 8)
                {
                    break;
                }

                binaryString.Append(binaryValue);
                byteLength += binaryValue.Length;
            }

            // Pad with zeros if the binary string is shorter than the specified byte count
            int remainingBits = byteCount * 8 - byteLength;
            binaryString.Append('0', remainingBits);

            return binaryString.ToString();
        }
    }
}
