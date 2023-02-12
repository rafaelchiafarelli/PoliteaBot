"""
Create a webpage that is constantly updated with random numbers from a background python process.
"""

# Start with a basic flask app webpage.
from tkinter.font import names
from turtle import forward
from flask_socketio import SocketIO, emit
from flask import Flask, render_template, url_for, copy_current_request_context
from random import random
from time import sleep
from threading import Thread, Event
from random import randint
import serial,json
from model import limits, steering, movement
import socket
__author__ = 'Eremita'

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
app.config['DEBUG'] = False

#turn the flask app into a socketio app
socketio = SocketIO(app,async_mode = "threading",logging = False, engineio_logger = False)

#random number Generator Thread
thread = Thread()
thread_stop_event = Event()

#serial comunication thread
s_thread = Thread()
serial_stop_event = Event()

ser = serial.Serial('/dev/ttyUSB0', 250000)
count = 0




class RandomThread(Thread):
    def __init__(self):
        self.delay = 1
        super(RandomThread, self).__init__()

    def randomNumberGenerator(self):
        """
        Generate a random number every 1 second and emit to a socketio instance (broadcast)
        Ideally to be run in a separate thread?
        """
        #infinite loop of magical random numbers
        print("Making random numbers")
        while not thread_stop_event.isSet():
            number = randint(11111, 99999)
            #print(number)
            socketio.emit('newnumber', {'number': number}, namespace='/test')
            sleep(self.delay)

    def run(self):
        self.randomNumberGenerator()


@app.route('/')
def index():
    return render_template('dev.html')

@app.route('/admin')
def admin():
    return render_template('dev.html')

@app.route('/dev')
def dev():
    return render_template('dev.html')

@socketio.on('connect', namespace='/test')
def test_connect():
    # need visibility of the global thread object
    global thread
    print('Client connected')
    #Start the random number generator thread only if the thread has not been started before.
    if not thread.is_alive():
        print("Starting Thread")
        thread = RandomThread()
        thread.start()

@socketio.on('disconnect', namespace='/test')
def test_disconnect():
    print('Client disconnected')
    serial_stop_event.set()

@socketio.on('stop')
def stop_connections():
    serial_stop_event.set()
    thread_stop_event.set()




@socketio.on('message', namespace='/test')
def received_msg(data):

    global count
    x = int(data['x'])
    forward = 0
    if(x<0):
        forward = 1
        x = x*(-1)
    if x>99:
        x=99

    y = int(data['y'])
    left = 0
    if(y<0):
        left = 1
        y = y*(-1)
    if y>99:
        y=99
    speed_x = limits[x]
    speed_y = limits[y]
    command = 0
    if (speed_y,speed_x,left,forward) in steering:
        if steering[(speed_y,speed_x,left,forward)] in movement:
            command = movement[steering[(speed_y,speed_x,left,forward)]]
    count+=1    
    if count > 99999999:
        count = 0    
    if forward == 1:
        x  = -1 * x
    if left == 1:
        y = -1 * y

    mystring = ("{cmd:"+ f'{command:02d}' + 
                ",t:" + f'{x:+03d}' +
                ",y:" + f'{y:+03d}' +
                ",hb:" + f'{count:08d}' + 
                "};").encode("utf-8")
    print(mystring)
    host = socket.gethostname()  # get local machine name
    port = 8080  # Make sure it's within the > 1024 $$ <65535 range

    soc = socket.socket()    
    soc.connect((host, port))
    soc.sendto(mystring)
    




if __name__ == '__main__':

    socketio.run(app, host='127.0.0.1', port=5000, log_output = False)
