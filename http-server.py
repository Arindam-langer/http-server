'''
creating a socket
binding a socket
listening 
accepting
writing
closing
'''
import socket 
HOST = "127.0.0.1"
PORT_NUMBER = 3000

###creating a socket
server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM,0)


###binding the server socket
server_socket.bind((HOST,PORT_NUMBER))

###listening to incoming connections with a queue of 5
server_socket.listen(5)

while True:
        # Wait for a connection
        client_socket, client_address = server_socket.accept()
        try:
            print(f"Connection from {client_address}")

            # Receive the request data
            request = client_socket.recv(1024).decode()
            #print(f"Request:\n{request}")

            # Prepare an HTTP response
            response_body = "<h1>Hello, World!</h1>"
            response_headers = "HTTP/1.1 200 OK\r\n"
            response_headers += "Content-Type: text/html; charset=utf-8\r\n"
            response_headers += f"Content-Length: {len(response_body)}\r\n"
            response_headers += "\r\n"

            # Send the response
            client_socket.sendall(response_headers.encode() + response_body.encode())
        finally:
            # Clean up the connection
            client_socket.close()

