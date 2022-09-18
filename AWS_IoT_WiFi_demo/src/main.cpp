// demo from: https://www.youtube.com/watch?v=idf-gGXvIu4
// #include "secrets.h"

/////////////////////////
#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "LilyGO_SIM7000_WiFi"                         //change this
 
const char WIFI_SSID[] = "Go-Fi";               //change this
const char WIFI_PASSWORD[] = "Narcisova6";           //change this
const char AWS_IOT_ENDPOINT[] = "a3i8xypesjyhwe-ats.iot.eu-central-1.amazonaws.com";       //change this
 
// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
// Device Certificate                                               //change this
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAK0S5GcRGZhwFqqndb3AHenIOd/yMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjA4MTgxMDEw
MjJaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDhzKnIsif3FqXm3XeT
AcqHDywfRcHaJD7TDfOXNvP1BPVWkHDSSTfE1KcnuGuTJxYofWPQQhyBtUeTwPZX
JpZUgwypL1S7UKy6HPHaoL/s3TVOuiVxpXBlGMMrWnzZxstcFhSd+odLepPSPH8o
hgoCmRdgSyw4JNTboATnivf+R6hQuzGFReca7CpRu7XxOEX4yFmp0Vm/ZjT2Hx48
VW0fmR7zBPvACqWXoJUcG0HUI7hdvzMWL5/28lN9SPw8jr8nloDf0uylExjOxRcd
N3211x0zntZV8JW2/L6yMtQuN59T8uB9auhexkAVBoWEAtbnT8kcwDQJ1lQzV1wN
8yGHAgMBAAGjYDBeMB8GA1UdIwQYMBaAFL5bnabdmSSeYBZwAeVUjrPdnpgwMB0G
A1UdDgQWBBQPBbJsqsjXuNpKSV0tqzNH+EzivjAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAWwlMIprezmtDxzvlssNM0+up
81Z2O/Qfv3731/zDGA2G7NsHDwsr3A6Jgnr+azjAN3VGX3g0uaDw0o5FC5mbV8LR
eRqaAsSQBKTLfvuWarYQ0kSQ6r0yym2aB29FvYtTLMg9bp5oCjrMwdpk8Vv3PPx6
V+97Pjh3X2o879JLqq/NBOE0yd1HmfomHpfLxEYtsTmT0ryr2fIF9Zm8Q4hiTWfi
56OhdFy4I/cJ3VpkRYSh8Wc9wPujJexneCcoe23sQEF+TD8gd9Vz+lASyqL+RVVN
IlHrrYfMEK7BK2QQcVTELnWoHvsFA6PKsJYfmHy5rSUkOGMZ/irbADW01goI/Q==
-----END CERTIFICATE-----
 
 
)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEA4cypyLIn9xal5t13kwHKhw8sH0XB2iQ+0w3zlzbz9QT1VpBw
0kk3xNSnJ7hrkycWKH1j0EIcgbVHk8D2VyaWVIMMqS9Uu1Csuhzx2qC/7N01Trol
caVwZRjDK1p82cbLXBYUnfqHS3qT0jx/KIYKApkXYEssOCTU26AE54r3/keoULsx
hUXnGuwqUbu18ThF+MhZqdFZv2Y09h8ePFVtH5ke8wT7wAqll6CVHBtB1CO4Xb8z
Fi+f9vJTfUj8PI6/J5aA39LspRMYzsUXHTd9tdcdM57WVfCVtvy+sjLULjefU/Lg
fWroXsZAFQaFhALW50/JHMA0CdZUM1dcDfMhhwIDAQABAoIBAGCcmjS2DaWKOjfa
oJP02zwIgN9skHIOuhbBzGzx5VX75iFAshU3oLYGKvMy1ExlF/UBGZj9AId7EgIl
OQG3D/FfFSa6iq2O6ijDw7PAvf3R9EIYIXdLyxhmjPNaxzrC9TYUeIPTstnXu7Hj
kqC7IUNVT4wy/duT3sON5ytO6acRIjMl9fn9Tc8xmO4lUHdjw6wQxgYj400c8n+b
QwU8TnSQfd7GRr6s5NswBssF0u5GkZE8JVwMgrWuTRnNaNQ+6mJ4B6lyVczcEzHf
RryGib9S4SQCmipMW4Tr0SDmEjcIuD+XQv1pRSk/q3g8aKRxiAjIKILlwBK3brpY
l7pEHrECgYEA8eMyp01blnqv0DN5OdkkdKq8Fw+ubg9NlyRXw2E+hIeKhSssgNaM
Ax7bSCZHuxbqdMgAwnL20uB3gMOlAuPaFYq3ooQ+pJfYirZX6sxgTC22kU1+2G4R
pszax9NyQDuYBFYg4rfZFO3dP00J9rabsEnBkVQQwiy5RoMrr+D7wSkCgYEA7vkt
Mr/OH/q95fml8edXk3tFdKHqYLD/advEwaPjvZhi3KbXV+RNpBZBZd/KixfPoMx+
/mYE20X2T4Pj+/XvpHXR6aMujJ8Z0PN+TbjuuhCEFxaPK0xovEVQn+xofIeXBWk+
CJMufeufBS62ccfzd3tKcnC9E0vU0SAKWWizsy8CgYEAqRMHB/xBhZhyJdSk6rOG
EOp6mKAEa7fUo03q7o2ddmOLhnPcIp5UtaWu3uqq/vIQpdpa9ZAISPRPc7jNMYz0
llQk8bsAUmo1GRhFscBzmyvkzgHeJQgi3HWag0ygMpe1NWrCh9a8LS3qlWGTElkn
z/xuCdg58o/yXYA4XDKlpqkCgYApLbzRGuYM8qsYXt1ugru/iSVdxKzbfoR0nE8a
QwByYjje5s0Csy+Bz+fzAw4my7KWdcaIVdIOas7XwtVdTHK/9yF1zg2uY5gSPnMM
N4rDeycXx2ZiQqdlkdgjxpv2oXKvlwP+fEYtopVjUjpT/u2AMDmS4MRj99QzOP8v
ivA0NwKBgQDOTm39KdWSEIXbYkLoPLA4pLR9bE2iS45axAuRxXVMbXKTP19GB01O
k9iQlP2fobsSec6p1d9b5sNY05i6VEDgd9NOXSgMEOrl25LZ3OcdxCv0D7FKP18L
jIboUgh2m1DrqXnqaERn8fQSkbkfJ1fzBtfka4Wom4aAuSmhTcnFCA==
-----END RSA PRIVATE KEY-----
 
)KEY";
////////////////////////

