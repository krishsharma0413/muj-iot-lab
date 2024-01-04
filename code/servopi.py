import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

servo = 17

GPIO.setup(servo, GPIO.OUT)

pwm = GPIO.PWM(servo, 50)
pwm.start(0)

def set_angle(angle):
    duty = angle / 18 + 2
    pwm.ChangeDutyCycle(duty)
    time.sleep(0.5)

try:
    while True:
        # anles in degrees
        set_angle(0)
        set_angle(90)
        set_angle(180)

except KeyboardInterrupt:
    pwm.stop()
    GPIO.cleanup()