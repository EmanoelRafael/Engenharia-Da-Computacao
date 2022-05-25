from socket import *
from rdt import *
from codigo import *


serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('127.0.0.1',serverPort))
receiver = Rdt(1, 2048)
buffer = Buffer()

while True:
    msg, clientAdress = receiver.rdtRcv(serverSocket)
    cinToFome(buffer,msg,clientAdress)
    receiver.rdtSend(serverSocket, clientAdress[0], clientAdress[1], buffer.clearBuffer())

#serverSocket.close()
