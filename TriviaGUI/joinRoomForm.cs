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
            Socket socket = server.GetSocket();
            while(true)
            {
                Utillities.sendMessage(socket, serialize());
                string msg = Utillities.recieveMessage(socket);

                Thread.Sleep(3000);
            }
        }

        string serialize()
        {
            var getRooms = new updateMessage
            {
                messageCode = 0b00000100
            };

            string jsonString = JsonSerializer.Serialize(getRooms);

            jsonString = jsonString.Replace(":", ": ").Replace(",", ", ");

            string message = LOGIN_CODE.ToString("D89") +
                Utillities.ConvertStringToBinary(jsonString.Length.ToString(), LENGTH_BYTES) +
                Utillities.ConvertStringToBinary(jsonString, jsonString.Length);

            return message;
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }
    }
}
