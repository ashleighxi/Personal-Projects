import numpy as np 
import cv2

cap = cv2.VideoCapture(0)

while (1):
	_, frame = cap.read()

	hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
	upper_red = np.array([170,100,100])
	lower_red = np.array([179,255,255])

	mask = cv2.inRange(hsv, lower_red, upper_red)

	res = cv2.bitwise_and(frame, frame, mask = mask)

	#blur = cv2.bilateralFilter(res, 9, 75, 75)

	cv2.imshow('frame', frame)
	cv2.imshow('res', res)
	#cv2.imshow('blur', blur)
	k = cv2.waitKey(5) & 0xFF
	if k == 27:
		break

cv2.destroyAllWindows()
cap.release()