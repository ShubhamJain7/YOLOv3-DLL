#include "pch.h"
#include "internal.h"

std::vector<Detection> _getDetections(std::string image_path) {
	std::vector<Detection> detections;

    Detection d;
    d.classId = 55;
    d.probability = 0.97f;
    d.x = 200;
    d.y = 200;
    d.width = 100;
    d.height = 100;

    detections.push_back(d);

    return detections;
}