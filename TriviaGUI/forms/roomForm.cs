using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Sockets;
using System.Text.Json;
using TriviaGUI.messages;
using Microsoft.VisualBasic.ApplicationServices;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.TaskbarClock;
using System.Xml.Linq;
using Newtonsoft.Json;

namespace TriviaGUI
{
    public partial class roomForm : Form
    {
        ServerHandler server;
        bool isAdmin = false;
        bool stop = false;

        const int START_GAME_CODE = 0b00001011;
        const int ROOM_STATE_CODE = 0b00001100;

        public roomForm(string admin, ServerHandler server, createRoomMessage info)
        {
            this.isAdmin = true;
            InitializeComponent();
            this.server = server;
            adminBox.Text = admin;
            roomName.Text = info.roomName;
            maxNumberBox.Text = info.maxUsers;
            questionsNumBox.Text = info.questionCount;
            answerTimeoutBox.Text = info.answerTimeout;
        }

        public roomForm(ServerHandler server, string name)
        {
            InitializeComponent();
            this.server = server;
            roomName.Text = name;
        }


        private void roomForm_Close(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void roomForm_Load(object sender, EventArgs e)
        {
            Thread refreshThread = new Thread(sendUpdateMessage);
            refreshThread.Start();
        }

        void sendUpdateMessage()
        {
            Socket socket = server.GetSocket();

            while (!stop)
            {
                roomStateMessage roomStateMsg = new roomStateMessage
                {
                    code = ROOM_STATE_CODE
                };

                Utillities.sendMessage(socket, Utillities.serialize(roomStateMsg, ROOM_STATE_CODE));
                string msg = Utillities.recieveMessage(socket);

                if (!msg.Contains(":2}"))
                {
                    MessageBox.Show("Couldn't refresh room list. please restart client.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    roomUpdatedState state = parseRoomStateResponse(msg);
                    if(state != null)
                    {
                        UpdateRoomState(state);


                        UpdatePlayersList(state.players);
                        if(state.hasGameBegun)
                        {
                            gameQuestionForm game = new gameQuestionForm(server, answerTimeoutBox.Text, questionsNumBox.Text, 1, 0);
                            this.Hide();
                            game.Show();
                        }
                    }


                }

                Thread.Sleep(3000);
            }
        }

        private roomUpdatedState parseRoomStateResponse(string response)
        {
            int index = response.IndexOf('{');
            response = response.Substring(index);

            roomUpdatedState state = new roomUpdatedState(); // Initialize a new Question object

            try
            {
                // Deserialize the JSON string into a Question object
                var jsonObject = JsonConvert.DeserializeObject<Dictionary<string, object>>(response);

                if (jsonObject != null)
                {
                    // Extract values from the dictionary
                    state.answerTimeOut = Convert.ToInt32(jsonObject["answerTimeOut"]);
                    state.status = Convert.ToInt32(jsonObject["status"]);
                    state.hasGameBegun = Convert.ToBoolean(jsonObject["hasGameBegun"]);
                    state.AnswerCount = Convert.ToInt32(jsonObject["AnswerCount"]);
                    state.maxPlayers = Convert.ToInt32(jsonObject["maxPlayers"]);

                    // Split the players string and add them to the players list
                    // Split the players string and add non-empty players to the players list
                    string playersString = (string)jsonObject["players"];
                    state.players = playersString.Split(new char[] { ',' }, StringSplitOptions.RemoveEmptyEntries).ToList();

                }
            }
            catch (Exception ex) // Catch the exception to handle any errors during parsing
            {
                Console.WriteLine("Error parsing JSON: " + ex.Message);
                return null; // Return null if there is an error during parsing
            }

            return state; // Return the fully populated Question object
        }


        void UpdatePlayersList(List<string> players)
        {
            StringBuilder result = new StringBuilder();

            foreach (string player in players)
            {
                result.AppendLine(player);
            }

            if (playersList.InvokeRequired)
            {
                playersList.Invoke((MethodInvoker)(() => playersList.Text = result.ToString()));
            }
            else
            {
                playersList.Text = result.ToString();
            }
        }

        void UpdateQuestionsNumBox(int value)
        {
            UpdateControl(questionsNumBox, value.ToString());
        }

        void UpdateAnswerTimeoutBox(int value)
        {
            UpdateControl(answerTimeoutBox, value.ToString());
        }

        void UpdateMaxNumberBox(int value)
        {
            UpdateControl(maxNumberBox, value.ToString());
        }

        void UpdateAdminBox(string value)
        {
            UpdateControl(adminBox, value);
        }

        void UpdateControl(Control control, string value)
        {
            if (control.InvokeRequired)
            {
                control.Invoke((MethodInvoker)(() => control.Text = value));
            }
            else
            {
                control.Text = value;
            }
        }

        void UpdateRoomState(roomUpdatedState state)
        {
            UpdateQuestionsNumBox(state.AnswerCount);
            UpdateAnswerTimeoutBox(state.answerTimeOut);
            UpdateMaxNumberBox(state.maxPlayers);
            UpdateAdminBox(state.players[0]); // Assuming the first player is the admin
        }


        private void StartGame_Click(object sender, EventArgs e)
        {
            Socket socket = server.GetSocket(); // Assuming you have the serverHandler instance

            stop = true;

            var startGameMsg = new startGameMessage
            {
                code = START_GAME_CODE
            };

            Utillities.sendMessage(socket, Utillities.serialize(startGameMsg, START_GAME_CODE));

            string msg = Utillities.recieveMessage(socket);

            if (!msg.Contains(":11"))
            {
                MessageBox.Show("Coldn't create room! Please try again", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                stop = false;
            }
            else
            {
                gameQuestionForm game = new gameQuestionForm(server, answerTimeoutBox.Text, questionsNumBox.Text, 1, 0);
                this.Hide();
                game.Show();
            }
        }

        private void closeRoom_Click(object sender, EventArgs e)
        {

        }
    }

    public class roomUpdatedState
    {
        public int AnswerCount { get; set; }
        public int answerTimeOut { get; set; }
        public bool hasGameBegun { get; set; }
        public int maxPlayers { get; set; }

        public List<string> players { get; set; }
        public int status { get; set; }
    }
}
