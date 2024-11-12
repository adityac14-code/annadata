import time
from picamera import picamera

camera=picamera()

for i in range (1, 6):

	camera.start_preview()
	time.sleep(2)
	camera.capture('home/pi/desktop/images/image%d.jpg' %1)
	camera.stop_preview()

camera.close()
	
	