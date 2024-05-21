# Weart Low-Level C++ SDK

The Weart Low-Level C++ SDK  allows to connect to the Weart middleware and perform various actions with the TouchDIVER devices:
* Start and Stop the middleware operations
* Calibrate the device
* Receive tracking data from the devices
* Receive raw data from the thimble's motion sensors 
* Receive analog raw data from the thimble's senosrs
* Send haptic effects to the devices

## Installation

### General
Copy the source files (.cpp and .h) into your project folder and add them to your project.

On Visual Studio:
* Right-Click on your project
* Click "Add" -> "Existing Item..."
* Select all the sdk source files and click "Add"

### AMI-IIT
1. Run the Terminal as an Administrator
2. Clone the repo: https://github.com/ami-iit/WEART-SDK-Cpp.git TODO: Put speicific commit!!!!
3. `cd WEART-SDK-Cpp`
4. `mkdir build`
5. `cd build`
6. `cmake -G"Visual Studio 17 2022" ..`
7. `cmake --build . --target INSTALL --config Release`
8. Notice that the files are going to be installed to `C:\Program Files (x86)\YOUR_PROJECT_NAME\bin`
    - If you want to change `CMAKE_INSTALL_PREFIX`, run `ccmake .`
    - In our case: `C:\Users\USER_NAME\robotology-superbuild\build\install`
9. To run the application developed using the WeartGloveLibRawData, please remember to set the environmental variable `%PATH%` to the directory containing the `.dll` files. 

## Documentation and references
For the documentation, go [here](https://weart.it/developer-guide/)

## Example Project
An example source code application is available [here](https://github.com/WEARTHaptics/WEART-SDK-Cpp-Example).

## Copyright

Copyright &copy; 2024 Weart S.r.l.  
Copyright &copy; 2024 Fondazione Istituto Italiano di Tecnologia