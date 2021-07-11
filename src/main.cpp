/*
  Written for ESP8266 Based Wemos D1 mini Pro
  Should work with every ESP8266 based dev board
  Uses:
    - ifttt.com
      - Webhooks https://ifttt.com/maker_webhooks
      - Alexa Actions by mkZense https://ifttt.com/AlexaActionsByMkzense
    - AnotherIFTTTWebhook libary by Neil Webber
      https://github.com/Siytek/AnotherIFTTTWebhook
  

*/


#include <Arduino.h> //Necessary if you are coding in Visual Studio Code with Platformio extension

#include <ESP8266WiFi.h>
#include "AnotherIFTTTWebhook.h"
 
// Set WiFi credentials
#define WIFI_SSID "Ich hab Durst!"
#define WIFI_PASS "This_is_1_Shisha!"
 
#define IFTTT_Key "cIqtA3a-UvF-sAiGqAOslR"
#define IFTTT_Event "button_pressed" // or whatever name you have chosen
 
void setup() {
  Serial.begin(9600); // Serial output only for information, you can also remove all Serial commands
   
  // Connecting to WiFi...
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID,WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
 
  // Connected to WiFi
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
 
  // Send Webook to IFTTT
  send_webhook(IFTTT_Event,IFTTT_Key,"I need Mr.Meeseeks!","25","value 3");
}
void loop(){
  ESP.deepSleep(0);
}