import RPi.GPIO as GPIO
import time
import atexit
import serial

def goodbye():
    print("Program exited successfully!")
    #pwm.stop()
    GPIO.cleanup()                  # resets GPIO ports used back to input mode  

atexit.register(goodbye)

max_power = 80
steering_power = 100

# Supress warnings
GPIO.setwarnings(False)

# Set GPIO mode
GPIO.setmode(GPIO.BCM)

class Motor:
    def __init__(self, in1, in2, enable):
        self.in1 = in1
        self.in2 = in2
        self.enable = enable

    def forward(self):
        GPIO.output(self.in1, GPIO.HIGH)
        GPIO.output(self.in2, GPIO.LOW)
    
    def reverse(self):
        GPIO.output(self.in1, GPIO.LOW)
        GPIO.output(self.in2, GPIO.HIGH)
        
    def left(self):
        GPIO.output(self.in1, GPIO.LOW)
        GPIO.output(self.in2, GPIO.HIGH)
        
    def right(self):
        GPIO.output(self.in1, GPIO.HIGH)
        GPIO.output(self.in2, GPIO.LOW)
        
    def power(self, duty):
        self.enable.ChangeDutyCycle(duty)

DIR_1 = 16#5
DIR_2 = 26#6   
DIR_3 = 5#16
DIR_4 = 6#26
EN_1 = 24
EN_2 = 20

GPIO.setup(DIR_1, GPIO.OUT)
GPIO.setup(DIR_2, GPIO.OUT)
GPIO.setup(DIR_3, GPIO.OUT)
GPIO.setup(DIR_4, GPIO.OUT)
GPIO.setup(EN_1, GPIO.OUT)
GPIO.setup(EN_2, GPIO.OUT)

#pwm = GPIO.PWM(EN_1, 2000)
#pwm.start(0)

# Create motor objects
Engine = Motor(DIR_3, DIR_4, EN_2)
Steering = Motor(DIR_1, DIR_2, EN_1)


ser = serial.Serial("/dev/ttyS0", 115200)
print("Before setup")
print("intput 5: {}", GPIO.input(DIR_1))
print("intput 6: {}", GPIO.input(DIR_2))
print("intput 16: {}", GPIO.input(DIR_3))
print("intput 26: {}", GPIO.input(DIR_4))
data = [0,0]
for i in range(2):
    print("forward")
    Engine.forward()
    Steering.right()
    print("intput 5: {}", GPIO.input(DIR_1))
    print("intput 6: {}", GPIO.input(DIR_2))
    print("intput 16: {}", GPIO.input(DIR_3))
    print("intput 26: {}", GPIO.input(DIR_4))    
    data = [255,100]
    ser.write(data)
    time.sleep(1)
    data = [0,0]
    ser.write(data)
    time.sleep(2)
    print("reverse")
    Engine.reverse()
    Steering.left()
    print("intput 5: {}", GPIO.input(DIR_1))
    print("intput 6: {}", GPIO.input(DIR_2))
    print("intput 16: {}", GPIO.input(DIR_3))
    print("intput 26: {}", GPIO.input(DIR_4))
    data = [255,100]
    ser.write(data)
    time.sleep(1)
    data = [0,0]
    ser.write(data)
    time.sleep(2)


""" Engine
for i in range(2):
    print("forward")
    Engine.forward()
    #pwm.ChangeDutyCycle(0)
    #GPIO.output(EN_2, GPIO.LOW)
    #time.sleep(1)
    #pwm.ChangeDutyCycle(100)
    GPIO.output(EN_2, GPIO.HIGH)
    time.sleep(0.5)
    #pwm.ChangeDutyCycle(0)
    GPIO.output(EN_2, GPIO.LOW)
    time.sleep(0.5)

    print("reverse")
    Engine.reverse()
    #pwm.ChangeDutyCycle(100)
    GPIO.output(EN_2, GPIO.HIGH)
    time.sleep(0.5)
    #pwm.ChangeDutyCycle(0)
    GPIO.output(EN_2, GPIO.LOW)
    time.sleep(0.5)
#"""

""" Steering
for i in range(2):
    print("Left")
    Steering.left()
    GPIO.output(EN_1, GPIO.HIGH)
    #Steering.power(steering_power)
    time.sleep(0.5)
    GPIO.output(EN_1, GPIO.LOW)
    #Steering.power(0)
    time.sleep(0.5)

    print("Right")
    Steering.right()
    GPIO.output(EN_1, GPIO.HIGH)
    #Steering.power(steering_power)
    time.sleep(0.5)
    GPIO.output(EN_1, GPIO.LOW)
    time.sleep(0.5)
#"""

# Set enable low
#Engine.power(0)
#Steering.power(0)

# Clean GPIOs
GPIO.cleanup()

print("Complete")
