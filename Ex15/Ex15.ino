#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "Simon";
const char* pass = "Suiiiiiiii!";
WiFiClient client;
unsigned long channelID = 2397519;        // your TS channel
const char* APIKey = "08JET6OE2DENHIWL";  // your TS API
const char* server = "api.thingspeak.com";
const int postDelay = 5 * 1000;  // post data every 5 seconds

const int ledPin = D2;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  
  pinMode(ledPin, OUTPUT);  // Initialize the LED pin as an output
}

void loop() {
  float data = WiFi.RSSI();  // Get the current RSSI value
  Serial.print("RSSI: ");
  Serial.println(data);

  int ledState;


  if (data > -60) {
    digitalWrite(ledPin, HIGH);
    ledState = 1;
  } else {
    digitalWrite(ledPin, LOW);
    ledState = 0;
  }

  ThingSpeak.begin(client);
  client.connect(server, 80);    //connect(URL, Port)
  ThingSpeak.setField(1, data);  //set RSSI data on field 1
  ThingSpeak.setField(2, ledState);  //set LED state on field 2

  ThingSpeak.writeFields(channelID, APIKey);  //post everything to TS
  client.stop();

  delay(postDelay);  //wait and then post
}
