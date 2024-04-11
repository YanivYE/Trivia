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
    public partial class gameQuestionForm : Form
    {
        public gameQuestionForm(string answerTime, string numOfQuestions, int score)
        {
            InitializeComponent();
            label2.Text = answerTime;
            label1.Text = numOfQuestions;   

        }

        private void timer1_Tick(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }
    }
}
