using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Reflection.Emit;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using System.Windows.Forms;
using TriviaGUI.messages;

namespace TriviaGUI
{
    public partial class LeaderBoardForm : Form
    {
        ServerHandler server;
        string user;
        const int LEADER_BOARD_CODE = 0b00010000;
        public LeaderBoardForm(ServerHandler server)
        {
            InitializeComponent();
            this.server = server;
        }

        private void BackArrow_Click(object sender, EventArgs e)
        {
            statisticsForm statistics = new statisticsForm(user, server);
            statistics.Show();
            this.Hide();
        }

        private void LeaderBoardForm_Load(object sender, EventArgs e)
        {
            Socket socket = server.GetSocket();

            var leaderBoardMsg = new statisticsMsg
            {
                code = LEADER_BOARD_CODE
            };

            Utillities.sendMessage(socket, Utillities.serialize(leaderBoardMsg, LEADER_BOARD_CODE));
            string leaderBoardString = Utillities.recieveMessage(socket);
            Dictionary<string, int> leaderBoard = CreateDictionaryFromString(leaderBoardString);
            DisplayLeaderboard(leaderBoard);

        }

        public static Dictionary<string, int> CreateDictionaryFromString(string leaderBoardString)
        {
            Dictionary<string, int> board = new Dictionary<string, int>();

            int index = leaderBoardString.IndexOf('{');
            leaderBoardString = leaderBoardString.Substring(index);

            // Remove any trailing characters after the closing curly brace '}'
            int endIndex = leaderBoardString.LastIndexOf('}');
            leaderBoardString = leaderBoardString.Substring(0, endIndex + 1);

            // Parse the JSON string into a JObject
            JObject leaderBoardJson = JObject.Parse(leaderBoardString);

            // Extract the leaders dictionary from the JObject
            string leadersString = leaderBoardJson["leaders"].ToString();

            // Remove any unnecessary characters
            leadersString = leadersString.Replace("{", "").Replace("}", "").Replace("\"", "");

            // Split the leaders string by ',' to get individual entries
            string[] leaderEntries = leadersString.Split(',');

            // Loop through the leader entries and populate the dictionary
            foreach (string entry in leaderEntries)
            {
                string[] parts = entry.Split(':');
                if (parts.Length == 2)
                {
                    string username = parts[0];
                    int score = int.Parse(parts[1]);
                    board.Add(username, score);
                }
            }

            return board;
        }


        void DisplayLeaderboard(Dictionary<string, int> board)
        {
            System.Windows.Forms.Label[] userLabels = { user1, user2, user3 };
            System.Windows.Forms.Label[] scoreLabels = { score1, score2, score3 };
            // Extract usernames and scores
            List<string> usernames = board.Keys.ToList();
            List<int> scores = board.Values.ToList();

            // Sort by score in descending order
            var sortedScores = scores.OrderByDescending(x => x).ToList();

            // Display top 3
            for (int i = 0; i < Math.Min(sortedScores.Count, 3); i++)
            {
                string username = usernames[scores.IndexOf(sortedScores[i])];
                int score = sortedScores[i];
                userLabels[i].Text = username;
                scoreLabels[i].Text = score.ToString();
            }
        }
    }
}
