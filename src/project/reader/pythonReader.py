#!/usr/bin/python
import sys
import dataReader
import menu
import serial
from prettytable import PrettyTable
score = [0] * 32

def importData():
	global score
	port = raw_input("Type serial port name\n")
	try:
		data = dataReader.getGameDataFromSerial(port)
		for i in data.damagesDone:
			score[i.originatingPlayerId] = score[i.originatingPlayerId] + i.amountOfDamage 
	except serial.SerialException as err:
		print err[1]

def showScore():
	global score
	t = PrettyTable(['PlayerID','Score'])
	for i in range(1,len(score)):
		if score[i] is not 0:
			t.add_row([i,score[i]])
	t.sortby = "Score"
	t.reversesort = True
	print t

level1menu = [['Import Data',importData],['Show score',showScore],['Exit',exit]]

while True:
	menu.showMenu(level1menu)