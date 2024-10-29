#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#define PORT_NUMBER 3000
int main() 
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) 
    {
        printf("WSAStartup failed. Error Code: %d\n", WSAGetLastError());
        exit(1);
    }
//end of function
    // Creating a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) 
    {
        printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
        WSACleanup();
        exit(1);
    }
///end of function
    // Binding socket to a port number
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_NUMBER); // Port number
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to all interfaces

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) 
    {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }

    // Listening for incoming connections with a queue size of 5
    if (listen(server_socket, 5) == SOCKET_ERROR) 
    {
        printf("Listen failed. Error Code: %d\n", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }

    printf("Waiting for client connections...\n");
int i =0;
    // Accepting clients
    while(1)
    {
        struct sockaddr_in client_addr;
        int addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket == INVALID_SOCKET) {
            printf("Accept failed. Error Code: %d\n", WSAGetLastError());
            continue;  // Continue to accept new connections
        }

        // Sending HTTP response
        char buffer[1024]; // added how much info to send using this 
        int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0); // ###
        if (bytes_received > 0) 
        {
            buffer[bytes_received] = '\0'; // Null-terminate for printing // ###
            printf("Received request:\n%s\n", buffer); // ###
        }
        char response[] = /*"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, World!</h1>";*/
        "HTTP/1.1 200 OK\r\n"
                  "Content-Type: text/html\r\n\r\n"
                  "<html><body><h1></h1>"
                  "<img src='https://images8.alphacoders.com/463/thumb-1920-463477.jpg' alt='Image'>"
                  "</body></html>";
        
       /* for video links
       char response[] = "HTTP/1.1 302 Found\r\n"
                  "Location: https://www.youtube.com/watch?v=dQw4w9WgXcQ\r\n\r\n";

       */
        int send_result = send(client_socket, response, sizeof(response) - 1, 0); // Use sizeof(response) - 1 to avoid sending null terminator
        if (send_result == SOCKET_ERROR)
        {
            printf("Send failed. Error Code: %d\n", WSAGetLastError());
        }

        // Close client socket after sending the response
        closesocket(client_socket);
    }
    // Closing sockets

    closesocket(server_socket);
    WSACleanup();

    return 0;
}
