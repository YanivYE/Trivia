using System.Net.Sockets;
using TriviaGUI.messages;
using Newtonsoft.Json;

namespace TriviaGUI
{
    public partial class gameQuestionForm : Form
    {
        ServerHandler server;
        Socket socket; 
        const int GAME_QUESTION_CODE = 0b00010000;
        const int SUBMIT_ANSWER_CODE = 0b00001111;
        const int GAME_RESULT_CODE = 0b00001110;
        string questionsNum = "";
        int questionsIndex = 0;
        Boolean lastQuestion = false;
        Random random = new Random();
        List<int> availableAnswers = new List<int> { 1, 2, 3, 4 };
        int option1ID = 0;
        int option2ID = 0;
        int option3ID = 0;
        int option4ID = 0;

        public gameQuestionForm(ServerHandler server, string answerTime, string numOfQuestions, int questionIndex, int score)
        {
            InitializeComponent();
            this.server = server;
            this.socket = server.GetSocket();
            timeBox.Text = answerTime;
            questionsNum = numOfQuestions;
            questionsIndex = questionIndex;
            questionCountBox.Text = questionIndex.ToString() + '/' + numOfQuestions;
            lastQuestion = questionIndex == int.Parse(numOfQuestions) ? true : false;
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
            var gameQuestionMsg = new gameQuestionMessage
            {
                code = GAME_QUESTION_CODE,
            };

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
                    option1ID = getRandomAnswerID();
                    option2ID = getRandomAnswerID();
                    option3ID = getRandomAnswerID();
                    option4ID = getRandomAnswerID();
                    option1.Text = question.answers[option1ID - 1];
                    option2.Text = question.answers[option2ID - 1];
                    option3.Text = question.answers[option3ID - 1];
                    option4.Text = question.answers[option4ID - 1];
                }
                
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
                    parsedQuestion.answers = new List<string>();

                    // Copy each answer to the new Question object
                    foreach (var answer in jsonObject.answers)
                    {
                        // Since Answer is a List<string>, add a new list containing the same elements
                        parsedQuestion.answers.Add(new string(answer));
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

        private int getRandomAnswerID()
        {
            int randomAnswerIndex = random.Next(0, availableAnswers.Count);
            int val = availableAnswers[randomAnswerIndex];
            availableAnswers.RemoveAt(randomAnswerIndex);
            return val;
        }

        private void option1_Click(object sender, EventArgs e)
        {
            var submitAnswerMsg = new submitAnswer
            {
                ID = option1ID.ToString(),
            };

            Utillities.sendMessage(socket, Utillities.serialize(submitAnswerMsg, SUBMIT_ANSWER_CODE));

            string msg = Utillities.recieveMessage(socket);

            if (!msg.Contains(":15"))
            {
                MessageBox.Show("Coldn't submit answer! Please try again", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                int startIndex = msg.IndexOf('{');
                string jsonString = msg.Substring(startIndex);

                // Deserialize the JSON string to an object
                CorrectAnswer correctAnswer = JsonConvert.DeserializeObject<CorrectAnswer>(jsonString);
                if(option1ID == correctAnswer.ID)
                {
                    if (!lastQuestion)
                    {
                        gameQuestionForm nextQuestion = new gameQuestionForm(server, timeBox.Text, questionsNum, questionsIndex + 1, int.Parse(scoreBox.Text) + 1000);
                        this.Hide();
                        nextQuestion.Show();
                    }
                    else
                    {
                        GetGameResults();
                    }
                    
                }
            }
        }

        private void option2_Click(object sender, EventArgs e)
        {
            var submitAnswerMsg = new submitAnswer
            {
                ID = option2ID.ToString(),
            };

            Utillities.sendMessage(socket, Utillities.serialize(submitAnswerMsg, SUBMIT_ANSWER_CODE));

            string msg = Utillities.recieveMessage(socket);

            if (!msg.Contains(":15"))
            {
                MessageBox.Show("Coldn't submit answer! Please try again", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                int startIndex = msg.IndexOf('{');
                string jsonString = msg.Substring(startIndex);

                // Deserialize the JSON string to an object
                CorrectAnswer correctAnswer = JsonConvert.DeserializeObject<CorrectAnswer>(jsonString);
                if (option2ID == correctAnswer.ID)
                {
                    if (!lastQuestion)
                    { 
                        gameQuestionForm nextQuestion = new gameQuestionForm(server, timeBox.Text, questionsNum, questionsIndex + 1, int.Parse(scoreBox.Text) + 1000);
                        this.Hide();
                        nextQuestion.Show();
                    }
                    else
                    {
                        GetGameResults();
                    }
                }
            }
        }

        private void option3_Click(object sender, EventArgs e)
        {
            var submitAnswerMsg = new submitAnswer
            {
                ID = option3ID.ToString(),
            };

            Utillities.sendMessage(socket, Utillities.serialize(submitAnswerMsg, SUBMIT_ANSWER_CODE));

            string msg = Utillities.recieveMessage(socket);

            if (!msg.Contains(":15"))
            {
                MessageBox.Show("Coldn't submit answer! Please try again", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                int startIndex = msg.IndexOf('{');
                string jsonString = msg.Substring(startIndex);

                // Deserialize the JSON string to an object
                CorrectAnswer correctAnswer = JsonConvert.DeserializeObject<CorrectAnswer>(jsonString);
                if (option3ID == correctAnswer.ID)
                {
                    if (!lastQuestion)
                    {
                        gameQuestionForm nextQuestion = new gameQuestionForm(server, timeBox.Text, questionsNum, questionsIndex + 1, int.Parse(scoreBox.Text) + 1000);
                        this.Hide();
                        nextQuestion.Show();
                    }
                    else
                    {
                        GetGameResults();
                    }
                }
            }
        }

        private void option4_Click(object sender, EventArgs e)
        {
            var submitAnswerMsg = new submitAnswer
            {
                ID = option4ID.ToString(),
            };

            Utillities.sendMessage(socket, Utillities.serialize(submitAnswerMsg, SUBMIT_ANSWER_CODE));

            string msg = Utillities.recieveMessage(socket);

            if (!msg.Contains(":15"))
            {
                MessageBox.Show("Coldn't submit answer! Please try again", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                int startIndex = msg.IndexOf('{');
                string jsonString = msg.Substring(startIndex);

                // Deserialize the JSON string to an object
                CorrectAnswer correctAnswer = JsonConvert.DeserializeObject<CorrectAnswer>(jsonString);
                if (option4ID == correctAnswer.ID)
                {
                    if (!lastQuestion)
                    {
                        gameQuestionForm nextQuestion = new gameQuestionForm(server, timeBox.Text, questionsNum, questionsIndex + 1, int.Parse(scoreBox.Text) + 1000);
                        this.Hide();
                        nextQuestion.Show();
                    }
                    else
                    {
                        GetGameResults();
                    }
                }
            }
        }

        private void GetGameResults()
        {
            var gameResultMsg = new gameResultsMessage
            {
                code = GAME_RESULT_CODE
            };

            Utillities.sendMessage(socket, Utillities.serialize(gameResultMsg, GAME_RESULT_CODE));

            string msg1 = Utillities.recieveMessage(socket);
        }
    }
    

    public class Question
    {
        public List<string> answers { get; set; }
        public string question { get; set; }
        public int status { get; set; }
    }

    class CorrectAnswer
    {
        public int ID { get; set; }
        public int status { get; set; }
    }
}
