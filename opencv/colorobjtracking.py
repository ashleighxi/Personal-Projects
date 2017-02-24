import cv2
import numpy as np 

cap = cv2.VideoCapture(0)


while(1):
	# take each frame
	_, frame = cap.read()

	# convert BGR to HSV
	hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

	# define range of blue color in HSV
	lower_red = np.array([170,50,50])
	upper_red = np.array([179,255,255])
	lower_green = np.array([50,100,100])
	upper_green = np.array([70,255,255])

	# threshold the HSV image for only blue
	mask = cv2.inRange(hsv, lower_red, upper_red)
	mask2 = cv2.inRange(hsv, lower_green, upper_green)
	 
	

	# bitwise-AND mask and original image
	# res = cv2.add(cv2.bitwise_and(frame, frame, mask = mask), cv2.bitwise_and(frame, frame, mask = mask2))
	res = cv2.bitwise_and(frame, frame, mask = mask) + cv2.bitwise_and(frame, frame, mask = mask2)

	blur = cv2.bilateralFilter(res,9,75,75)

	# cv2.imshow('frame', frame)
	cv2.imshow('mask', mask)
	cv2.imshow('res', res)
	cv2.imshow('blur', blur)
	k = cv2.waitKey(5) & 0xFF
	if k == 27:
		break

cv2.destroyAllWindows()
cap.release()
