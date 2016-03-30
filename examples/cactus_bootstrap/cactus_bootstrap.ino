/*
 * This code runs on the arduino part of the cactus board
 * It runs a bootloader at startup to allow flashing the esp8266
 * module without reprograming the arduino each time.
 * the esp8266 module is connected to Serial1, Serial is the USB 
 * virtual serial port of the arduino
 * 
 */

#include "cactusBootloader.h"

#define BAUD_RATE 9600

String tmp; 
unsigned long counter = 0;
const int ESP8266_ENABLE_PIN = 13;


void setup() {
  // bootloader code
  unsigned long timeout = 5000;
  unsigned long baud_rate = 115000;
  cactusBootloader cb(baud_rate);
  cb.run(timeout);

  // sketch code
  Serial.begin(BAUD_RATE);
  Serial1.begin(BAUD_RATE);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("Hello Cactus Micro!");
  
  // Enable esp8266
  pinMode(ESP8266_ENABLE_PIN, OUTPUT);
  digitalWrite(ESP8266_ENABLE_PIN, HIGH);

}

void loop() {

// receive from esp8266
  while (Serial1.available() > 0)  {
    tmp += char(Serial1.read());
    delay(2);
  }

  if(tmp.length() > 0) {
    Serial.println(tmp);
    tmp = "";
  }
}



