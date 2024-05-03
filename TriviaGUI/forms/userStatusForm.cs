using Newtonsoft.Json;
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

            int startIndex = userStats.IndexOf('{');
            string jsonString = userStats.Substring(startIndex);

            // Deserialize the JSON string to an object
            UserStatistics userStatistics = JsonConvert.DeserializeObject<UserStatistics>(jsonString);

            gamesPlayedBox.Text = userStatistics.UserStats[0].ToString();
            rightAnswersBox.Text = userStatistics.UserStats[1].ToString();
            wrongAnswersBox.Text = userStatistics.UserStats[2].ToString();
            avgTimeBox.Text = userStatistics.UserStats[3].ToString();
        }
    }

    class UserStatistics
    {
        public List<int> UserStats { get; set; }
        public int status { get; set; }
    }
}
