import RPi.GPIO as GPIO
import time
import atexit

def goodbye():
    print("Program exited successfully!")
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

DIR_1 = 6
DIR_2 = 5
DIR_3 = 26
DIR_4 = 16
EN_1 = 12
EN_2 = 13

GPIO.setup(DIR_1, GPIO.OUT)
GPIO.setup(DIR_2, GPIO.OUT)
GPIO.setup(DIR_3, GPIO.OUT)
GPIO.setup(DIR_4, GPIO.OUT)
GPIO.setup(EN_1, GPIO.OUT)
GPIO.setup(EN_2, GPIO.OUT)

pwm = GPIO.PWM(EN_1, 2000)
pwm.start(0)

# Create motor objects
Engine = Motor(DIR_3, DIR_4, EN_2)
Steering = Motor(DIR_1, DIR_2, EN_1)

#""" Engine
for i in range(5):
    print("forward")
    Engine.forward()
    GPIO.output(EN_2, GPIO.LOW)
    time.sleep(1)
    GPIO.output(EN_2, GPIO.HIGH)
    time.sleep(3)
    GPIO.output(EN_2, GPIO.LOW)


    print("reverse")
    Engine.reverse()
    GPIO.output(EN_2, GPIO.HIGH)
    time.sleep(3)
    GPIO.output(EN_2, GPIO.LOW)
#"""

#""" Steering
for i in range(5):
    print("Left")
    Steering.left()
    Steering.power(steering_power)
    time.sleep(2)

    Steering.power(0)
    time.sleep(1)

    print("Right")
    Steering.right()
    Steering.power(steering_power)
    time.sleep(2)
#"""

# Set enable low
Engine.power(0)
Steering.power(0)

# Clean GPIOs
GPIO.cleanup()

print("Complete")
