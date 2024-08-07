#include "WiFiHandler.h"
#include <WebServer.h>
#include <WiFi.h>

// Wi-Fi credentials
const char* ssid = "ESP32_Quadcopter";
const char* password = "12345678";

// Network settings
IPAddress local_IP(192, 168, 1, 100);  // Static IP address
IPAddress gateway(192, 168, 1, 1);     // Gateway address (commonly the router IP)
IPAddress subnet(255, 255, 255, 0);    // Subnet mask

//TUNE THESE PID VALUES FOR FLIGHT
float PRateRoll = 0.75; //For outdoor flights, keep this gain to 0.75 and for indoor flights keep the gain to be 0.6
float IRateRoll = 0.012;
float DRateRoll = 0.0085;

float PRatePitch = PRateRoll;
float IRatePitch = IRateRoll;
float DRatePitch = DRateRoll;

float PRateYaw = 4.2;
float IRateYaw = 2.8;
float DRateYaw = 0;

// Create an instance of the web server on port 80
WebServer server(80);

void setupWiFi() {
    Serial.begin(115200);

    Serial.println("Configuring WiFi Access Point (AP)");
    if (!WiFi.softAPConfig(local_IP, gateway, subnet)) {
        Serial.println("AP Config Failed");
    }
    Serial.println(" ");
    Serial.print("AP Launch Status: ");
    Serial.println(WiFi.softAP(ssid, password) ? "Ready" : "Failed");

    Serial.println(" ");
    Serial.print("Connect to IP Address: ");
    Serial.println(WiFi.softAPIP());

    setupWebServer();
}

//  accessed continuously by main loop
void checkWiFiConnection() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi disconnected, reconnecting...");
        setupWiFi();
    } else {
        Serial.println("WiFi connected");
    }
}

void setupWebServer() {
    // Define web server routes
    server.on("/", handleRoot);
    server.on("/update", handleUpdate);
    server.begin();
    Serial.println("Web server started");
}

void handleRoot() {
    // Serve a simple web page for updating PID values
    String html = "<html><body>"
                  "<h1>Update PID Values</h1>"
                  "<form action='/update' method='POST'>"
                  "PRateRoll: <input type='text' name='PRateRoll'><br>"
                  "IRateRoll: <input type='text' name='IRateRoll'><br>"
                  "DRateRoll: <input type='text' name='DRateRoll'><br>"
                  "PRatePitch: <input type='text' name='PRatePitch'><br>"
                  "IRatePitch: <input type='text' name='IRatePitch'><br>"
                  "DRatePitch: <input type='text' name='DRatePitch'><br>"
                  "PRateYaw: <input type='text' name='PRateYaw'><br>"
                  "IRateYaw: <input type='text' name='IRateYaw'><br>"
                  "DRateYaw: <input type='text' name='DRateYaw'><br>"
                  "<input type='submit' value='Update'>"
                  "</form></body></html>";
    server.send(200, "text/html", html);
}

void handleUpdate() {
    // Extract values from POST request and update PID variables
    if (server.hasArg("PRateRoll")) PRateRoll = server.arg("PRateRoll").toFloat();
    if (server.hasArg("IRateRoll")) IRateRoll = server.arg("IRateRoll").toFloat();
    if (server.hasArg("DRateRoll")) DRateRoll = server.arg("DRateRoll").toFloat();
    if (server.hasArg("PRatePitch")) PRatePitch = server.arg("PRatePitch").toFloat();
    if (server.hasArg("IRatePitch")) IRatePitch = server.arg("IRatePitch").toFloat();
    if (server.hasArg("DRatePitch")) DRatePitch = server.arg("DRatePitch").toFloat();
    if (server.hasArg("PRateYaw")) PRateYaw = server.arg("PRateYaw").toFloat();
    if (server.hasArg("IRateYaw")) IRateYaw = server.arg("IRateYaw").toFloat();
    if (server.hasArg("DRateYaw")) DRateYaw = server.arg("DRateYaw").toFloat();

    server.send(200, "text/html", "<html><body><h1>PID values updated</h1></body></html>");
}