import socket
import serial, json
import re


def checksum(string):
    csum = 0
    for c in string:
        csum ^= ord(c)
    return str(csum)

def Main():
    ser = serial.Serial('/dev/ttyUSB0', 250000)

    host = "127.0.0.1"
    print(host)
    port = 4000

    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind((host, port))

    print("Server Started")
    while True:
        raw_data, addr = s.recvfrom(1024)
        raw_data = raw_data.decode('utf-8')
        p = re.compile('(?<!\\\\)\'')
        raw_data = p.sub('\"', raw_data)
        
        
        data = json.loads(raw_data)


        ##15000;1500;10000;400;1500;10000;400;1500;10000;400*07$
        to_send = "#"
        
        for m in data["motors"]:
            to_send += m + ";"
        
        digital = 0
        i=0
        for k in data["LED"]:
            digital << 1
            if k == 'true':
                digital |= 1<<i
            i+=1
        for k in data["KEYS"]:
            digital << 1
            if k == 'true':
                digital |= 1<<i
            i+=1
    
        for k in data["DIGITAL"]:
            if k == 'true':                
                digital |= 1<<i
            i+=1
        dig_low = digital
        dig_low = dig_low&(0x0000ffff)
        dig_high = digital
        dig_high = dig_high&(0xffff0000)
        dig_high = dig_high>>16        

        to_send += str(dig_low)+";"
        to_send += str(dig_high)

        to_send += "*"
        to_send += checksum(to_send) + "$"
        print("ToSend: " , to_send.encode("utf-8"))
        ser.write(to_send.encode("utf-8"))
        var = ser.read(10)
        ser.flush()
    c.close()

if __name__=='__main__':
    Main()