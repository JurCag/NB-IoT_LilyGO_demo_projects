#include <Arduino.h>

// Set serial for debug console (to the Serial Monitor, speed 115200)
#define SerialMon Serial

// Set LED_BUILTIN if it is not defined by Arduino framework
#ifndef LED_BUILTIN
    // #define LED_BUILTIN 4
#endif

#define PIN12       12

void setup()
{
  // initialize LED digital pin as an output.
  // pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN12, INPUT);
}
int waitTime = 1000;

int cnt;


void loop()
{
  cnt ++;
  if (cnt > 40)
  cnt = 10;
  // // turn the LED on (HIGH is the voltage level)
  // digitalWrite(LED_BUILTIN, HIGH);
  // // wait for a second
  // delay(waitTime);
  // // turn the LED off by making the voltage LOW
  // digitalWrite(LED_BUILTIN, LOW);
  //  // wait for a second
  // delay(waitTime);
}
