from pyPS4Controller.controller import Controller
import RPi.GPIO as GPIO
import math
import atexit

def goodbye():
    print("Program exited successfully!")
    MyController.frontpwm.stop()    # stop PWM
    MyController.rearpwm.stop()  
    GPIO.cleanup()                  # resets GPIO ports used back to input mode  

atexit.register(goodbye)

class MyController(Controller):

    camera = False 
    max_value = 32767

    GPIO.setmode(GPIO.BCM)      # Set Pi to use pin number when referencing GPIO pins.
    
    # Front motor
    frontengine1 = 5
    frontengine2 = 6
    GPIO.setup(frontengine1, GPIO.OUT)
    GPIO.setup(frontengine2, GPIO.OUT)

    # Rear motor
    rearengine1 = 16
    rearengine2 = 26
    GPIO.setup(rearengine1, GPIO.OUT)
    GPIO.setup(rearengine2, GPIO.OUT)

    # Horn
    horn = 20
    GPIO.setup(horn, GPIO.OUT)

    #Pwm
    frontpwngpio = 12
    rearpwngpio = 13
    GPIO.setup(frontpwngpio, GPIO.OUT)      # Set GPIO pin 13 to output mode - Front.
    frontpwm = GPIO.PWM(frontpwngpio,2000)  # Set PWM frequency to 1000 Hz
    frontpwm.start(0)
    GPIO.setup(rearpwngpio, GPIO.OUT)       # Set GPIO pin 13 to output mode - Rear.
    rearpwm = GPIO.PWM(rearpwngpio,2000)    # Set PWM frequency to 1000 Hz
    rearpwm.start(0)
    

    def __init__(self, **kwargs):
        Controller.__init__(self, **kwargs)
    
    def get_percentage(value):
        return math.trunc(((value + MyController.max_value) / (MyController.max_value*2)) * 100)

    # Turn on and off camera
    def on_x_press(self):
       if MyController.camera is True:
         print("Turn off camera")
         MyController.camera = False
       else:
         print("Turn on Camera")
         MyController.camera = True

    # Horn
    def on_square_press(self):
        GPIO.output(MyController.horn, GPIO.HIGH)

    def on_square_release(self):
        GPIO.output(MyController.horn, GPIO.LOW)
           
    # Setup drive forward       
    def on_R1_press(self):
        print("State: Drive")
        GPIO.output(MyController.rearengine1, GPIO.LOW)
        GPIO.output(MyController.rearengine2, GPIO.HIGH)

    def on_R2_press(self, value):
        percentage = MyController.get_percentage(value)
        print("on_R2_press: {} %".format(percentage))
        MyController.rearpwm.ChangeDutyCycle(percentage)     

    # Set PWM to 0 to turn off engine
    def on_R2_release(self):
        MyController.rearpwm.ChangeDutyCycle(0)
    
    # Setup drive backwards
    def on_L1_press(self):
        print("State: Reverse")
        GPIO.output(MyController.rearengine1, GPIO.HIGH)
        GPIO.output(MyController.rearengine2, GPIO.LOW)

    def on_L2_press(self, value):
        percentage = MyController.get_percentage(value)
        MyController.rearpwm.ChangeDutyCycle(percentage)

    # Set PWM to 0 to turn off engine
    def on_L2_release(self):
        MyController.rearpwm.ChangeDutyCycle(0)

    # Turn car
    def on_L3_left(self, value):
        percentage = math.trunc((abs(value) / (MyController.max_value)) * 100)
        GPIO.output(MyController.frontengine1, GPIO.HIGH)
        GPIO.output(MyController.frontengine2, GPIO.LOW)
        MyController.frontpwm.ChangeDutyCycle(percentage)


    def on_L3_right(self, value):
        percentage = math.trunc((value / (MyController.max_value)) * 100)
        GPIO.output(MyController.frontengine1, GPIO.LOW)
        GPIO.output(MyController.frontengine2, GPIO.HIGH)
        MyController.frontpwm.ChangeDutyCycle(percentage)

    def on_L3_y_at_rest(self):
        """L3 joystick is at rest after the joystick was moved and let go off"""
        print("on_L3_y_at_rest")
        MyController.frontpwm.ChangeDutyCycle(0)
    
    def on_L3_x_at_rest(self):
        """L3 joystick is at rest after the joystick was moved and let go off"""
        print("on_L3_x_at_rest")
        MyController.frontpwm.ChangeDutyCycle(0)

    def on_left_arrow_press(self):
        GPIO.output(MyController.frontengine1, GPIO.HIGH)
        GPIO.output(MyController.frontengine2, GPIO.LOW)
        MyController.frontpwm.ChangeDutyCycle(100)

    def on_left_right_arrow_release(self):
        MyController.frontpwm.ChangeDutyCycle(0)

    def on_right_arrow_press(self):
        GPIO.output(MyController.frontengine1, GPIO.LOW)
        GPIO.output(MyController.frontengine2, GPIO.HIGH)
        MyController.frontpwm.ChangeDutyCycle(100)

    def on_right_arrow_release(self):
        MyController.frontpwm.ChangeDutyCycle(0)

    # Do nothing commands
    def on_x_release(self):
        pass    

    def on_R1_release(self):
        pass
        
    def on_L1_release(self):
        pass


# If gpio 16 is postive and gpio 26 is negative, the engine turns one way. If changes it drives the other way - make a specific button for this. PWM signal value is Gpio 13

# Gpio 12 is pwm for turning. Gpio 5 and 6 is used to determine which direction.

controller = MyController(interface="/dev/input/js0", connecting_using_ds4drv=False)
# you can start listening before controller is paired, as long as you pair it within the timeout window

controller.listen(timeout=60)   