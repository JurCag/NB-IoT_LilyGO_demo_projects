#include <CayenneMQTTESP32.h>

#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial

#define BLUE_LED  12

// WiFi network info.
char ssid[] = "Go-Fi";
char wifiPassword[] = "Narcisova6";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "b43519e0-1743-11ed-baf6-35fab7fd0ac8";
char password[] = "5c347e544a0aeda1a9933e251d14e75f2beb83b5";
char clientID[] = "91ccc730-17cb-11ed-baf6-35fab7fd0ac8";

float temp = 24.24;
float hum = 50.5;
uint16_t i = 0;

void setup() {
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  pinMode(BLUE_LED, OUTPUT);
  digitalWrite(BLUE_LED, HIGH); // HIGH turns blue led off, inverted polarity

  Serial.begin(115200);
}

void loop() {
  Cayenne.loop();
  
  if (i == 5)
  {
    temp += 2.5;
    hum += 0.2;
    Serial.println(String(temp));
    i = 0;

    if (temp > 100)
    {
      temp = 20;
    }
    if (hum > 90)
    {
      hum = 10;
    }
  }
  i++;


  Cayenne.virtualWrite(1, temp, TYPE_TEMPERATURE, UNIT_CELSIUS);
  Cayenne.virtualWrite(2, hum, TYPE_RELATIVE_HUMIDITY, UNIT_PERCENT);
}

CAYENNE_IN(0)
{
  digitalWrite(BLUE_LED, !getValue.asInt());
}