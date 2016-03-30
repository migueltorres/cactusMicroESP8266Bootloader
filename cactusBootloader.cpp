#include "cactusBootloader.h"


cactusBootloader::cactusBootloader(unsigned long baudRate) {

  program_pin = 12;
  enable_pin = 13;
  watchdog = 0;
  interval = 0;
  previousMillis = 0; 
  this->baudRate = baudRate;

}
  
void cactusBootloader::run(unsigned long timeout) {
  // use a watchdog counter to finish 
  watchdog_timeout = timeout;
  Serial1.begin(baudRate);
  Serial.begin(baudRate);
  pinMode(enable_pin, OUTPUT);
  pinMode(program_pin, OUTPUT);
  digitalWrite(program_pin, LOW);
  digitalWrite(enable_pin,HIGH);

  while(!Serial);

  Serial.println("ESP8266 programmer ready.");
  previousMillis = millis();
  while (watchdog < watchdog_timeout) {
    unsigned long currentMillis = millis();
    interval = currentMillis - previousMillis;
    previousMillis = currentMillis;
    watchdog += interval;
    // pass data from ESP to host, if any
    while(Serial1.available())
    {
      Serial.write((uint8_t)Serial1.read());
    }
  
    // pass data from host to ESP, if any
    if(Serial.available())
    {
      watchdog = 0;
      while(Serial.available())
      {
        Serial1.write((uint8_t)Serial.read());
      }
    }
  }
  // end of bootloader, clean up resources
  digitalWrite(enable_pin, LOW);
  digitalWrite(program_pin, HIGH);
  Serial.end();
  Serial1.end();
}

