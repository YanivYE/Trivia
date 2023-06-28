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
        const int CODE_BYTES = 1;
        const int LENGTH_BYTES = 4;
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
        void sendUpdateMessage()
        {
            while (true) 
            {
                Socket socket = server.GetSocket();
                Utillities.sendMessage(socket, serialize());
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
                        int endQuoteIndex = value.LastIndexOf('"'); // Find the index of the closing double quote

                        if (startQuoteIndex != -1 && endQuoteIndex != -1 && startQuoteIndex < endQuoteIndex)
                        {
                            string result = value.Substring(startQuoteIndex + 1, endQuoteIndex - startQuoteIndex - 1); // Extract the value between the quotes

                            UpdateRoomList(result);
                        }
                    }
                }

                Thread.Sleep(3000);
            }
        }

        void UpdateRoomList(string roomName)
        {
            if (roomList.InvokeRequired)
            {
                roomList.Invoke(new Action<string>(UpdateRoomList), roomName);
            }
            else
            {
                roomList.Text = roomName;
            }
        }

        string serialize()
        {

            string message = GET_ROOMS_CODE.ToString("D8") +
                Utillities.ConvertStringToBinary("", LENGTH_BYTES) +
                Utillities.ConvertStringToBinary("0", 0);

            return message;
        }


        private void button2_Click(object sender, EventArgs e)
        {

        }
    }
}
