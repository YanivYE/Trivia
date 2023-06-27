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
            //Utillities.sendMessage(socket, serialize());
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }
    }
}
