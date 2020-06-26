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

std::vector<Detection> _getDetections(std::string image_path);