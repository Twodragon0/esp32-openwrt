# esp32-openwrt

Develop code to send messages between the server and the client for a socket. 
1. we download their code (header.h, client.c, and server.c)
2. Compile and run process for server
```sh
gcc -c header.h 
gcc -o header header.h 
gcc -c server.c 
gcc -o server server.c
```
3. Compile and run process for client
```sh
gcc -c header.h 
gcc -o header header.h 
gcc -c client.c 
gcc -o clent client.c
```
4. Server open port
```sh
./server 8070
```
5. Client connect the port
```sh
./client 127.0.0.1
```

