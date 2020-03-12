# echo_server.py
#-*- coding:utf-8 -*-

import socket
import sys
from datetime import datetime

IP = '192.168.1.4'
PORT = 8070
SIZE = 1024
ADDR = (IP, PORT)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    server_socket.bind(ADDR) 
    server_socket.listen() 

    while True:
        client_socket, client_addr = server_socket.accept()  
        print ('Connected by', client_addr)
       #print("[{}] message : {}".format(client_addr,msg)) 
        client_socket.sendall("Welcome!".encode()) 
       
        now_datetime = datetime.utcnow().strftime("%Y-%m-%dT-%H:%M:%S") 
        file_path='data/'+now_datetime+'.txt'
        f = open(file_path, "a")
        while True:
            msg = client_socket.recv(SIZE)
            if not msg:
                print ('No data received')
                f.close()
                print('file closed')
                break
            msg = msg.decode()
            f.write(msg+"\n")
            reply = 'OK'
            #client_socket.send(reply.encode())




