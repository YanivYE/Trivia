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
    print(str(pad_binary_string(code, 1)))
    print(str(pad_binary_string(int(size), 4)))
    print((str(pad_binary_string(str(buffer), int(size)))))

    message = str(pad_binary_string(code, 1)) + str(pad_binary_string(int(size), 4)) + str(pad_binary_string(str(buffer), int(size)))
    socket.send(message.encode())
    print("Sent message: " + message)


def get_message(socket):
    # receive the server's response
    response = socket.recv(1024).decode()
    print("Message received: " + response)


def decimal_to_binary(decimal_num):
    if decimal_num == 0:
        return '0'
    binary = ''
    while decimal_num > 0:
        remainder = decimal_num % 2
        binary = str(remainder) + binary
        decimal_num = decimal_num // 2
    return binary


def char_to_binary(char):
    """Convert a character from an ASCII table to binary"""
    decimal = char
    print(ord(char), char)
    binary = decimal_to_binary(decimal).zfill(8)
    return binary


def str_to_binary_string(s):
    """Convert a string to a binary string."""
    binary_string = ''
    for c in str(s):
        binary_string += char_to_binary(c)
    return binary_string


def pad_binary_string(value, num_bytes):
    binary_string = str_to_binary_string(value)
    """Pad a binary string with leading zeros to a specified number of bytes."""
    # Calculate the number of bits required to represent the desired number of bytes
    num_bits = num_bytes * 8
    # Calculate the number of zeros to pad with
    num_zeros = num_bits - len(binary_string)
    # Construct the padded binary string
    padded_binary_string = '0' * num_zeros + binary_string
    return padded_binary_string


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
