
import serial
import serial.tools.list_ports as ports
com_ports = list(ports.comports())  # create a list of com ['COM1','COM2']
connection_port = "COM8"
for port, desc, hwid in sorted(com_ports):
	
	if hwid.find("VID:PID=") != -1:
		sliced = hwid.split("VID:PID=")[1]
		vid_pid = sliced.split(" ")[0]
		VID = int(vid_pid.split(":")[0],16)
		PID = int(vid_pid.split(":")[1],16)
		if VID == 0x1A86 and PID == 0x7523:
			print("We got one {}".format(port))
			connection_port = port

ser = serial.Serial(connection_port, 38400)
mystring = "this is a message to you".encode("utf-8")
ser.write(mystring)

ser.flush()