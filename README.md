# Flask webserver + Video Streammer + Arduino PlatformIO 

## Intro
This section deals with the robot itself. As discussed earlier, this robot is a sum of 4 main parts, and this is the Software part that is meant to control and allow access to all other parts.

General Requirements:
---------------------
* Internet connection
* stable power supply
* 
## Deploy
Clone and compile this repo into a linux machine.
---------------------------------------------

git clone git@github.com:rafaelchiafarelli/PoliteaBot.git
cd PoliteaBot
./deploy.sh

The script will require "sudo".

## Development
Create the Development Environment
----------------------------------
*Requires:*
* Windows 10
* VSCode installed
* PlatformIO plugging for VSCode Installed.
* Python3.8 installed
* WebCam installed
* IP Camera installed
* Arduino Mega 2650 available

*Step 1:*
git clone git@github.com:rafaelchiafarelli/PoliteaBot.git
cd Politeabot

*Step 2:* 
./configure.sh
The script will require "sudo"

*Step 3:*
Start the virtual environment
source venv/bin/activate

*Step 4:*
Compile LowLovel
Go to VSCode and compile arduino project

Future works
------------
* Opening Statements
This development is raw and still on-going, so far little has been done to help peopple to contribute. No debug tool is provided and no validation or testing tool was created. Documentation is bad (to say the least) and architecture was develop to serve an awkard purpose (movie).
* future works
- virtual tools to allow others to contribute.
- document with text and pictures the architecture
- create a testing suit to allow users to ensure there development is working
* Closing thougts
The application and device are really cool, a testimony to today state of development. Features that ware really strange to figure out ware the ones with the most simplicity to develop, as example, the overlay of battery signal. Although it is very simple to implement, it did took some time to understand that the batery did not need to "realy die". On that regar, the implementation of speed and direction control was really difficult. And that's because there is no formula for the approuch. Controlling the device is really strange, but intuitive at the same time. weird.


Courtesy
--------

This project is based on following repos,

Flask WebSocket Example 1 : [FLASK](https://github.com/shanealynn/async_flask)

Flask WebSocket Example 2 : [FLASK](https://github.com/miguelgrinberg/Flask-SocketIO)

Virtual Joystick : [vJoyStick](https://github.com/jeromeetienne/virtualjoystick.js)

