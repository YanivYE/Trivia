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
    public partial class lobbyForm : Form
    {
        string user;

        public lobbyForm(string user)
        {
            this.user = user;
            InitializeComponent();
        }

        private void lobbyForm_Load(object sender, EventArgs e)
        {

        }

        private void lobbyForm_Load_1(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void lobbyForm_Load_2(object sender, EventArgs e)
        {
            username.Text = user;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
