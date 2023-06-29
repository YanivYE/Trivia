using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TriviaGUI
{
    public partial class statisticsForm : Form
    {
        ServerHandler server;
        string user;
        public statisticsForm(string user, ServerHandler server)
        {
            InitializeComponent();
            this.user = user;
            this.server = server;
        }

        private void statisticsForm_Load(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            userStatusForm userStats = new userStatusForm(user, server);
            userStats.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            LeaderBoardForm leaderBoard = new LeaderBoardForm(server);
            leaderBoard.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            lobbyForm lobby = new lobbyForm(user, server);
            lobby.Show();
            this.Hide();
        }
    }
}
