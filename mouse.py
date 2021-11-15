import serial
from pynput.mouse import Button, Controller
import time
s= serial.Serial('COM10',115200)
mouse = Controller()
time.sleep(0.5)
b=0
while(1): 
    x=s.readline().decode().strip().split(' ')
    print(x)
    X=x[1]
    y=x[3]
    print(X)
    X=(int(X)-22)/10
    Y=(int(y)-23)/10
    k=int(x[5])
    if k>50:
        b=2
        mouse.press(Button.left)
    elif k<-50:
        b=1
        mouse.press(Button.right)
    else:
        if b==1:
            mouse.release(Button.right)
        if b==2:
            mouse.release(Button.left)
        b=0
    mouse.move(X, -Y)
    try:
        X=int(X)
        Y=int(y)
        print(x)
       

    except:
        continue