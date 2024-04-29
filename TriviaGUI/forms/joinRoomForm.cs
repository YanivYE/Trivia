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
        string[] rooms;
        bool stop = false;
        string user;

        public joinRoomForm(ServerHandler server, string user)
        {
            this.server = server;
            this.user = user;
            InitializeComponent();
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
            Socket socket = server.GetSocket();

            while (!stop)
            {
                joinRoomMessage joinRoomMsg = new joinRoomMessage
                {
                    roomId = roomID.Text
                };

                Utillities.sendMessage(socket, Utillities.serialize(joinRoomMsg, GET_ROOMS_CODE));
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

                            string[] strings = result.Split(',');

                            List<string> stringList = strings
                                .Select((s, index) => string.IsNullOrEmpty(s)
                                    ? s.Trim() // No numbering if the string is empty or null
                                    : $"{index + 1}: {s.Trim()}") // Add numbering if the string is not empty
                                .ToList();

                            // Convert the List<string> to an array
                            string[] stringArray = stringList.ToArray();

                            // Remove the last element from the array
                            Array.Resize(ref stringArray, stringArray.Length - 1);

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

            foreach (string room in roomName)
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

        private void JoinRoom_Click(object sender, EventArgs e)
        {
            foreach (string id in rooms)
            {
                if (int.Parse(roomID.Text) == (id[0] - '0'))
                {
                    stop = true;

                    Socket socket = server.GetSocket();

                    joinRoomMessage joinRoomMsg = new joinRoomMessage
                    {
                        roomId = roomID.Text
                    };

                    Utillities.sendMessage(socket, Utillities.serialize(joinRoomMsg, JOIN_ROOM_CODE));
                    string msg = Utillities.recieveMessage(socket);

                    if (!msg.Contains(":15}"))
                    {
                        MessageBox.Show(msg, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                    else
                    {
                        JsonDocument jsonDocument = JsonDocument.Parse(msg.Substring(msg.IndexOf('{')));

                        // Access individual properties using the root element
                        JsonElement rootElement = jsonDocument.RootElement;

                        string roomName = rootElement.GetProperty("name").GetString();
                        roomForm lobby = new roomForm(server, roomName, this.user);
                        this.Hide();
                        lobby.Show();
                    }

                    break;
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

        private void BackArrow_Click(object sender, EventArgs e)
        {
            lobbyForm lobby = new lobbyForm(this.user, server);
            lobby.Show();
            this.Hide();
        }
    }
}
