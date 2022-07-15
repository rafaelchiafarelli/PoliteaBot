"""
Create a webpage that is constantly updated with random numbers from a background python process.
"""

# Start with a basic flask app webpage.
from tkinter.font import names
from tokenize import Single
from turtle import forward
from flask_socketio import SocketIO, emit
from flask import Flask, render_template, url_for, copy_current_request_context, jsonify
from random import random
from time import sleep
from threading import Thread, Event
from random import randint
import serial,json
from model import limits, steering, movement
import serial.tools.list_ports as ports
import cv2 
from serial_port import Singleton
import tkinter as tk
import subprocess

from PIL import Image

__author__ = 'Eremita'

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
app.config['DEBUG'] = False

#turn the flask app into a socketio app
socketio = SocketIO(app,async_mode = "threading",logging = False, engineio_logger = False)

#random number Generator Thread
thread = Thread()
thread_stop_event = Event()
                
serialPort = Singleton()




@app.route('/')
def index():
    return render_template('dev.html')

@app.route('/admin')
def admin():
    return render_template('dev.html')

@app.route('/dev')
def dev():
    return render_template('dev.html')

@app.route('/showbat')
def showbat():
    #launch app bat 
    #"C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\LowLevelBatt.png"
    print("***********************************************************")
    subprocess.call(["C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\venv\\Scripts\\python.exe", "C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\bat_app.py"])
    return jsonify({"result":"done"})

@app.route('/showbat_turnoff')
def showbat_turnoff():
    #launch app bat 
    #"C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\LowLevelBatt.png"
    print("***********************************************************")
    subprocess.call(["C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\venv\\Scripts\\python.exe", "C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\timer_test.py"])
    return jsonify({"result":"done"})

@socketio.on('message', namespace='/test')
def received_msg(data):
    global serialPort

    x = int(data['x'])
    y = int(data['y'])
    command = int(data['cmd'])

    serialPort.count+=1    
    if serialPort.count > 99999999:
        serialPort.count = 0    


    mystring = ("{cmd:"+ f'{command:02d}' + 
                ",t:" + f'{x:+03d}' +
                ",y:" + f'{y:+03d}' +
                ",hb:" + f'{serialPort.count:08d}' + 
                "};").encode("utf-8")
    print(mystring,flush=True)
    serialPort.ser.write(mystring)
    serialPort.ser.flush()

if __name__ == '__main__':
    socketio.run(app, host='0.0.0.0', port=5000, log_output = True)
    
