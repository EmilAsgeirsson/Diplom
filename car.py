from pyPS4Controller.controller import Controller
import RPi.GPIO as GPIO
    
    
class MyController(Controller):

    camera = False 

    GPIO.setmode(GPIO.BOARD)    # Set Pi to use pin number when referencing GPIO pins.
                                # Can use GPIO.setmode(GPIO.BCM) instead to use 
                                # Broadcom SOC channel names.
    
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
    frontpwm = GPIO.PWM(frontpwngpio,1000)  # Set PWM frequency to 1000 Hz
    GPIO.setup(rearpwngpio, GPIO.OUT)       # Set GPIO pin 13 to output mode - Rear.
    rearpwm = GPIO.PWM(rearpwngpio,1000)    # Set PWM frequency to 1000 Hz
    
    

    def __init__(self, **kwargs):
        Controller.__init__(self, **kwargs)
    
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
        GPIO.output(horn, GPIO.HIGH)

    def on_square_release(self):
        GPIO.output(horn, GPIO.LOW)
           
    # Setup drive forward       
    def on_R1_press(self):
        print("State: Drive")
        GPIO.output(engine1, GPIO.LOW)
        GPIO.output(engine2, GPIO.HIGH)

    def on_R2_press(self, value):
        print("on_R2_press: {}".format(value))
        # Requires logic to convert the value to a pwm percentage
        rearpwm.ChangeDutyCycle(75)     # 75 for 75 %

    # Set PWM to 0 to turn off engine
    def on_R2_release(self):
        rearpwm.ChangeDutyCycle(0)
    
    # Setup drive backwards
    def on_L1_press(self):
        print("State: Reverse")
        GPIO.output(rearengine1, GPIO.HIGH)
        GPIO.output(rearengine2, GPIO.LOW)

    def on_L2_press(self, value):
        print("on_L2_press: {}".format(value))
        # Requires logic to convert the value to a pwm percentage
        rearpwm.ChangeDutyCycle(70)     # 70 for 70 %

    # Set PWM to 0 to turn off engine
    def on_L2_release(self):
        rearpwm.ChangeDutyCycle(0)

    # Turn car
    def on_L3_left(self, value):
        #print("on_L3_left: {}".format(value))
        GPIO.output(frontengine1, GPIO.HIGH)
        GPIO.output(frontengine2, GPIO.LOW)
        frontpwm.ChangeDutyCycle(75)


    def on_L3_right(self, value):
        #print("on_L3_right: {}".format(value))
        GPIO.output(frontengine1, GPIO.LOW)
        GPIO.output(frontengine2, GPIO.HIGH)
        frontpwm.ChangeDutyCycle(75)

     def on_L3_y_at_rest(self):
        """L3 joystick is at rest after the joystick was moved and let go off"""
        print("on_L3_y_at_rest")
        frontpwm.ChangeDutyCycle(0)

    # Do nothing commands
    def on_x_release(self):    

    def on_R1_release(self):
        
    def on_L1_release(self):


# If gpio 16 is postive and gpio 26 is negative, the engine turns one way. If changes it drives the other way - make a specific button for this. PWM signal value is Gpio 13

# Gpio 12 is pwm for turning. Gpio 5 and 6 is used to determine which direction.

controller = MyController(interface="/dev/input/js0", connecting_using_ds4drv=False)
# you can start listening before controller is paired, as long as you pair it within the timeout window
controller.listen(timeout=60)


pwm.stop()                         # stop PWM
GPIO.cleanup()                     # resets GPIO ports used back to input mode