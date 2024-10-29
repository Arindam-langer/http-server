# http-server
making http server. Because why not!!
i will making the http servers in three or four languages
1. c
2. python
3. rust
4. still thinking about it
## tools
i will be using 
1. book by beej on network programming [book](https://beej.us/guide/bgnet/)
2. vs code
3. google
4. stack overflow

## basic theory
so to make a http server you first need a socket. Now what is a socket?? Sockets are a Unix like file structure that helps us communicate with other programs. Everything in Unix is done by using a file descriptor every I/O operation is done using a file descriptor,every communication in the internet will be done using a file descriptor.


### steps

1. create a socket
2. bind the socket to ports
3. listen for incoming connections
4. accept the connection
5. read and write data
6. close the socket
 the end


 ### main issues found 
 when running the http server it was responding to the telnet command but was not running on web browser.
 the issue was caused by me not sending the content length in the http header



