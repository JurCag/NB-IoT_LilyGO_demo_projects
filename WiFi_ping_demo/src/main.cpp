#include <WiFi.h>

const char* ssid = "Go-Fi";
const char* password = "Narcisova6";


void setup() {
  delay(5000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  Serial.print(String(ssid));

  while(WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }

  Serial.println("\nConnected to the Wifi Network.");
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());

}

void loop() {
  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Try to ping me");
    delay(5000);
  }
  else{
    Serial.println("Connection lost");
    delay(5000);
  }
}