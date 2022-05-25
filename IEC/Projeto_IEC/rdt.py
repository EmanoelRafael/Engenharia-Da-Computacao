import time
from functions import *

class Timer:
    def __init__(self, timeLimit) -> None:
        self.timerLimit = timeLimit
        self.timeStart = None

    def start(self):
        self.timeStart = time.time()

    def checkTimer(self):
        if time.time() - self.timeStart >= self.timerLimit:
            return False
        else:
            return True
    
    def reset(self):
        self.timeStart = None
    
class Rdt:

    def __init__(self, timeLimit, bufferSize) -> None:
        self.bufferSize = bufferSize
        self.timer = Timer(timeLimit)
        self.activeConnections = {}
        pass

    def rdtSend(self, socket, dstName, dstPort, data):
        
        dstAddress = (dstName,dstPort)

        if dstAddress not in self.activeConnections.keys():
            self.activeConnections.update({dstAddress:[0,0]})
        
        #adiciona o seqNumber 
        msg = ("0" if self.activeConnections[dstAddress][1] == 0 else "1") + data 

        #encapsula (adiciona o checksum e transforma para vetor de bytes)
        msgToSend = encapsulateMsg(msg) 
        
        while True:
            
            #envia a mensagem
            socket.sendto(msgToSend,dstAddress)
            
            #inicia o timer
            self.timer.start()

            while True:
                
                #recebe o ack
                messageRec, serverAddress = socket.recvfrom(self.bufferSize)
                
                if serverAddress not in self.activeConnections.keys():
                    self.activeConnections.update({serverAddress:[0,0]})

                #se o temporizador estoura reinicia e reenvia a mensagem(sai do loop interno)
                if not self.timer.checkTimer():
                    self.timer.reset()
                    break

                #desemcapsula mensagem (obtem o checksum e os dados)
                checksum, dataRcv = uncapsulateMsg(messageRec)

                #verifica se a mensagem esta corrompida
                noCorrupt = verify_checksum(dataRcv, checksum)

                dataRcv = dataRcv.decode()
                
                #obtem o seqNumber (como so pode ser 1 ou 0 o seqNumber vai ser o primeiro elemento dos dados)
                ackSeqNumber = dataRcv[0]

                #se o seqNumber for o esperado e os dados não estiverem corruptos altera o seqNumber esperado, 
                #reseta o timer e retorna os dados recebidos
                expectedSeqNumber = "1" if self.activeConnections[serverAddress][1] else "0"
                if ackSeqNumber == expectedSeqNumber and noCorrupt:
                    self.timer.reset()
                    self.activeConnections[serverAddress][1] = 0 if self.activeConnections[serverAddress][1] else 1
                    return dataRcv[1:]

    def rdtRcv(self, socket):

        while True:
            
            #recebe os dados
            data, clientAdress = socket.recvfrom(self.bufferSize)
            
            if clientAdress not in self.activeConnections.keys():
                self.activeConnections.update({clientAdress:[0,0]})
            
            #desemcapsula os dados (obtem checksum e os dados)
            checksum, msg = uncapsulateMsg(data)
            
            #verifica se os dados estao corrompidos
            noCorrupt = verify_checksum(msg, checksum)
            msg = msg.decode()
            
            #obtem seqNumber
            seqNumber = msg[0]
            
            expectedSeqNumber = "1" if self.activeConnections[clientAdress][0] else "0"

            #se os dados nao estao corrompidos e o seqNumber é o esperado, envia ack
            if noCorrupt and seqNumber == expectedSeqNumber:
                ack = ("1" if self.activeConnections[clientAdress][0] else "0") + "Acknowledgment Message"
                ackToSend = encapsulateMsg(ack)
                socket.sendto(ackToSend,clientAdress)
                self.activeConnections[clientAdress][0] = 0 if self.activeConnections[clientAdress][0] else 1
                return msg[1:],clientAdress
            
            #senao, envia ack de seqNumber nao esperado (recebido anteriormente)
            else:
                ack = ("0" if self.activeConnections[clientAdress][0] else "1") + "Acknowledgment Message"
                ackToSend = encapsulateMsg(ack)
                socket.sendto(ackToSend,clientAdress)
