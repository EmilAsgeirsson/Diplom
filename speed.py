from pyPS4Controller.controller import Controller
import RPi.GPIO as GPIO
import atexit

def goodbye():
    print("Program exited successfully!")
    GPIO.cleanup()                  # resets GPIO ports used back to input mode  

atexit.register(goodbye)

GPIO.setmode(GPIO.BCM)      # Set Pi to use pin number when referencing GPIO pins.

# Front_left motor
front_left = 5
GPIO.setup(front_left, GPIO.OUT)
GPIO.output(front_left, GPIO.LOW)

front_right = 6
GPIO.setup(front_right, GPIO.OUT)
GPIO.output(front_right, GPIO.LOW)

# Rear motor
rear_reverse = 16
GPIO.setup(rear_reverse, GPIO.OUT)
GPIO.output(rear_reverse, GPIO.LOW)

rear_forward = 26
GPIO.setup(rear_forward, GPIO.OUT)
GPIO.output(rear_forward, GPIO.LOW)

# Horn
horn = 23
GPIO.setup(horn, GPIO.OUT)

front_pwm_gpio = 12
GPIO.setup(front_pwm_gpio, GPIO.OUT)          # Set GPIO pin 13 to output mode - Front.
GPIO.output(front_pwm_gpio, GPIO.LOW)

rear_pwm_gpio = 13
GPIO.setup(rear_pwm_gpio, GPIO.OUT)           # Set GPIO pin 13 to output mode - Rear.
GPIO.output(rear_pwm_gpio, GPIO.LOW)  

class MyController(Controller):

    def __init__(self, **kwargs):
        Controller.__init__(self, **kwargs)

    def on_R2_press(self,value):
        GPIO.output(rear_forward, 1)
        GPIO.output(rear_pwm_gpio, 1)
    
    def on_R2_release(self):
        GPIO.output(rear_forward, 0)
        GPIO.output(rear_pwm_gpio, 0)

    def on_R1_press(self):
        GPIO.output(rear_reverse, 1)
        GPIO.output(rear_pwm_gpio, 1)
    
    def on_R1_release(self):
        GPIO.output(rear_reverse, 0)
        GPIO.output(rear_pwm_gpio, 0)

    def on_L2_press(self,value):
        GPIO.output(front_right, 1)
        GPIO.output(front_pwm_gpio, 1)
    
    def on_L2_release(self):
        GPIO.output(front_right, 0)
        GPIO.output(front_pwm_gpio, 0)

    def on_L1_press(self):
        GPIO.output(front_left, 1)
        GPIO.output(front_pwm_gpio, 1)
    
    def on_L1_release(self):
        GPIO.output(front_left, 0)
        GPIO.output(front_pwm_gpio, 0)
    
    def on_up_arrow_press(self):
        GPIO.output(rear_forward, GPIO.HIGH)
        GPIO.output(rear_pwm_gpio, GPIO.HIGH)

    def on_up_down_arrow_release(self):
        GPIO.output(rear_pwm_gpio, GPIO.LOW)
        GPIO.output(rear_forward, GPIO.LOW)
        GPIO.output(rear_reverse, GPIO.LOW)

    def on_down_arrow_press(self):
        GPIO.output(rear_reverse, GPIO.HIGH)
        GPIO.output(rear_pwm_gpio, GPIO.HIGH)

    def on_left_arrow_press(self):
        GPIO.output(front_left, GPIO.HIGH)

    def on_left_right_arrow_release(self):
        GPIO.output(front_pwm_gpio, GPIO.LOW)
        GPIO.output(front_left, GPIO.LOW)
        GPIO.output(front_right, GPIO.LOW)

    def on_right_arrow_press(self):
        GPIO.output(front_right, GPIO.HIGH)


controller = MyController(interface="/dev/input/js0", connecting_using_ds4drv=False)
# you can start listening before controller is paired, as long as you pair it within the timeout window

controller.listen(timeout=60)   