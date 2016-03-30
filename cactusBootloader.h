
#ifndef CACTUSBOOTLOADER_H
#define CACTUSBOOTLOADER_H

#include "Arduino.h"

class cactusBootloader {
  public:
  cactusBootloader(unsigned long baud_rate);
  void run(unsigned long timeout);  

  private:
  int program_pin;
  int enable_pin;
  unsigned long watchdog;
  unsigned long watchdog_timeout;
  unsigned long interval;
  unsigned long previousMillis;    
  unsigned baudRate;  

};

#endif
