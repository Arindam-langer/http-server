/*
creating a socket
binding a socket
listening 
accepting
writing
closing
*/


//this is how you import libraries in rust net and io are libraries
// and tcplistener,read write are the modules we are importing

use std::net::{TcpListener,TcpStream};  //tcpstream == TCP connection
use std::io::{Read, Write};
/*mut is a way to tell rust that the stream variable will be changing atleast once in this
code if it does not then rust will warn us that we didnot change stream vairable of type tcpstream
FYI!! variable in rust are immutable
*/
fn handle_clients(mut stream: TcpStream) 
{
    //declared a muttable array of 1024 size with element == 0
    let mut buffer = [0;1024];


    //reading the data in stream variable and stores it in  buffer variable which is 1024
    //then using expect method which will tell us a messg as below if the call fails
    stream.read(&mut buffer).expect("failed to read from client");


    //converting the buffer to string
    // request will store the byte from buffer array to utf-8 string meaning text
    //buffer[..] is slicing the array 
    let request  = String::from_utf8_lossy(&buffer[..]);




    /*{} is place holder to print request and can be used for 
    almost every type data*/
    print!("request recieved {}",request);




    /*  converting the response to byte slice
    byte slice is different from an array a slice is more similar 
    to a list in python but only when slicing where as an array in rust is more 
    like an array in C */

    /*taking response as a string  */
    let response = "HTTP/1.1 200 OK\r\n".to_string()
                            + "Content-Type: text/html\r\n\r\n"
                            + "<html><body><h1></h1>"
                            + "<img src='https://images8.alphacoders.com/463/thumb-1920-463477.jpg' alt='Image'>"
                            + "</body></html>";


    //same as that of stream.read and using expect for error handling on line 29
    stream.write(response.as_bytes()).expect("failed to write response");


    //we are using flush to send all the data to client right away if we dont use this line 
    //it will take some time since write function rust might hold onto some data in its buffer for more performance
    stream.flush().expect("Failed to flush stream");
}



fn  main() {
    let addr = "127.0.0.1:3000";
    print!("check the output at {}",addr);
    //binding address
    let listener  = TcpListener::bind(addr).expect("failed to bind address");
    print!("server listening on {}",addr);

    //listening to accept clients
    /*it is just like the while loop but it increases readability
    and handles incoming connections efficiently*/
    for stream in listener.incoming()
    {
        /*a conditional in rust used to find patterns and working on the snippet with same pattern
        like a dictionary in python */
        match stream
        {
            //it is like a try except block
            Ok(stream) => {

                //creating a new thread for faster execution.
                //std::thread::spawn helps in handling multipe tasks
                /*still dont understand || but it is a closure syntax for anonymous function used to make functions
                on the spot |between takes parameters| after that is the operation */
                std::thread::spawn(|| handle_clients(stream));
            }
            Err(e) =>
            {
                eprint!("failed to establish connection: {}",e); 
            } 

        }
    }

}