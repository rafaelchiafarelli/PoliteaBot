import serial,json
from model import limits, steering, movement
import serial.tools.list_ports as ports
# my_module.py
class Singleton:

    _instance = None
    ser = None
    count = 0
    connection_port = "COM8"
  

    def __new__(cls):
        if cls._instance is None:
            com_ports = list(ports.comports())  # create a list of com ['COM1','COM2']
            for port, desc, hwid in sorted(com_ports):
                if hwid.find("VID:PID=") != -1:
                    print(port,flush=True)
                    sliced = hwid.split("VID:PID=")[1]
                    vid_pid = sliced.split(" ")[0]
                    VID = int(vid_pid.split(":")[0],16)
                    PID = int(vid_pid.split(":")[1],16)
                    if VID == 0x1A86 and PID == 0x7523:
                        cls.connection_port = port
            if cls.ser is None:
                cls.ser = serial.Serial(cls.connection_port, 38400)
            cls._instance = super().__new__(cls)
        return cls._instance



