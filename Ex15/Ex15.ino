#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
const char* ssid = "Simon";
const char* pass = "Suiiiiiiii!";
WiFiClient client;
unsigned long channelID = 2397519;        //your TS channal
const char* APIKey = "08JET6OE2DENHIWL";  //your TS API
const char* server = "api.thingspeak.com";
const int postDelay = 5 * 1000;  //post data every 20

void handleLED() {  // If a POST request is made to URI /LED
  //digitalWrite(led, !digitalRead(led));
}

  void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, pass);
  }
  float data;

  void loop() {
    //data = 42.0;
    data = WiFi.RSSI();
    Serial.print("RSSI: ");
    Serial.println(data);
    ThingSpeak.begin(client);
    client.connect(server, 80);    //connect(URL, Port)
    ThingSpeak.setField(1, data);  //set data on the X

    ThingSpeak.writeFields(channelID, APIKey);  //post everything to TS
    client.stop();
    delay(postDelay);  //wait and then post
  }
