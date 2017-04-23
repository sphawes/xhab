#This script is called when any of the buttons on our custom octoprint tab are clicked
#execution for engaging linear actuator: "python automation.py 1"
#execution for disengaging linear actuator: "python automation.py 2"
#etc, etc

import serial
import cgi

ser=serial.Serial()

try:
    port = "/dev/ttyAMA0"
    print "Attempting connection with " + port
    ser = serial.Serial(port, 9600, timeout=1)
except:
    print 'Connection Failed'
    break

arguments = cgi.FieldStorage()
command = str(arguments[0].value)

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
else:
    print "Invalid argument. Please follow the script with a numeral 1-6."


ser.close()
