from pyPS4Controller.controller import Controller
import math

class MyController(Controller):

    R2_max_value = 0
    R2_min_value = 0
    L2_max_value = 0
    L2_min_value = 0
    max_value = 32767

    def __init__(self, **kwargs):
        Controller.__init__(self, **kwargs)

    def get_percentage(value):
        return math.trunc(((value + MyController.max_value) / (MyController.max_value*2)) * 100)

    def on_R2_press(self, value):
        percentage = MyController.get_percentage(value)
        print("on_R2_press: {} %".format(math.trunc(percentage)))
        if MyController.R2_max_value < value:
            MyController.R2_max_value = value
        if MyController.R2_min_value > value:
            MyController.R2_min_value = value
    
    def on_R2_release(self):
        print("R2_max_value: {}".format(MyController.R2_max_value))
        print("R2_min_value: {}".format(MyController.R2_min_value))
        MyController.R2_max_value = 0
        MyController.R2_min_value = 0

    def on_L2_press(self, value):
        # The value ranges from -32767 to 32767 - the value is moved to between 0 and 65534
        percentage = MyController.get_percentage(value)
        print("on_L2_press: {} %".format(math.trunc(percentage)))
        if MyController.L2_max_value < value:
            MyController.L2_max_value = value
        if MyController.L2_min_value > value:
            MyController.L2_min_value = value

    def on_L2_release(self):
        print("L2_max_value: {}".format(MyController.L2_max_value))
        print("L2_min_value: {}".format(MyController.L2_min_value))
        MyController.L2_max_value = 0
        MyController.L2_min_value = 0


controller = MyController(interface="/dev/input/js0", connecting_using_ds4drv=False)
# you can start listening before controller is paired, as long as you pair it within the timeout window
controller.listen(timeout=60)