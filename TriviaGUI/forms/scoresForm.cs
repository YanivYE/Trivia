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
    public partial class scoresForm : Form
    {
        ServerHandler server;
        string user;
        public scoresForm(ServerHandler server, string user, string winner, int score)
        {
            InitializeComponent();
            this.server = server;
            this.user = user;
            nameBox.Text = winner;
            scoreBox.Text = score.ToString();
        }

        private void exit_Click(object sender, EventArgs e)
        {
            lobbyForm lobby = new lobbyForm(this.user, server);
            lobby.Show();
            this.Hide();
        }
    }
}
