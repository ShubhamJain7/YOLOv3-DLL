#pragma once
#include "framework.h"
#include "internal.h"
#include <string>

#ifdef YOLOV3DLL_EXPORTS
#define YOLOV3LIBRARY_API __declspec(dllexport)
#else
#define YOLOV3LIBRARY_API __declspec(dllimport)
#endif

extern "C" YOLOV3LIBRARY_API int doDetections(IN std::string image_path);
extern "C" YOLOV3LIBRARY_API int getDetections(OUT Detection* results_list, size_t size);