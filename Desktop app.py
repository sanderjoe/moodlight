from PIL import Image
import serial
import time

Serial = serial.Serial('com3', 9600)
time.sleep(3)



##
##x = 100
##y = 100
##im = Image.open("pic1.png")
###im.rotate(180).show()
##
##pix = im.load()
##print (im.size )
##print(pix[x,y])
##value = pix[x,y]
##

led20 = [1, 0, 0, 255]
led21 = [21, 255, 0, 0]
led22 = [22, 0, 255, 0]
led23 = [23, 255, 255, 255]

ledColors = [led20, led21, led22, led23]
ledCount = len(ledColors)
#ser.write(ledCount)
#dataBack = ser.readline()
#print("in: ", dataBack)    
i = 0

while i < ledCount:
    for led in ledColors:
        for value in led:
            data = bytes([value])
            print("out: ", data)
            Serial.write(data)
            dataBack = Serial.readline()
            print("in: ", dataBack)    
    print("Cycle nr :", i)
    i+=1
    time.sleep(0.1)
#while True:
#    dataBack = Serial.readline()
#    print("in: ", dataBack)
    
    
   
print("Done!")