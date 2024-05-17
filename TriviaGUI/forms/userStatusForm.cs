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
using static System.Windows.Forms.AxHost;

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
            UserStatistics userStatistics = new UserStatistics();

            try
            {
                // Deserialize the JSON string into a Question object
                var jsonObject = JsonConvert.DeserializeObject<Dictionary<string, object>>(jsonString);

                if (jsonObject != null)
                {
                    userStatistics.status = Convert.ToInt32(jsonObject["status"]); 
                    // Split the players string and add non-empty players to the players list
                    string statsString = (string)jsonObject["UserStats"];
                    userStatistics.UserStats = statsString.Split(new char[] { ',' }, StringSplitOptions.RemoveEmptyEntries).ToList();

                }
            }
            catch (Exception ex) // Catch the exception to handle any errors during parsing
            {
                Console.WriteLine("Error parsing JSON: " + ex.Message);
            }

            gamesPlayedBox.Text = userStatistics.UserStats[0].ToString();
            rightAnswersBox.Text = userStatistics.UserStats[1].ToString();
            wrongAnswersBox.Text = userStatistics.UserStats[2].ToString();
            avgTimeBox.Text = userStatistics.UserStats[3].ToString();
        }
    }

    class UserStatistics
    {
        public List<string> UserStats { get; set; }
        public int status { get; set; }
    }
}
