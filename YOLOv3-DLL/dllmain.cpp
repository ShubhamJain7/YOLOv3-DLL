// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "internal.h"
#include "YOLOv3Lib.h"
#include<vector>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

std::vector<Detection> g_detections;

int doDetection(char* configFile, char* weightsFile, char* image_path) {
    g_detections = _getDetections(configFile, weightsFile, image_path);
    return g_detections.size();
}

int getDetections(Detection* results_list, size_t size) {
    size_t i = 0;
    for (; i < g_detections.size() && i<size; i++)
    {
        results_list[i] = g_detections[i];
    }
    return i;
}