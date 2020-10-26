#include <Arduino.h>

#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "134K1A5E-siqFcnMZucBbddzFvv3L5IC"; //f411reesp

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MiNE_1";
char pass[] = "abcd1234";

// // Hardware Serial on Mega, Leonardo, Micro...
// #define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 8); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // process received value
  if (pinValue == 1)
  {
    digitalWrite(D7, HIGH);
  }
  else
  {
    digitalWrite(D7, LOW);
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D7,OUTPUT);
  delay(10);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass, "192.168.1.104", 8080);
}

void loop()
{
  Blynk.run();
}