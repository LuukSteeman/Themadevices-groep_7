import serial
import game_pb2
def getGameDataFromSerial(serialPort):
    x = serial.Serial(port=serialPort,baudrate=38400,parity=serial.PARITY_NONE,stopbits=serial.STOPBITS_ONE,bytesize=serial.EIGHTBITS,timeout=1000)

    raw_input("Press enter to retrieve data\n")
    x.write("\n")
    length = x.readline()
    while "dataLength:" not in length:
        x.write("\n")
        length = x.readline()
    length = int(length.split(':')[1])
    data = ''
    lengthalreadyread = 0
    while lengthalreadyread < length:
        data = data + x.read()
        lengthalreadyread = lengthalreadyread + 1
    thingz = game_pb2.GameData()
    thingz.ParseFromString(data)
    return thingz