# YOLOv3-DLL

This repository is a part of my [GSoC 2020 project](https://summerofcode.withgoogle.com/projects/#6039693356957696) and the DLL generated is used by the [Object Detection NVDA Add-on](https://github.com/ShubhamJain7/objectDetection-NVDA-Addon).
Object detection is perfromed by the [YOLOv3-Darknet](https://pjreddie.com/darknet/yolo/). 

This repo consists of a Visual Studio Solution that contains 2 projects:
1. __YOLOv3-DLL__: A Microsoft Windows DLL that runs inference on the YOLOv3-Darknet model and returns the labels and locations of detected objects in the input image.
2. __YOLOv3 Console__: A Simple console application that interfaces with the _YOLOv3-DLL_ to perform object detection on a sample input image.

The repository also includes a python client, `client.py` that uses Cython to run a sample object detection process on a test image, much like the _YOLOv3 Console_ project.

## How to Build and Run

1. Clone this repository
2. Create the folders `x86/vc16/Debug` and `x86/vc16/Release` in the `opencv` directory.
3. Download [OpenCV](https://opencv.org/releases/) (version 4.3 was used for this project) and build it by following the steps in this [tutorial](https://hackeradam.com/installing-opencv-4-on-windows-10/). Make sure to select the option to build a 32-bit library in Step 4 of the tutorial.
4. Create `lib` directories in the `Debug` & `Relese` folders and copy the library files for the following modules in the corresponding directories:
    - opencv_core
    - opencv_imgcodecs
    - opencv_imgproc
    - opencv_dnn
(debug versions end with a _d_)
5. Open the __YOLOv3-DLL.sln__ file in Visual Studio.
6. Open the properties menu of the __YOLOv3-DLL__ project and select _C/C++ -> General_. Add `$(SolutionDir)opencv\include` to the _Additional include directories_.
7. In the properties menu, select _Linker -> General_ and add `$(SolutionDir)\x86\vc16\Release\lib` or `$(SolutionDir)\x86\vc16\Debug\lib` (depending on your selected configuration) to _Additional Library Directories_.
8. Again, in the properties menu select _Linker -> Input_ and add the names of the library files to _Additional Dependencies_. (Names of the library files in the directory mentioned in the previous step. Mind the selected configuration here too, Debug libraries end with a _d_).
9. Download the _congif_ and _weights_ file of any model YOLOv3 model from [here](https://pjreddie.com/darknet/yolo/) into the `models` directory. (Make sure the files are named `yolov3.cfg` and `yolov3.weights` only)
10. You can now build the __YOLOv3-DLL__ project by selecting the _Build Solution_ option in the build menu of Visual Studio or just press `ctrl+shift+b`. Depending on the selected build configuration, a Debug or Release directory with the  built DLL will be created in the root directory of the repository.
11. Copy the DLLs for the OpenCV modules mentioned in step 4 to the Release or Debug directory created in the last step.
12. Build and run the __YOLOv3Console__ project to test the model by pressing `ctrl+f5`. Alternatively, you can run `python client.py` (only works with Release builds). Your output should look like:
```
5(0.999168):[105,79,954,636]
2(0.879537):[-1,461,105,171]
```
The output is of the form `classIndex(confidence):[x,y,width,height]` where:
- `classIndex`: Index of class label in the [coco.names file](https://github.com/pjreddie/darknet/blob/master/data/coco.names)
- `confidence`: How sure the model is about this detection (aka probability)
- `x`: _x_ co-ordinate of top-left corner of object in the image
- `y`: _y_ co-ordinate of top-left corner of object in the image
- `width`: _width_ of object in the image
- `height`: _height_ of object in the image

If you've done everything right, the file structure of this repo should look something like:
```
YOLOv3-DLL
│   .gitignore
│   client.py
│   LICENSE
│   test.jpg
│   YOLOv3-DLL.sln
│
├───Debug
│       opencv_core430d.dll
│       opencv_dnn430d.dll
│       opencv_imgcodecs430d.dll
│       opencv_imgproc430d.dll
│       YOLOv3-DLL.dll
│       YOLOv3-DLL.exp
│       YOLOv3-DLL.ilk
│       YOLOv3-DLL.lib
│       YOLOv3-DLL.pdb
│       YOLOv3Console.exe
│       YOLOv3Console.ilk
│       YOLOv3Console.pdb
│
├───models
│       yolov3.cfg
│       yolov3.weights
│
├───opencv
│   │   LICENSE
│   │   OpenCVConfig-version.cmake
│   │   OpenCVConfig.cmake
│   │   setup_vars_opencv4.cmd
│   │
│   └───x86
│       └───vc16
│           ├───Debug
│           │   └───lib
│           │           opencv_core430d.lib
│           │           opencv_dnn430d.lib
│           │           opencv_imgcodecs430d.lib
│           │           opencv_imgproc430d.lib
│           │
│           └───Release
│               └───lib
│                       opencv_core430.lib
│                       opencv_dnn430.lib
│                       opencv_imgcodecs430.lib
│                       opencv_imgproc430.lib
│
├───Release
│       opencv_core430.dll
│       opencv_dnn430.dll
│       opencv_imgcodecs430.dll
│       opencv_imgproc430.dll
│       YOLOv3-DLL.dll
│       YOLOv3-DLL.exp
│       YOLOv3-DLL.iobj
│       YOLOv3-DLL.ipdb
│       YOLOv3-DLL.lib
│       YOLOv3-DLL.pdb
│       YOLOv3Console.exe
│       YOLOv3Console.iobj
│       YOLOv3Console.ipdb
│       YOLOv3Console.pdb
│
├───YOLOv3-DLL
│   │   dllmain.cpp
│   │   framework.h
│   │   internal.cpp
│   │   internal.h
│   │   pch.cpp
│   │   pch.h
│   │   YOLOv3-DLL.vcxproj
│   │   YOLOv3-DLL.vcxproj.filters
│   │   YOLOv3-DLL.vcxproj.user
│   │   YOLOv3Lib.h
│   │
│   ├───Debug
│   │   │   dllmain.obj
│   │   │   internal.obj
│   │   │   pch.obj
│   │   │   vc142.idb
│   │   │   vc142.pdb
│   │   │   YOLOv3-DLL.log
│   │   │   YOLOv3-DLL.pch
│   │   │
│   │   └───YOLOv3-DLL.tlog
│   │           CL.command.1.tlog
│   │           CL.read.1.tlog
│   │           CL.write.1.tlog
│   │           link.command.1.tlog
│   │           link.read.1.tlog
│   │           link.write.1.tlog
│   │           YOLOv3-DLL.lastbuildstate
│   │           YOLOv3-DLL.write.1u.tlog
│   │
│   ├───Release
│   │   │   dllmain.obj
│   │   │   internal.obj
│   │   │   pch.obj
│   │   │   vc142.pdb
│   │   │   YOLOv3-DLL.log
│   │   │   YOLOv3-DLL.pch
│   │   │
│   │   └───YOLOv3-DLL.tlog
│   │           CL.command.1.tlog
│   │           CL.read.1.tlog
│   │           CL.write.1.tlog
│   │           link.command.1.tlog
│   │           link.read.1.tlog
│   │           link.write.1.tlog
│   │           YOLOv3-DLL.lastbuildstate
│   │           YOLOv3-DLL.write.1u.tlog
│   │
│   └───x64
│       └───Debug
│           │   dllmain.obj
│           │   internal.obj
│           │   pch.obj
│           │   vc142.idb
│           │   vc142.pdb
│           │   YOLOv3-DLL.log
│           │   YOLOv3-DLL.pch
│           │
│           └───YOLOv3-DLL.tlog
│                   CL.command.1.tlog
│                   CL.read.1.tlog
│                   CL.write.1.tlog
│                   link-cvtres.read.1.tlog
│                   link-cvtres.write.1.tlog
│                   link-rc.read.1.tlog
│                   link-rc.write.1.tlog
│                   link.command.1.tlog
│                   link.read.1.tlog
│                   link.write.1.tlog
│                   unsuccessfulbuild
│                   YOLOv3-DLL.lastbuildstate
│
└───YOLOv3Console
    │   YOLOv3Console.cpp
    │   YOLOv3Console.vcxproj
    │   YOLOv3Console.vcxproj.filters
    │   YOLOv3Console.vcxproj.user
    │
    ├───Debug
    │   │   vc142.idb
    │   │   vc142.pdb
    │   │   YOLOv3Console.log
    │   │   YOLOv3Console.obj
    │   │
    │   └───YOLOv3Console.tlog
    │           CL.command.1.tlog
    │           CL.read.1.tlog
    │           CL.write.1.tlog
    │           link.command.1.tlog
    │           link.read.1.tlog
    │           link.write.1.tlog
    │           YOLOv3Console.lastbuildstate
    │
    ├───Release
    │   │   vc142.pdb
    │   │   YOLOv3Console.log
    │   │   YOLOv3Console.obj
    │   │
    │   └───YOLOv3Console.tlog
    │           CL.command.1.tlog
    │           CL.read.1.tlog
    │           CL.write.1.tlog
    │           link.command.1.tlog
    │           link.read.1.tlog
    │           link.write.1.tlog
    │           YOLOv3Console.lastbuildstate
    │           YOLOv3Console.write.1u.tlog
    │
    └───x64
        └───Debug
            │   vc142.idb
            │   vc142.pdb
            │   YOLOv3Console.log
            │
            └───YOLOv3Console.tlog
                    CL.command.1.tlog
                    unsuccessfulbuild
                    YOLOv3Console.lastbuildstate
```
(`opencv\include` and `opencv\etc` not included)