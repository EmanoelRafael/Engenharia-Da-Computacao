from struct import pack

def checksum_func(data):
    
    checksum = bytearray(2)
    data_len = len(data)

    if (data_len % 2):
        data_len += 1
        data += pack('!B', 0)
   
    for i in range(0, data_len, 2):
        if data[i+1]+checksum[1] > 255:
            checksum[1] = (data[i+1]+checksum[1] - 256)
            if data[i]+checksum[0] +1 > 255:
                checksum[0] = (data[i]+checksum[0]+1-256)
            else:
                checksum[0] = data[i]+checksum[0]+1
        else:
            checksum[1] = data[i+1]+checksum[1]
            if data[i]+checksum[0]> 255:
                checksum[0] = (data[i]+checksum[0]-256)
            else:
                checksum[0] = data[i]+checksum[0]
    
    checksum[0] = checksum[0]^0xFF
    checksum[1] = checksum[1]^0xFF
    return checksum

def verify_checksum(data, cs):
    checksum = bytearray(2)
    data_len = len(data)

    if (data_len % 2):
        data_len += 1
        data += pack('!B', 0)
    
    for i in range(0, data_len, 2):
        if data[i+1]+checksum[1] > 255:
            checksum[1] = (data[i+1]+checksum[1] - 256)
            if data[i]+checksum[0] +1 > 255:
                checksum[0] = (data[i]+checksum[0]+1-256)
            else:
                checksum[0] = data[i]+checksum[0]+1
        else:
            checksum[1] = data[i+1]+checksum[1]
            if data[i]+checksum[0]> 255:
                checksum[0] = (data[i]+checksum[0]-256)
            else:
                checksum[0] = data[i]+checksum[0]
    
    if checksum[0] + cs[0] > 255 or checksum[1] + cs[1] > 255:
        return False
    
    checksum[0] += cs[0]
    checksum[1] += cs[1]

    if checksum[0] == 255 and checksum[1] == 255:
        return True
    else:
        return False

def uncapsulateMsg(msg):
    cs = bytearray(2)
    
    cs[0] = msg[0]
    cs[1] = msg[1]

    return cs, msg[2:]

def encapsulateMsg(msg):
    messageBytes = msg.encode()
    checkSum = bytes(checksum_func(messageBytes))

    messageToSend = checkSum+messageBytes
    return messageToSend

