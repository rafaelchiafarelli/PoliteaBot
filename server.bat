netsh wlan set hostednetwork ssid=politeabotx86 key=politeabot
netsh wlan start hostednetwork
cd C:\Users\rafae\Documents\workspace\PoliteaBot\
call C:\Users\rafae\Documents\workspace\PoliteaBot\venv\Scripts\activate.bat
echo "Starting the application now!"

"C:\Users\rafae\Documents\workspace\PoliteaBot\venv\Scripts\python" "C:\Users\rafae\Documents\workspace\PoliteaBot\app.py"