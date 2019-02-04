# Server_Side_APP
## Overview
- ServerConnection.cpp is using the winsock2 library for windows socket applications.
- The app is using the xml parser library pugixml(pugixml.hpp, pugixml.cpp, pugiconfig.hpp) which is a C++ XML processing library, which consists of a DOM-like interface
- The server is supposed to be up all time.
## Configuration
- The app is assuming the server is configured based on an xml file called server_config.xml which should be written in the same format as provided in the below example.
- The xml configuration file is allowing modularity in adding more clients in the list of known clients and also adding different type of inofrmation items or even removing some.
- In order to minimize repetition, all Clients should have one information items type, which is stored in the configuration file. if adding a new client you should assign one of old types or define a new type with your needs.
```
<config>
    <error_email_addresses>
        <email>IT@1.com</email>
    </error_email_addresses>
    <clients>
        <client id="1" email="1@1.com" information_items_Type = "Type_1"/>
    </clients>
    <information_items_Type>
		<Type_1>
			<item name ="Free memory" lowest_value="0" highest_value="10"/>
			<item name ="Swapspace Used" lowest_value="10" highest_value="100"/>
			<item name ="CPU" lowest_value="0" highest_value="10"/>
			<item name ="Disk space free" lowest_value="0" highest_value="10"/>
			<item name ="IO Wait" lowest_value="0" highest_value="10"/>
		</Type_1>
    </information_items_Type>
</config>
```
## Server Functionalties
- The server is connecting to the local host socket, with the protocol TCP. It is better to use the SCTP protocol for more reliablity and the multihoming ability but I used TCP as an example.
- The server is waiting to any connection, and if any message recieved it sent back an acknowledgment saying "recieved".
- The server is currently showing only if the message had any error or not.
- The server is catching all types of errors but only showing if there is an error in the console without defining the type of error.
- As mentioned above, Server is not sending emails for misconfiguration but instead saving that internaly.
## Logging
- The server is logging clients messages in a file with the format Client_"ID".xml, creating the file if it is the first time, and adding the message to a new line if one or more messages was sent before.
- Example of line in that log file:
```
<client id= "1" server_ip=" 127.0.0.1" interval="2000"><item name = "Free memory" value="1"/><item name = "Swapspace Used" value="7"/><item name = "CPU load" value="4"/><item name = "Disk space free" value="0"/><item name = "IO Wait" value="9"/></client>
```
# Future Work
- Cover the server functionalties with unit tests.
- Support email functionalties for sending alert emails.
- Use SCTP Protocol.
- Wrap the connection code ij a better class.
