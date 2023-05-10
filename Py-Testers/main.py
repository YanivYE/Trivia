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
    elif message_type == SignUp:
        return int(SignUp)
    else:
        return 0


def get_user_details(code):
    print(code)
    username = input("Enter a user name: ")
    password = input("Enter a password: ")
    if code == int(SignUp):
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

    message = str(pad_binary_string(code, 1)) + str(pad_binary_string(int(size), 4)) + str(
        pad_binary_string(str(buffer), int(size)))
    socket.send(message.encode())
    print("Sent message: " + message)


def get_message(socket):
    # receive the server's response
    response = socket.recv(1024).decode()
    print("Message received: " + response)
    return response


def to_binary_string(value):
    """Convert an integer or string to a binary string."""
    if isinstance(value, int):
        # Use the built-in `bin` function to convert an integer to a binary string
        binary_string = bin(value)[2:]
    elif isinstance(value, str):
        # Use the built-in `ord` function to convert a character to its ASCII code
        # Then convert the ASCII code to a binary string using the built-in `bin` function
        binary_string = ''.join(format(ord(char), '08b') for char in value)
    else:
        raise TypeError('Value must be an integer or string.')
    return binary_string.replace("00100111", "00100010")


def pad_binary_string(value, num_bytes):
    binary_string = to_binary_string(str(value))
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

    while True:
        code = get_message_type_code()
        data = get_user_details(code)

        # Serialize the JSON object to a string
        json_string = json.dumps(data)
        # Get the size of the JSON string
        data_size = (str(len(json_string))).zfill(5)

        send_message(socket, code, data_size, data)
        response = int(get_message(socket), 2)

        print(response.to_bytes((response.bit_length() + 7) // 8, 'big').decode())

    # close the socket
    socket.close()


if __name__ == "__main__":
    main()
