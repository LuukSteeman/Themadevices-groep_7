#!/usr/bin/python
import serial
import sys
x = serial.Serial(port='/dev/ttyACM0',baudrate=38400,parity=serial.PARITY_NONE,stopbits=serial.STOPBITS_ONE,bytesize=serial.EIGHTBITS)
print >> sys.stderr, 'Press enter to continue'
raw_input()
x.write("\n".encode())

length = x.readline()
length = int(length)
print >> sys.stderr, length
lengthalreadyread = 0
while lengthalreadyread < length:
	sys.stdout.write(x.read())
	lengthalreadyread = lengthalreadyread + 1