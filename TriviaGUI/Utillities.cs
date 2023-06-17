using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace TriviaGUI
{
    internal class Utillities
    {
        public static string recieveMessage(Socket socket)
        {
            byte[] getMsg = new byte[1024]; // Buffer to store the received data
            int bytesRead;

            try
            {
                bytesRead = socket.Receive(getMsg);
                string getMessage = Encoding.UTF8.GetString(getMsg, 0, bytesRead);

                StringBuilder asciiString = new StringBuilder();

                for (int i = 0; i < getMessage.Length; i += 8)
                {
                    string binaryByte = getMessage.Substring(i, 8);
                    int asciiValue = Convert.ToInt32(binaryByte, 2);
                    char asciiChar = Convert.ToChar(asciiValue);
                    asciiString.Append(asciiChar);
                }

                string result = asciiString.ToString();
                return result;
            }
            catch (Exception ex)
            {
                return "Error receiving message: " + ex.Message;
            }
        }

        public static void sendMessage(Socket socket, string msg)
        {
            byte[] buffer = Encoding.UTF8.GetBytes(msg);

            try
            {
                socket.Send(buffer);
                Console.WriteLine("Message sent successfully.");
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error sending message: " + ex.Message);
            }
        }

        public static string ConvertStringToBinary(string inputString, int byteCount)
        {
            StringBuilder binaryString = new StringBuilder();
            StringBuilder paddedString = new StringBuilder();
            int byteLength = 0;

            foreach (char c in inputString)
            {
                int asciiValue = (int)c;
                string binaryValue = Convert.ToString(asciiValue, 2).PadLeft(8, '0');

                // Check if adding the current character exceeds the byte count
                if (byteLength + binaryValue.Length > byteCount * 8)
                {
                    break;
                }

                binaryString.Append(binaryValue);
                byteLength += binaryValue.Length;
            }

            // Pad with zeros if the binary string is shorter than the specified byte count
            int remainingBits = byteCount * 8 - byteLength;

            paddedString.Append('0', remainingBits);

            return paddedString.ToString() + binaryString.ToString();
        }
    }
}
