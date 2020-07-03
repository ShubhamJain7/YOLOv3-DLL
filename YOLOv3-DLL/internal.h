#pragma once
#include<vector>

struct Detection {
	int classId;
	float probability;
	int x;
	int y;
	int width;
	int height;
};

// declare file paths
//const char configFile[] = "C:/Users/dell/source/repos/YOLOv3-DLL/models/yolov3.cfg";
//const char weightsFile[] = "C:/Users/dell/source/repos/YOLOv3-DLL/models/yolov3.weights";

// declare constants
const float conf_threshold = 0.5f;
const float nms = 0.4f;
const int width = 416;
const int height = 416;

std::vector<Detection> _getDetections(char* configFile, char* weightsFile, char* image_path);