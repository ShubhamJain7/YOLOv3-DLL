// YOLOv3Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <YOLOv3-DLL/YOLOv3Lib.h>

int main()
{
    std::string img_path = "C:/Users/dell/source/repos/YOLOv3-DLL/test.jpg";
    int result = doDetections(img_path);

    Detection objects[20];
    int size = getDetections(objects, 20);
    for (int i = 0; i < size; i++)
    {
        Detection d = objects[i];
        std::cout << d.classId << "(" << d.probability << "):";
        std::cout << "[" << d.x << "," << d.y << "," << d.width << "," << d.height << "]" << std::endl;
    }
}