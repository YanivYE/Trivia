import socket

# create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# get the server IP address and port number
server_address = ('localhost', 8200)

# connect to the server
client_socket.connect(server_address)

# receive the server's response
response = client_socket.recv(1024).decode()
print("Message received: " + response)

# send a message to the server
message = 'Hello'
client_socket.send(message.encode())
print("Sent message: " + message)

# close the socket
client_socket.close()
