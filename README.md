# DIY-Arduino-Quadcopter

Google Docs Documentation: https://docs.google.com/document/d/1w-_Mgveb7NV3Uxb808Nk6pVux4E4SsMkCS6ROmJbJvg/edit?usp=sharing

This project can only be directly opened on PlatformIO (VSCode Extension) and run on the ESP32.
The following is a list of important hardware components used in this project: MPU6050, Flysky RC FS-iA6B Receiver, 4 brushless motors&ESCs, a quadcopter frame

There are certain files in the src folder that depend on each other and require unrelated files to be commented out: 
1) main.cpp
2) pid_tuning.cpp, WiFiHandler.cpp, WiFiHandler.h
3) imu_test.cpp
4) motor_test.cpp
