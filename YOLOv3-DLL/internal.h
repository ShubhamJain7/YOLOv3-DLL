#pragma once
#include<vector>
#include<string>

struct Detection {
	int classId;
	float probability;
	int x;
	int y;
	int width;
	int height;
};

// declare file paths
const std::string configFile = "C:/Users/dell/source/repos/YOLOv3-DLL/models/yolov3.cfg";
const std::string weightsFile = "C:/Users/dell/source/repos/YOLOv3-DLL/models/yolov3.weights";

// declare constants
const float conf_threshold = 0.5f;
const float nms = 0.4f;
const int width = 416;
const int height = 416;

std::vector<Detection> _getDetections(std::string image_path);