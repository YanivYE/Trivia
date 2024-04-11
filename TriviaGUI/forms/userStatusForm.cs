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
using TriviaGUI.messages;

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

        private void BackArrow_Click(object sender, EventArgs e)
        {
            statisticsForm statistics = new statisticsForm(user, server);
            statistics.Show();
            this.Hide();
        }

        private void userStatusForm_Load(object sender, EventArgs e)
        {
            Socket socket = server.GetSocket();

            var personalStats = new statisticsMsg
            {
                code = USER_STATISTICS_CODE
            };

            Utillities.sendMessage(socket, Utillities.serialize(personalStats, USER_STATISTICS_CODE));

            string userStats = Utillities.recieveMessage(socket);

            gamesPlayedBox.Text = CreateVectorFromString(userStats)[3];
            rightAnswersBox.Text = CreateVectorFromString(userStats)[1];
            wrongAnswersBox.Text = (int.Parse(CreateVectorFromString(userStats)[2]) - int.Parse(CreateVectorFromString(userStats)[1])).ToString();
            avgTimeBox.Text = CreateVectorFromString(userStats)[0];
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
        
    }
}
