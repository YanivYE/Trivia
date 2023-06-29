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
    public partial class userStatusForm : Form
    {
        ServerHandler server;
        string user;
        const int USER_STATISTICS_CODE = 0b00001001;
        public userStatusForm(string user, ServerHandler server)
        {
            InitializeComponent();
            this.user = user;
            this.server = server;
        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            statisticsForm statistics = new statisticsForm(user, server);
            statistics.Show();
            this.Hide();
        }

        private void userStatusForm_Load(object sender, EventArgs e)
        {
            Socket socket = server.GetSocket();
            Utillities.sendMessage(socket, serialize());

            string userStats = Utillities.recieveMessage(socket);

            label6.Text = CreateVectorFromString(userStats)[3];
            label12.Text = CreateVectorFromString(userStats)[1];
            label11.Text = (int.Parse(CreateVectorFromString(userStats)[2]) - int.Parse(CreateVectorFromString(userStats)[1])).ToString();
            label8.Text = CreateVectorFromString(userStats)[0];
        }

        string serialize()
        {
            var personalStats = new statisticsMsg
            {
                code = USER_STATISTICS_CODE
            };

            string jsonString = JsonSerializer.Serialize(personalStats);

            jsonString = jsonString.Replace(":", ": ").Replace(",", ", ");

            string message = USER_STATISTICS_CODE.ToString("D8") +
                Utillities.ConvertStringToBinary(jsonString.Length.ToString(), 4) +
                Utillities.ConvertStringToBinary(jsonString, jsonString.Length);

            return message;
        }

        public static List<string> CreateVectorFromString(string inputString)
        {
            // Split the input string by commas
            string[] parts = inputString.Split(',');

            // Extract the numbers from the split parts
            List<string> numbers = new List<string>();
            for (int i = 1; i <= 4; i++)
            {
                numbers.Add(parts[i].Trim());
            }

            return numbers;
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }
    }
}
