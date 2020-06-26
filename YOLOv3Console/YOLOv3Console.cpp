// YOLOv3Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <YOLOv3-DLL/YOLOv3Lib.h>

int main()
{
    char img_path[] = "wdkhbd";
    int x = doDetections(img_path);

    Detection objects[20];
    int y = getDetections(objects, 20);
    for (int i = 0; i < y; i++)
    {
        Detection d = objects[i];
        std::cout << d.classId << "(" << d.probability << "):";
        std::cout << "[" << d.x << "," << d.y << "," << d.width << "," << d.height << "]" << std::endl;
    }
}