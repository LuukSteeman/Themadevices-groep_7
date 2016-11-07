#!/usr/bin/python
import serial
import sys
import game_pb2
x = serial.Serial(port='/dev/ttyACM0',baudrate=38400,parity=serial.PARITY_NONE,stopbits=serial.STOPBITS_ONE,bytesize=serial.EIGHTBITS)

raw_input("Press enter to retrieve data\n")
x.write("\n")
length = x.readline()
length = int(length)
data = ''
lengthalreadyread = 0
while lengthalreadyread < length:
	data = data + x.read()
	lengthalreadyread = lengthalreadyread + 1
thingz = game_pb2.GameData()
thingz.ParseFromString(data)
print thingz