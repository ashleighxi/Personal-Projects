import cv2
import numpy as np 

img1 = cv2.imread('blending.jpg')
img2 = cv2.imread('overlay.jpg')

dst = cv2.add(img1,img2)

cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()