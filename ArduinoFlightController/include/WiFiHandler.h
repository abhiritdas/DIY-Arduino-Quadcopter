#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H

#include <WiFi.h>
#include <WebServer.h>

extern WebServer server;

// Shared PID variables (accessed by WiFiHandler.cpp and pid_tuning.cpp)
extern float PRateRoll;
extern float IRateRoll;
extern float DRateRoll;

extern float PRatePitch;
extern float IRatePitch;
extern float DRatePitch;

extern float PRateYaw;
extern float IRateYaw;
extern float DRateYaw;

void setupWiFi();
void checkWiFiConnection();
void setupWebServer();
void handleRoot();
void handleUpdate();

#endif // WIFI_HANDLER_H