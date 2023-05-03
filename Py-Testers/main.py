import socket
import json
import struct

PORT = 8200
MESSAGE = 'Hello'
Login = '1'
SignUp = '2'

get_bin = lambda x: format(x, 'b')


def connect():
    # create a socket object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # get the server IP address and port number
    server_address = ('localhost', PORT)

    # connect to the server
    client_socket.connect(server_address)
    return client_socket


def get_message_type_code():
    message_type = input("Choose a message type:\n1. Login\n2. SignUp\n ")
    if message_type == Login:
        return int(Login)
    if message_type == SignUp:
        return int(SignUp)


def get_user_details(code):
    username = input("Enter a user name: ")
    password = input("Enter a password: ")
    if code == SignUp:
        mail = input("Enter a mail: ")
        data = {
            "username": username,
            "password": password,
            "mail": mail
        }
    else:
        data = {
            "username": username,
            "password": password,
        }

    return data


def send_message(socket, code, size, buffer):
    # send a message to the server
    print(get_bin(code))
    print(get_bin(int(size)))
    print((str(to_bytes(buffer))))

    message = get_bin(code) + get_bin(int(size)) + str(to_bytes(buffer))
    socket.send(message.encode())
    print("Sent message: " + message)


def get_message(socket):
    # receive the server's response
    response = socket.recv(1024).decode()
    print("Message received: " + response)


def to_bytes(value):
    # Convert the value to bytes
    if isinstance(value, bytes):
        byte_string = value
    elif isinstance(value, str):
        byte_string = value.encode('utf-8')
    else:
        byte_string = bytes(str(value), 'utf-8')

    # Create the binary representation of the value
    binary = ''.join(format(byte, '08b') for byte in byte_string)

    # Return the byte string and the binary representation
    return binary



def main():
    socket = connect()

    code = get_message_type_code()
    data = get_user_details(code)

    # Serialize the JSON object to a string
    json_string = json.dumps(data)
    # Get the size of the JSON string
    data_size = (str(len(json_string))).zfill(5)

    print(code, data_size, json_string)

    send_message(socket, code, data_size, data)
    get_message(socket)

    # close the socket
    socket.close()


if __name__ == "__main__":
    main()
