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


ser = serial.Serial(getArduinoPort(),115200)

x = []
y = []
z = []

index = 0;

print("Conectando ao arduino arduino...")
while index < 5 :
    print(ser.readline())
    index +=1 
ser.write(struct.pack("B",int(input("Digite um numero para comecar>> "))))

index = 0 

while index<4:
    print(ser.readline())
    index += 1

index = 0

while index<100:
    ax = ser.readline()
    ax = ax.decode("utf-8")

    axis  = re.findall(r'\d+\.\d+',ax)
    
    if(2<=len(axis)):
        print(axis[2])
        x.append(axis[2])
    index += 1

plt.plot(x)
plt.show()
ser.flush()
ser.close()
