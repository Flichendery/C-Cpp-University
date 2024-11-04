import cv
import numpy as np

image = cv.imread("1.png")
gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)

#Create SURF Feature Detector object
surf = cv.surf

# Only features, whose hessian is larger than hessianThreshold are retained by the detector
surf.hessianThreshold = 500
keypoints, descriptors = surf.detectAndCompute(gray, None)
print("Number of keypoints Detected: ", len(keypoints))

# Draw rich key points on input image
image = cv.drawKeypoints(image, keypoints, flags=cv.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)

cv.imshow('Feature Method - SURF', image)
cv.waitKey()