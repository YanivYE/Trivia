using System.Net.Sockets;
using TriviaGUI.messages;
using Newtonsoft.Json;

namespace TriviaGUI
{
    public partial class gameQuestionForm : Form
    {
        ServerHandler server;
        const int GAME_QUESTION_CODE = 0b00010000;
        string questionsNum = "";
        string time = "";

        public gameQuestionForm(ServerHandler server, string answerTime, string numOfQuestions, int questionIndex, int score)
        {
            InitializeComponent();
            this.server = server;
            timeBox.Text = answerTime;
            time = answerTime;
            questionsNum = numOfQuestions;
            questionCountBox.Text = questionIndex.ToString() + '/' + numOfQuestions;
            scoreBox.Text = score.ToString();
        }

        public gameQuestionForm(int index, int score)
        {
            InitializeComponent();
            questionCountBox.Text = index.ToString() + '/' + questionsNum;
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
            Socket socket = server.GetSocket(); // Assuming you have the serverHandler instance

            var gameQuestionMsg = new gameQuestionMessage
            {
                code = GAME_QUESTION_CODE,
            };

            //221{ "Answers":[[1,"Michael Emerson"],[2,"Jim Caviezel"],[3,"Taraji P. Henson"],[4,"Kevin Chapman"]]
            //    ,"question":"In the TV series &quot;Person of Interest&quot;, who plays the character &quot;Harold Finch&quot;?","status":16}

            Utillities.sendMessage(socket, Utillities.serialize(gameQuestionMsg, GAME_QUESTION_CODE));

            string msg = Utillities.recieveMessage(socket);

            if (!msg.Contains(":16"))
            {
                MessageBox.Show("Coldn't create room! Please try again", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                Question question = parseQuestionResponse(msg);
                if (question != null)
                {
                    questionLabel.Text = question.question;
                }
                //gameQuestionForm nextQquestion = new gameQuestionForm(0, 1);
                //this.Hide();
                //nextQquestion.Show();
            }
        }

        private Question parseQuestionResponse(string response)
        {
            int index = response.IndexOf('{');
            response = response.Substring(index);

            Question parsedQuestion = new Question(); // Initialize a new Question object

            try
            {
                // Deserialize the JSON string into a Question object
                var jsonObject = JsonConvert.DeserializeObject<Question>(response);

                if (jsonObject != null)
                {
                    // Copy data from jsonObject to parsedQuestion
                    parsedQuestion.question = jsonObject.question;
                    parsedQuestion.status = jsonObject.status;
                    parsedQuestion.Answers = new List<List<string>>();

                    // Copy each answer to the new Question object
                    foreach (var answer in jsonObject.Answers)
                    {
                        // Since Answer is a List<string>, add a new list containing the same elements
                        parsedQuestion.Answers.Add(new List<string>(answer));
                    }
                }
            }
            catch (Exception ex) // Catch the exception to handle any errors during parsing
            {
                Console.WriteLine("Error parsing JSON: " + ex.Message);
                return null; // Return null if there is an error during parsing
            }

            return parsedQuestion; // Return the fully populated Question object
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

    public class Question
    {
        public List<List<string>> Answers { get; set; }
        public string question { get; set; }
        public int status { get; set; }
    }
}
