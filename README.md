# Server_Side_APP
ServerConnection.cpp is using the winsock2 library for windows socket applications.
The app is assuming the server is configured based on an xml file called server_config.xml which should be written in the same format as provided in the example.
The xml configuration file is allowing modularity in adding more clients in the list of known clients and also adding different type of inofrmation items or even removing some.
The app is using the xml parser library pugixml(pugixml.hpp, pugixml.cpp, pugiconfig.hpp) which is a C++ XML processing library, which consists of a DOM-like interface
The server is supposed to be up all time.
The server is connecting to the local host socket, with the protocol TCP. It is better to use the SCTP protocol for more reliablity and the multihoming ability but I used TCP as an example.
The server is waiting to any connection, and if any message recieved it sent back an acknowledgment saying "recieved".
The server is currently showing only if the message had any error or not.
The server is catching all types of errors but only showing if there is an error in the console without defining the type of error.
As mentioned above, Server is not sending emails for misconfiguration but instead saving that internaly.
The server is logging clients messages in a file with the format Client_"ID".xml, creating the file if it is the first time, and adding the message to a new line if one or more messages was sent before.
In order to minimize repetition, all Clients should have one information items type, which is stored in the configuration file. if adding a new client you should assign one of old types or define a new type with your needs.
