from socket import *
from rdt import *

serverName = '127.0.0.1'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
sender = Rdt(1, 2048)

message = input('=>')
while True:
    sender.rdtSend(clientSocket, serverName, serverPort, message)
    msg, serverAdress= sender.rdtRcv(clientSocket)
    
    print(msg)
    if message == "sair":
        break
    message = input('=>')
clientSocket.close()
