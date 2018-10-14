import pandas
import serial
import matplotlib
import serial.tools.list_ports
import struct 
import re
import matplotlib.pyplot as plt
import numpy as np



ser = serial.Serial()

def getArduinoPort():
    ports = list(serial.tools.list_ports.comports())
    
    for p in ports:
        if("Arduino" in p[1]):
            return p[0]
    
    raise Exception('Arduino não conectado')


ser = serial.Serial("/dev/ttyUSB0",9200)


print("Conectando ao arduino arduino...")


ser.flush()
#nums = re.compile()

test = open("Dados.csv","w")
test.write("Acc(X),Acc(Y),Acc(Z),Angulo(X),Angulo(Y),Tempo\n")


accX = []
accY = []
accZ = []
angX = []
angY = []

try:
    while True:
        rawValue = str(ser.readline())

        try:
            values = re.findall(r"[+-]?\d+(?:\.\d+)?",rawValue)
        except AttributeError:
            print("-")
        
        writeData = ""

        for a in values:
            writeData += a +","
        
        accX.append(values[0])
        accY.append(values[1])
        accZ.append(values[2])
        angX.append(values[3])
        angY.append(values[4])

        print(writeData)
        test.write(writeData+"\n")
except KeyboardInterrupt:
    plt.plot(accX)
    plt.show()

    ser.close()

        
    
    
    
    
    


