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
            string leaderBoard = Utillities.recieveMessage(socket);
            List<string> board = CreateVectorFromString(leaderBoard);
            if (!(board.Count() == 0))
            {
                first.Text = CreateVectorFromString(leaderBoard)[0];
                second.Text = CreateVectorFromString(leaderBoard)[1];
                third.Text = CreateVectorFromString(leaderBoard)[2];
            }

        }

        public static List<string> CreateVectorFromString(string inputString)
        {
            // Split the input string by commas
            string[] parts = inputString.Split(',');

            // Extract the user and numbers from the split parts
            List<string> vector = new List<string>();
            if (parts.Contains("\"HighScores\":\"\","))
            {
                for (int i = 0; i <= 2; i++)
                {
                    string[] keyValue = parts[i].Split(':');
                    if (keyValue.Length == 2)
                    {
                        string user = keyValue[0].Trim();
                        string number = keyValue[1].Trim();
                        string item = $"{user}: {number}";
                        vector.Add(item);
                    }
                    else
                    {
                        Console.WriteLine($"Failed to extract user and number at index {i}");
                        return null;
                    }
                }

            }
            return vector;
        }
    }
}
