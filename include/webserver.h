////here is everything webserver related

#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

// SSID & Password
const char *ssid = "Quiz am Brend - PDF Download"; //SSID of the ap
const char *password = NULL;            //password of the ap

// IP configuration
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void setupWebserver(){
    // Create SoftAP
    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(local_ip, gateway, subnet);

    if(!SPIFFS.begin()){ //start acces to the 4MB storrage on the ESP
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }

    //configure the webserver to display the PDF at the web-root
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/brend_quiz.pdf", "application/pdf");
    });
    // Start server
    server.begin();
}