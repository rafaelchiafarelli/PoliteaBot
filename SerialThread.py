import socket
import serial, json
import re
import os
from time import sleep


ser = serial.Serial('/dev/ttyUSB0', 250000,timeout=0.1)
f = open("animations.json")
animations = json.load(f)

def checksum(string):
    csum = 0
    for c in string:
        csum ^= ord(c)
    return str(csum)


def send_data(data):
    if data == None:
        return
    to_send = "#"
    
    for m in data["motors"]:
        to_send += m + ";"
    
    digital = 0
    i=0
    for k in data["LED"]:
        digital << 1
        if k == 'false':
            digital |= 1<<i
        i+=1
    for k in data["KEYS"]:
        digital << 1
        if k == 'false':
            digital |= 1<<i
        i+=1

    for k in data["DIGITAL"]:
        if k == 'false':                
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
    
    ser.write(to_send.encode("utf-8"))
    ser.flush()
    var = ser.read(1024)
      

def Main():
    sequences = []
    
    if "animations" in animations:
        print(animations["animations"])
        for animation_file in animations["animations"]:
            if os.path.isfile(animation_file):
                print(animation_file)
                f = open(animation_file)
                scene = json.load(f)
                sequences.append(scene)
        

    host = "127.0.0.1"
    print(host)
    port = 4000

    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind((host, port))
    print("Server Started")
    first_msg = "#200;200;200;200;200;200;200;200;200;200;65535;65535*50$"
    ser.write(first_msg.encode("utf-8"))
    ser.flush()    
    while True:
        raw_data, addr = s.recvfrom(1024)

        raw_data = raw_data.decode('utf-8')
        p = re.compile('(?<!\\\\)\"')
        raw_data = p.sub('\"', raw_data)
        print(raw_data)
        data = json.loads(raw_data[2:-1])
        if "animation" in data:
            animation_number = data["animation"]


            file_name = animations["animations"][int(animation_number)-1]
            f = open(file_name)
            complete_animation = json.load(f)
            for sequences in complete_animation["animation"]:                
                send_data(data=sequences["output"])
                sleep(float(sequences["cene"])/1000)
        else:
            send_data(data=data)
        

        
    c.close()

if __name__=='__main__':
    Main()