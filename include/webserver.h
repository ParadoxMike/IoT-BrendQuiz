#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

// SSID & Password
const char *ssid = "Quiz am Brend - PDF Download"; // Enter your SSID here
const char *password = NULL;            //Can also be a string with a password

// Use this IP adress after connecting to the AP
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void setupWebserver(){
    // Create SoftAP
    WiFi.hostname("esp_demo"); //This does not work as of yet, let me know if you get it working. Use 192.168.1.1 to connect for now
    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(local_ip, gateway, subnet);

    if(!SPIFFS.begin()){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }

    // Route for root / web page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/brend_quiz_map.pdf", "application/pdf");
    });
    // Start server
    server.begin();
}