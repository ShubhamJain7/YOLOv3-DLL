from ctypes import *
import sys

# define absolute path to image
image_path = 'C:/Users/dell/source/repos/YOLOv3-DLL/test.jpg'

# define class labels
CLASSES = ['person', 'bicycle', 'car', 'motorbike', 'aeroplane', 'bus', 'train', 'truck', 'boat', 
		   'traffic light', 'fire hydrant', 'stop sign', 'parking meter', 'bench', 'bird', 'cat', 
		   'dog', 'horse', 'sheep', 'cow', 'elephant', 'bear', 'zebra', 'giraffe', 'backpack', 
		   'umbrella', 'handbag', 'tie', 'suitcase', 'frisbee', 'skis', 'snowboard', 'sports ball', 
		   'kite', 'baseball bat', 'baseball glove', 'skateboard', 'surfboard', 'tennis racket', 
		   'bottle', 'wine glass', 'cup', 'fork', 'knife', 'spoon', 'bowl', 'banana', 'apple', 
		   'sandwich', 'orange', 'broccoli', 'carrot', 'hot dog', 'pizza', 'donut', 'cake', 
		   'chair', 'sofa', 'potted plant', 'bed', 'dining table', 'toilet', 'tv monitor', 'laptop', 
		   'mouse', 'remote', 'keyboard', 'cell phone', 'microwave', 'oven', 'toaster', 'sink', 
		   'refrigerator', 'book', 'clock', 'vase', 'scissors', 'teddy bear', 'hair drier', 'toothbrush']

# python definition of 'Detection' struc
class Detection(Structure):
	_fields_ = [("classId", c_int),
				("probability", c_float),
				("x", c_int),
				("y", c_int),
				("width", c_int),
				("height", c_int),]

# load dependant DLLs
opencv_core430 = CDLL("C:/Users/dell/source/repos/YOLOv3-DLL/Release/opencv_core430.dll")
opencv_imgproc430 = CDLL("C:/Users/dell/source/repos/YOLOv3-DLL/Release/opencv_imgproc430.dll")
opencv_imgcodecs430 = CDLL("C:/Users/dell/source/repos/YOLOv3-DLL/Release/opencv_imgcodecs430.dll")
opencv_dnn430 = CDLL("C:/Users/dell/source/repos/YOLOv3-DLL/Release/opencv_dnn430.dll")

# load required DLL
lib = CDLL("C:/Users/dell/source/repos/YOLOv3-DLL/Release/YOLOv3-DLL.dll")

# define return type and arguments of 'doDetection' function
lib.doDetection.restype = c_int
lib.doDetection.argtypes = [c_char_p]

# call 'doDetection' function and get number of objects detected 
res = lib.doDetection(image_path.encode('utf-8'))
DetectedObjectsArray = Detection * res

# continue if objects were detected
if res!=0:
	# define return type and arguments of 'getDetections' function
	lib.getDetections.restype = c_int
	lib.getDetections.argtypes = [POINTER(DetectedObjectsArray), c_int]

	# define array to store 'Detection's and call the 'getDetections' function
	objects = DetectedObjectsArray()
	_ = lib.getDetections(objects, res)

	# display results
	for d in objects:
		classLabel = CLASSES[d.classId]
		print(f'{classLabel}({d.probability}):[{d.x},{d.y},{d.width},{d.height}]')
else:
	print("No objects detected in image.")