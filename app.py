"""
Create a webpage that is constantly updated with random numbers from a background python process.
"""

# Start with a basic flask app webpage.

from flask import Flask, request, render_template, url_for, copy_current_request_context

from random import random
from time import sleep
from threading import Thread, Event
from random import randint
import json
from model import limits, steering, movement
from socket import socket, AF_INET, SOCK_DGRAM
__author__ = 'Eremita'

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
app.config['DEBUG'] = False




@app.route('/')
def index():
    return render_template('dev.html')

@app.route('/admin')
def admin():
    return render_template('dev.html')

@app.route('/dev')
def dev():
    return render_template('dev.html')

@app.route('/message', methods=['POST'])
def received_msg():
    content = request.data
    SERVER_IP   = "127.0.0.1"
    PORT_NUMBER = 4000
    SIZE = 1024
    
    mySocket = socket( AF_INET, SOCK_DGRAM )
    data_str = bytes(str(content).encode("utf-8"))
    mySocket.sendto(data_str,(SERVER_IP,PORT_NUMBER))
    return str(content)



if __name__ == '__main__':
    app.run()
