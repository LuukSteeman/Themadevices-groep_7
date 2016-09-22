#!/bin/bash

if [[ "$EUID" -ne 0 ]]
  then echo "get root bro"
  exit
fi

python -c "import serial; \
ser = serial.Serial(port='/dev/$1',baudrate=1200,parity=serial.PARITY_NONE,stopbits=serial.STOPBITS_ONE,bytesize=serial.EIGHTBITS);"

sleep 1

./bossac -i -p "$1" -U false -e -w -v -b "$2" -R
