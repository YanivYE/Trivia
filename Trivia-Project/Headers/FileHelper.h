#include <iostream>
#include <fstream>
#include <string>

class FileHelper {
public:
    FileHelper(const std::string& filePath)
    {
        ReadConfigFile(filePath);
    }

    bool ReadConfigFile(const std::string& filePath)
    {
        std::fstream inputFile(filePath);

        if (!inputFile.is_open()) 
        {
            std::cout << "Failed to open the file." << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(inputFile, line)) {
            if (line.find("server_ip=") == 0) {
                serverIP = line.substr(10); // Extract the IP address after "server_ip="
            }
            else if (line.find("port=") == 0) {
                port = line.substr(5); // Extract the port number after "port="
            }
        }

        inputFile.close();
        return true;
    }

    std::string GetServerIP() const 
    {
        return serverIP;
    }

    std::string GetPort() const 
    {
        return port;
    }

private:
    std::string serverIP;
    std::string port;
};