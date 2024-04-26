using System.Net.Sockets;
using TriviaGUI.messages;
using Newtonsoft.Json;
using System;
using System.Windows.Forms;

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
        string answerTimeHolder;
        bool lastQuestion = false;
        int countdownSeconds;
        private System.Windows.Forms.Timer timer = new System.Windows.Forms.Timer();
        Random random = new Random();
        List<int> availableAnswers = new List<int> { 1, 2, 3, 4 };
        Button[] buttonsArray;
        Dictionary<Button, int> buttons;
        Button pressedButton = null;
        int answerPressTime;



        public gameQuestionForm(ServerHandler server, string answerTime, string numOfQuestions, int questionIndex, int score)
        {
            InitializeComponent();
            this.server = server;
            this.socket = server.GetSocket();
            answerTimeHolder = answerTime;
            countdownSeconds = int.Parse(answerTime);
            timer.Interval = 1000; // 1 second
            timer.Tick += timer_Tick;
            questionsNum = numOfQuestions;
            questionsIndex = questionIndex;
            questionCountBox.Text = questionIndex.ToString() + '/' + numOfQuestions;
            lastQuestion = questionIndex == int.Parse(numOfQuestions) ? true : false;
            scoreBox.Text = score.ToString();

        }

        private void timer_Tick(object sender, EventArgs e)
        {
            timeBox.Text = countdownSeconds.ToString();
            countdownSeconds--;

            if (countdownSeconds < 0)
            {
                // Stop the timer
                timer.Stop();
                checkSubmitedAnswer();
                // Move to the next page

            }
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }



        private void gameQuestionForm_Load(object sender, EventArgs e)
        {
            timer.Start();
            this.buttonsArray = new Button[] { option1, option2, option3, option4 };
            
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
                    this.buttons = initButtonsDict(question.answers);
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

        

        private void option1_Click(object sender, EventArgs e)
        {
            optionCLick(1);
        }

        private void option2_Click(object sender, EventArgs e)
        {
            optionCLick(2);
        }

        private void option3_Click(object sender, EventArgs e)
        {
            optionCLick(3);
        }

        private void option4_Click(object sender, EventArgs e)
        {
            optionCLick(4);
        }

        private void optionCLick(int id)
        {
            disableAllButtons();
            answerPressTime = countdownSeconds;
            pressedButton = buttonsArray[id - 1];
        }

        void checkSubmitedAnswer()
        {
            if (pressedButton != null)
            {
                var submitAnswerMsg = new submitAnswer
                {
                    ID = buttons[pressedButton].ToString(),
                    time = answerPressTime.ToString()
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
                    AnswerResult answerResult = JsonConvert.DeserializeObject<AnswerResult>(jsonString);

                    preccceedGame(answerResult.isCorrect, answerResult.score);
                }
            }
            else
            {
                // run out of time
                disableAllButtons();
                preccceedGame(false, 0);
            }
        }

        async void preccceedGame(bool isCorrectAnswer, int answerScore)
        {
            if(pressedButton != null) { 
                pressedButton.BackColor = isCorrectAnswer ? Color.Green : Color.Red;
            }

            await Task.Delay(2000);

            // add score update

            int currentScore = int.Parse(scoreBox.Text);
            currentScore += answerScore;

            if (!lastQuestion)
            {
                gameQuestionForm nextQuestion = new gameQuestionForm(server, answerTimeHolder, questionsNum, questionsIndex + 1, currentScore);
                this.Hide();
                nextQuestion.Show();
            }
            else 
            {
                GetGameResults();
            }
        }

        private Dictionary<Button, int> initButtonsDict(List<string> answers)
        {
            Dictionary<Button, int> buttons = new Dictionary<Button, int>();
            foreach (Button button in buttonsArray)
            {
                int randomID = getRandomAnswerID();
                buttons.Add(button, randomID);
                button.Text = answers[randomID - 1];
            }
            return buttons;
        }

        private int getRandomAnswerID()
        {
            int randomAnswerIndex = random.Next(0, availableAnswers.Count);
            int val = availableAnswers[randomAnswerIndex];
            availableAnswers.RemoveAt(randomAnswerIndex);
            return val;
        }

        private void disableAllButtons()
        {
            foreach(Button button in buttonsArray)
            {
                button.BackColor = SystemColors.ControlDarkDark;
                button.Enabled = false;
            }
        }

        private void GetGameResults()
        {
            // add total score sending for comparison on server side
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

    class AnswerResult
    {
        public bool isCorrect { get; set; }
        public int score { get; set; }
        public int status { get; set; }
    }
}
