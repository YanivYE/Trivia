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
        public gameQuestionForm(string answerTime, string numOfQuestions, int questionIndex, int score)
        {
            InitializeComponent();
            timeBox.Text = answerTime;
            questionCountBox.Text = questionIndex.ToString() + '/' + numOfQuestions;
            scoreBox.Text = score.ToString();
        }

        private void timer_Tick(object sender, EventArgs e)
        {

        }

        private void Exit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }



        private void gameQuestionForm_Load(object sender, EventArgs e)
        {

        }

        private void option1_Click(object sender, EventArgs e)
        {

        }

        private void option3_Click(object sender, EventArgs e)
        {

        }

        private void option2_Click(object sender, EventArgs e)
        {

        }

        private void option4_Click(object sender, EventArgs e)
        {

        }
    }
}
