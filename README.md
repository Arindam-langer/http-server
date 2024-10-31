# http-server
making http server. Because why not!!
i will making the http servers in three or four languages
1. c (completed)
2. python (completed)
3. rust (completed)
## tools
i will be using 
1. book by beej on network programming [book](https://beej.us/guide/bgnet/)
2. vs code
3. google
4. stack overflow

## basic theory
so to make a http server you first need a socket. Now what is a socket?? Sockets are a Unix like file structure that helps us communicate with other programs. Everything in Unix is done by using a file descriptor every I/O operation is done using a file descriptor,every communication in the internet will be done using a file descriptor.


### steps to make a http-server

1. create a socket
2. bind the socket to ports
3. listen for incoming connections
4. accept the connection
5. read and write data
6. close the socket
 the end



### making a http server in c
use the basic steps of the http server with the library winsock2.h which is the best socket library and to see the code check it on file [http-server-in-c](http-server.c).

#### log of when making http server in C
when running the http server it was responding to the telnet command but was not running on web browser.
the issue was caused by me not sending the content length in the http header.



### making http-server in python
same as in C i will use the simple steps and a library called socket to make it to, to read the code check it on file [http-server-in-python](http-server.py).

#### log when making http-server in python.
nothing


### making http-server in Rust
i will do same as i did in c but pre-requisites were to learn so i am making http-server while learning rust so apologies for very detailed commens in the file [http-server-in-rust](http-server-in-rust\src\main.rs)

#### log of when making an http server in rust
- did the same stuff but rather than doing work in main made a function for easier readibility. 
- used threading: very easy to use it and it has many features for working with servers like i used for loop specially made for tcp servers but could've used infinite loop which is not efficient.
- had anonymous funtions for example on can make functions without names .
- good error handling with expect function is powerful.
- new conditional "match". it is used to find the pattern of the output then act on it making it act like a dictionary for handling situations, interesting part. 
- problem is that line 72 is not runnig right away but running when not need so i have to solve it by making it run on another thread.


# conclusion
- making http server is easy when knowing the steps but was interesting.
- making server in c was hard due to using struct and a very primitive but good library winsock.
- making server in python was easy kind of too easy due to socket module.
- making it in rust was kinda hard due to not working on it but by making this i kindo of understand what rust does and it has good features which make it easier to do socket programming in.

