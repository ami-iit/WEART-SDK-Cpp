# Weart Low-Level C++ SDK

The Weart Low-Level C++ SDK  allows to connect to the Weart middleware and perform various actions with the TouchDIVER devices:
* Start and Stop the middleware operations
* Calibrate the device
* Receive tracking data from the devices
* Receive raw data from the thimble's motion sensors 
* Receive analog raw data from the thimble's senosrs
* Send haptic effects to the devices

## Installation (classic)

Copy the source files (.cpp and .h) into your project folder and add them to your project.

On Visual Studio:
* Right-Click on your project
* Click "Add" -> "Existing Item..."
* Select all the sdk source files and click "Add"

## Installation (Cmake)

It is possible to compile and install the library using [``CMake``](https://cmake.org/),
```
cd WEART-SDK-Cpp
mkdir build
cd build
cmake -G"Visual Studio 17 2022" -DCMAKE_INSTALL_PREFIX=./install ..
cmake --build . --config Release --target INSTALL
```
With these commands, the library will be installed in the folder ``<prefix>/WEART-SDK-Cpp/build/install``.
It is possible to specify a different installation folder replacing ``./install`` after ``-DCMAKE_INSTALL_PREFIX=``.

In order to find the library in a ``CMake`` project you should set the following environment variables
```
set "PATH=%PATH%;<prefix>/WEART-SDK-Cpp/build/install/bin"
set "CMAKE_PREFIX_PATH=%CMAKE_PREFIX_PATH%;<prefix>/WEART-SDK-Cpp/build/install"
```
and in your ``CMakeLists.txt``
```
find_package(WeArtGloveLib REQUIRED)

# ...

target_link_libraries(yourTarget PRIVATE WeArtGloveLib::WeArtGloveLib)
```

## Documentation and references
For the documentation, go [here](https://weart.it/developer-guide/)

## Example Project
An example source code application is available [here](https://github.com/WEARTHaptics/WEART-SDK-Cpp-Example).

## Copyright

Copyright &copy; 2024 Weart S.r.l.
