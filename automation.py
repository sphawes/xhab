#This script is called when any of the buttons on our custom octoprint tab are clicked
#execution for engaging linear actuator: "automation.py 1"
#execution for disengaging linear actuator: "automation.py 2"
#etc, etc

import serial
import sys

ser=serial.Serial()

try:
    port = "/dev/cu.USB1"
    print "Attempting connection with " + port
    ser = serial.Serial(port, 9600, timeout=1)
except:
    print 'Connection Failed'
    break

command = sys.argv[0]

if command == "1":
    try:
        ser.write("1")
        print "Command Sent"
    except:
        print "Sending Failed"
elif command == "2":
    try:
        ser.write("2")
        print "Command Sent"
    except:
        print "Sending Failed"
elif command == "3":
    try:
        ser.write("3")
        print "Command Sent"
    except:
        print "Sending Failed"
elif command == "4":
    try:
        ser.write("4")
        print "Command Sent"
    except:
        print "Sending Failed"
elif command == "5":
    try:
        ser.write("5")
        print "Command Sent"
    except:
        print "Sending Failed"
elif command == "6":
    try:
        ser.write("6")
        print "Command Sent"
    except:
        print "Sending Failed"


ser.close()
