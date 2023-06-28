using Microsoft.VisualBasic.ApplicationServices;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TriviaGUI
{
    public partial class joinRoomForm : Form
    {
        ServerHandler server;
        const int GET_ROOMS_CODE = 0b00000100;
        const int JOIN_ROOM_CODE = 0b00000110;
        const int CODE_BYTES = 1;
        const int LENGTH_BYTES = 4;
        string[] rooms;
        bool stop = false;

        public joinRoomForm(ServerHandler server)
        {
            this.server = server;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void joinRoomForm_Load(object sender, EventArgs e)
        {
            Thread refreshThread = new Thread(sendUpdateMessage);
            refreshThread.Start();

        }
        private void joinRoomForm_Close(object sender, EventArgs e)
        {
            Application.Exit();
        }
        void sendUpdateMessage()
        {
            while (!stop)
            {
                Socket socket = server.GetSocket();
                Utillities.sendMessage(socket, serialize(GET_ROOMS_CODE));
                string msg = Utillities.recieveMessage(socket);

                if (!msg.Contains(":15}"))
                {
                    MessageBox.Show("Couldn't refresh room list. please restart client.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    int colonIndex = msg.IndexOf(':'); // Find the index of the colon

                    if (colonIndex != -1 && colonIndex < msg.Length - 1)
                    {
                        string value = msg.Substring(colonIndex + 1); // Get the substring starting from the colon

                        int startQuoteIndex = value.IndexOf('"'); // Find the index of the opening double quote
                        int endQuoteIndex = value.LastIndexOf("\","); // Find the index of the closing double quote

                        if (startQuoteIndex != -1 && endQuoteIndex != -1 && startQuoteIndex < endQuoteIndex)
                        {
                            string result = value.Substring(startQuoteIndex + 1, endQuoteIndex - startQuoteIndex - 1); // Extract the value between the quotes

                            // Split the input string by commas
                            string[] strings = result.Split(',');

                            // Trim whitespace from each string and convert to a List<string>
                            List<string> stringList = strings
                                .Select((s, index) => $"{index+1}: {s.Trim()}")
                                .ToList();

                            // Convert the List<string> to an array
                            string[] stringArray = stringList.ToArray();

                            rooms = stringArray;
                            UpdateRoomList(stringList);
                        }
                    }
                }

                Thread.Sleep(3000);
            }
        }

        void UpdateRoomList(List<string> roomName)
        {
            string result = "";

            foreach(string room in roomName)
            {
                result += room + "\n";
            }

            if (roomList.InvokeRequired)
            {
                roomList.Invoke(new Action<List<string>>(UpdateRoomList), roomName);
            }
            else
            {
                roomList.Text = result;
            }
        }

        string serialize(int code)
        {
            joinRoomMessage joinRoomMsg = new joinRoomMessage
            {
                roomId = joinRoomName.Text
            };

            string jsonString = JsonSerializer.Serialize(joinRoomMsg);

            jsonString = jsonString.Replace(":", ": ").Replace(",", ", ");

            string message = code.ToString("D8") +
                Utillities.ConvertStringToBinary(jsonString.Length.ToString(), LENGTH_BYTES) +
                Utillities.ConvertStringToBinary(jsonString, jsonString.Length);

            return message;
        }


        private void button2_Click(object sender, EventArgs e)
        {
            foreach (string id in rooms)
            {
                if (int.Parse(joinRoomName.Text) == (id[0] - '0'))
                {
                    stop = true;

                    Socket socket = server.GetSocket();
                    Utillities.sendMessage(socket, serialize(JOIN_ROOM_CODE));
                    string msg = Utillities.recieveMessage(socket);

                    //roomForm lobby = new roomForm(user, server, createRoomMsg);
                    //this.Hide();
                    //lobby.Show();
                }
                else
                {
                    MessageBox.Show("Room ID not from list. please try again.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);

                    stop = false;
                }
            }
        }

        private void joinRoomName_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Allow digits, backspace
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != '\b')
            {
                e.Handled = true; // Ignore the input
            }
        }
    }
}
