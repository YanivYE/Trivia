using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaGUI
{
    internal class FileHandler
    {
        const String serverIpValue = "server_ip";
        const String portValue = "port";

        public String serverIp = "";
        public int port = 0;

        public void readFile()
        {
            string filePath = "config.txt";

            try
            {
                using (StreamReader reader = new StreamReader(filePath))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        // Split the line into key and value based on the "=" delimiter
                        string[] parts = line.Split('=');
                        if (parts.Length == 2)
                        {
                            string key = parts[0].Trim();
                            string value = parts[1].Trim();

                            // Process the key-value pair
                            switch (key)
                            {
                                case "server_ip":
                                    serverIp = value;
                                    break;
                                case "port":
                                    port = int.Parse(value);
                                    break;
                                default:
                                    Console.WriteLine("Unknown key: " + key);
                                    break;
                            }
                        }
                    }
                }
            }
            catch (FileNotFoundException)
            {
                Console.WriteLine("File not found: " + filePath);
            }
            catch (Exception ex)
            {
                Console.WriteLine("An error occurred: " + ex.Message);
            }
        }
    }
}
