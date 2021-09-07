from pyPS4Controller.controller import Controller
import RPi.GPIO as GPIO
import math
import atexit
import time

def goodbye():
    print("Program exited successfully!")
    MyController.frontpwm.ChangeDutyCycle(0)    # stop PWM
    MyController.rearpwm.ChangeDutyCycle(0)  
    GPIO.cleanup()                  # resets GPIO ports used back to input mode  

atexit.register(goodbye)

class MyController(Controller):

    camera = False 
    max_value = 32768

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

    #Pwm
    front_pwm_gpio = 12
    GPIO.setup(front_pwm_gpio, GPIO.OUT)          # Set GPIO pin 13 to output mode - Front.
    frontpwm = GPIO.PWM(front_pwm_gpio, 2000)     # Set PWM frequency to 1000 Hz
    frontpwm.start(0)

    rear_pwm_gpio = 13
    GPIO.setup(rear_pwm_gpio, GPIO.OUT)           # Set GPIO pin 13 to output mode - Rear.
    #GPIO.output(rear_pwm_gpio, GPIO.LOW)
    rearpwm = GPIO.PWM(rear_pwm_gpio, 2000)       # Set PWM frequency to 1000 Hz
    rearpwm.start(0)
    

    def __init__(self, **kwargs):
        Controller.__init__(self, **kwargs)
    
    def get_percentage(value):
        percentage = math.trunc((abs(value) / MyController.max_value) * 100)
        if percentage < 50:
            percentage = 0
        elif percentage >= 50 and percentage < 75:
            percentage = 75
        else:
            percentage = 100
        return percentage

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

    def buzz(noteFreq, duration):
        halveWaveTime = 1 / (noteFreq * 2 )
        waves = int(duration * noteFreq)
        for i in range(waves):
            GPIO.output(MyController.horn, True)
            time.sleep(halveWaveTime)
            GPIO.output(MyController.horn, False)
            time.sleep(halveWaveTime)

    def on_triangle_press(self):
        t=0
        notes=[262,294,330,262,262,294,330,262,330,349,392,330,349,392,392,440,392,349,330,262,392,440,392,349,330,262,262,196,262,262,196,262]
        duration=[0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,1,0.5,0.5,1,0.25,0.25,0.25,0.25,0.5,0.5,0.25,0.25,0.25,0.25,0.5,0.5,0.5,0.5,1,0.5,0.5,1]
        for n in notes:
            MyController.buzz(n, duration[t])
            time.sleep(duration[t] *0.1)
            t+=1

    def on_R2_press(self, value):
        percentage = math.trunc(((value+MyController.max_value) / (MyController.max_value*2)) * 100)
        GPIO.output(MyController.rear_forward, GPIO.HIGH)
        GPIO.output(MyController.rear_reverse, GPIO.LOW)
        MyController.rearpwm.ChangeDutyCycle(percentage)

    def on_L2_press(self, value):
        percentage = math.trunc(((value+MyController.max_value) / (MyController.max_value*2)) * 100)
        GPIO.output(MyController.rear_forward, GPIO.LOW)
        GPIO.output(MyController.rear_reverse, GPIO.HIGH)
        MyController.rearpwm.ChangeDutyCycle(percentage)

    def on_R2_release(self):
        MyController.rearpwm.ChangeDutyCycle(0)
    
    def on_L2_release(self):
        MyController.rearpwm.ChangeDutyCycle(0)

    def on_R3_up(self, value):
        percentage = MyController.get_percentage(value)
        GPIO.output(MyController.rear_forward, GPIO.HIGH)
        GPIO.output(MyController.rear_reverse, GPIO.LOW)
        MyController.rearpwm.ChangeDutyCycle(percentage)

    def on_R3_down(self, value):
        percentage = MyController.get_percentage(value)
        GPIO.output(MyController.rear_forward, GPIO.LOW)
        GPIO.output(MyController.rear_reverse, GPIO.HIGH)
        MyController.rearpwm.ChangeDutyCycle(percentage)

    def on_L3_left(self, value):
        percentage = MyController.get_percentage(value)
        GPIO.output(MyController.front_left, GPIO.HIGH)
        GPIO.output(MyController.front_right, GPIO.LOW)
        MyController.frontpwm.ChangeDutyCycle(percentage)

    def on_L3_right(self, value):
        percentage = MyController.get_percentage(value)
        GPIO.output(MyController.front_left, GPIO.LOW)
        GPIO.output(MyController.front_right, GPIO.HIGH)
        MyController.frontpwm.ChangeDutyCycle(percentage)

    def on_R3_y_at_rest(self):
        MyController.rearpwm.ChangeDutyCycle(0)

    # def on_R3_x_at_rest(self):
    #     MyController.rearpwm.ChangeDutyCycle(0)

    # Turn car
    # def on_L3_left(self, value):
    #     percentage = math.trunc((abs(value) / (MyController.max_value)) * 100)
    #     GPIO.output(MyController.front_left, GPIO.HIGH)
    #     GPIO.output(MyController.front_right, GPIO.LOW)
    #     #MyController.frontpwm.ChangeDutyCycle(percentage)
    #     MyController.frontpwm.ChangeDutyCycle(100)

    # def on_L3_right(self, value):
    #     percentage = math.trunc((value / (MyController.max_value)) * 100)
    #     GPIO.output(MyController.front_left, GPIO.LOW)
    #     GPIO.output(MyController.front_right, GPIO.HIGH)
    #     #MyController.frontpwm.ChangeDutyCycle(percentage)
    #     MyController.frontpwm.ChangeDutyCycle(100)

    # def on_L3_y_at_rest(self):
    #     MyController.frontpwm.ChangeDutyCycle(0)
    
    def on_L3_x_at_rest(self):
         MyController.frontpwm.ChangeDutyCycle(0)


    def on_left_arrow_press(self):
        GPIO.output(MyController.front_left, GPIO.HIGH)
        GPIO.output(MyController.front_right, GPIO.LOW)
        MyController.frontpwm.ChangeDutyCycle(100)

    def on_left_right_arrow_release(self):
        MyController.frontpwm.ChangeDutyCycle(0)

    def on_right_arrow_press(self):
        GPIO.output(MyController.front_left, GPIO.LOW)
        GPIO.output(MyController.front_right, GPIO.HIGH)
        MyController.frontpwm.ChangeDutyCycle(100)

    def on_right_arrow_release(self):
        MyController.frontpwm.ChangeDutyCycle(0)

    def on_up_arrow_press(self):
        GPIO.output(MyController.rear_forward, GPIO.HIGH)
        GPIO.output(MyController.rear_reverse, GPIO.LOW)
        MyController.rearpwm.ChangeDutyCycle(100)

    def on_up_arrow_release(self):
        MyController.rearpwm.ChangeDutyCycle(0)

    def on_down_arrow_press(self):
        GPIO.output(MyController.rear_forward, GPIO.LOW)
        GPIO.output(MyController.rear_reverse, GPIO.HIGH)
        MyController.rearpwm.ChangeDutyCycle(100)

    def on_down_arrow_release(self):
        MyController.rearpwm.ChangeDutyCycle(0)

    def on_up_down_arrow_release(self):
        MyController.rearpwm.ChangeDutyCycle(0)

    def reset_gpio():
        MyController.rearpwm.ChangeDutyCycle(0)
        MyController.frontpwm.ChangeDutyCycle(0)
        GPIO.cleanup() 
        GPIO.setmode(GPIO.BCM)      # Set Pi to use pin number when referencing GPIO pins.
    
        # Front_left motor
        MyController.front_left = 5
        GPIO.setup(MyController.front_left, GPIO.OUT)
        GPIO.output(MyController.front_left, GPIO.LOW)
        
        MyController.front_right = 6
        GPIO.setup(MyController.front_right, GPIO.OUT)
        GPIO.output(MyController.front_right, GPIO.LOW)

        # Rear motor
        MyController.rear_reverse = 16
        GPIO.setup(MyController.rear_reverse, GPIO.OUT)
        GPIO.output(MyController.rear_reverse, GPIO.LOW)

        MyController.rear_forward = 26
        GPIO.setup(MyController.rear_forward, GPIO.OUT)
        GPIO.output(MyController.rear_forward, GPIO.LOW)
        
        # Horn
        MyController.horn = 23
        GPIO.setup(MyController.horn, GPIO.OUT)

        #Pwm
        MyController.front_pwm_gpio = 12
        
        GPIO.setup(MyController.front_pwm_gpio, GPIO.OUT)          # Set GPIO pin 13 to output mode - Front.
        MyController.frontpwm = GPIO.PWM(MyController.front_pwm_gpio, 2000)     # Set PWM frequency to 1000 Hz
        MyController.frontpwm.start(0)
        
        MyController.rear_pwm_gpio = 13
        GPIO.setup(MyController.rear_pwm_gpio, GPIO.OUT)           # Set GPIO pin 13 to output mode - Rear.
        MyController.rearpwm = GPIO.PWM(MyController.rear_pwm_gpio, 2000)       # Set PWM frequency to 1000 Hz
        MyController.rearpwm.start(0)

    # Do nothing commands
    # def on_x_release(self):
    #     pass    

    # #def on_L3_up(self, value):
    #     pass

    # #def on_L3_down(self, value):
    #     pass

    # def on_L3_y_at_rest(self):
    #     pass

    # def on_L3_x_at_rest(self):
    #     pass

    # def on_R3_right(self, value):
    #     pass

    # def on_R3_left(self, value):
    #     pass

    # def on_R3_y_at_rest(self):
    #     pass

    # def on_R3_x_at_rest(self):
    #     pass


# If gpio 16 is postive and gpio 26 is negative, the engine turns one way. If changes it drives the other way - make a specific button for this. PWM signal value is Gpio 13

# Gpio 12 is pwm for turning. Gpio 5 and 6 is used to determine which direction.

controller = MyController(interface="/dev/input/js0", connecting_using_ds4drv=False)
# you can start listening before controller is paired, as long as you pair it within the timeout window

controller.listen(timeout=60)   