#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"
 
// #include "DHT.h"
// #define DHTPIN 14     // Digital pin connected to the DHT sensor
// #define DHTTYPE DHT11   // DHT 11
 
#define AWS_IOT_PUBLISH_TOPIC   "LilyGO_SIM7000_WiFi/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "LilyGO_SIM7000_WiFi/sub"
 
float h;
float t;
 
// DHT dht(DHTPIN, DHTTYPE);
 
WiFiClientSecure net = WiFiClientSecure();
PubSubClient client(net);
 
void connectAWS(void);
void publishMessage(void);
void messageHandler(char* topic, byte* payload, unsigned int length);

void connectAWS()
{
  // WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
  Serial.println("Connecting to Wi-Fi");
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
 
  // Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);
 
  // Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.setServer(AWS_IOT_ENDPOINT, 8883);
 
  // Create a message handler
  client.setCallback(messageHandler);
 
  Serial.println("Connecting to AWS IOT");
 
  while (!client.connect(THINGNAME))
  {
    Serial.print(".");
    delay(100);
  }
 
  if (!client.connected())
  {
    Serial.println("AWS IoT Timeout!");
    return;
  }
 
  // Subscribe to a topic
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
 
  Serial.println("AWS IoT Connected!");
}
 
void publishMessage()
{
  StaticJsonDocument<200> doc;
  doc["humidity"] = h;
  doc["temperature"] = t;
  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer); // print to client
 
  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}
 
void messageHandler(char* topic, byte* payload, unsigned int length)
{
  Serial.print("INCOMING: ");
  Serial.println(topic);
 
  StaticJsonDocument<200> doc;
  deserializeJson(doc, payload);
  const char* message = doc["message2"];
  Serial.println(message);
}
 
void setup()
{
  Serial.begin(115200);
  connectAWS();
  // dht.begin();
}
 
void loop()
{
  h = random(500, 1000) / 10.0;
  t = random(0, 500) / 10.0;
 
 
  if (isnan(h) || isnan(t) )  // Check if any reads failed and exit early (to try again).
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
 
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
 
  publishMessage();
  client.loop();
  delay(3000);
}