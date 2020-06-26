#pragma once
#include "framework.h"
#ifdef YOLOV3DLL_EXPORTS
#define YOLOV3LIBRARY_API __declspec(dllexport)
#else
#define YOLOV3LIBRARY_API __declspec(dllimport)
#endif

struct Detection{
	int classId;
	float probability;
	int x;
	int y;
	int width;
	int height;
};

extern "C" YOLOV3LIBRARY_API int doDetections(IN char* image_path);
extern "C" YOLOV3LIBRARY_API int getDetections(OUT Detection* results_list, size_t size);