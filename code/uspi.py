import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
trigger = 17
echo = 27

GPIO.setup(trigger, GPIO.OUT)
GPIO.setup(echo, GPIO.IN)

def distance():
    GPIO.output(trigger, True)
    time.sleep(0.00001)
    GPIO.output(trigger, False)
    start = time.time()
    while GPIO.input(echo) == 0:
        start = time.time()
    while GPIO.input(echo) == 1:
        stop = time.time()
    elapsed = stop - start
    distance = (elapsed * 34300) / 2
    return distance

try:
    while True:
        dist = distance()
        print(f"Distance: {dist:.2f} cm")
        time.sleep(1)
        
except KeyboardInterrupt:
    GPIO.cleanup()