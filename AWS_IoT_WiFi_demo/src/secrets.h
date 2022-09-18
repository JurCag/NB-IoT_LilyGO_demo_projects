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
MIIDWjCCAkKgAwIBAgIVAJa5cU1mGKKSMzD0g3EESja6PZkdMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjA4MTgwNzQw
MTJaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDr3t+d7G0yI43EI02d
KbpbiPY/R/1pzsVYlXzayh8g/0Ij6kGCmLXH7HCkmUc2Z8uKTT/NeAGZrX6vhBnJ
2ggMgedsDrY1BaKnYhr6oaXD3fcRbibt4ed7ps1PWvWDCsGEj02rbKRltvuruXsZ
komNuW+WoED+KHASjYeBl9plO0L6TVtGwic20wzQNB5GbpzEWtPh2eB4YvIJ6oCU
IMyWkVkrm8T3aQ3Dyxrd0Lw3pEVI1dQ+zwrJhivo+8Gx+9Lv5YUCPRX2o1ZDvTkk
iSF6JrZm+fV7mFs8s8BDL24KuEdxdVFe6BtuRTh9ZDVgy6S5d3xi/4+KdOydqGBG
MzDDAgMBAAGjYDBeMB8GA1UdIwQYMBaAFNMZt2VrKh30z1S3+9G0k+kbFdR7MB0G
A1UdDgQWBBSiT2c6OL9HD+oKESre4kZBVV9n4jAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEA5SE2QRLalLXQYRauKSpC5H9n
p9xugoLBQyMWdoKETlsU4m/9zu0YLo+crP5/dVeJB9Ny+i0k6aRdnFpeNZaonCLx
DqaAebPtED48b3Un+J8hxR0o7PZSTvf4O91G51Iz5FJagRXoO2ewfXPF/b9zufrX
bfDYMVXdW1zXvOA4vvWzxevP1qUzZSI+yPBpqT3nGosCQj5M3RDvX11OZyDOzI7y
jo7QzGw9A/5Nlwfsykhir3AVGOvHJvvMGNU4gDUHxT7tdihPQtNVavNfIk9R87ln
9XdFjGl7y8+KfzB+Lw0Vnd8TDhdzYuXni/W82wSY7HHA9RJUfGeKyBzQgI54Vw==
-----END CERTIFICATE-----
 
 
)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpgIBAAKCAQEA697fnextMiONxCNNnSm6W4j2P0f9ac7FWJV82sofIP9CI+pB
gpi1x+xwpJlHNmfLik0/zXgBma1+r4QZydoIDIHnbA62NQWip2Ia+qGlw933EW4m
7eHne6bNT1r1gwrBhI9Nq2ykZbb7q7l7GZKJjblvlqBA/ihwEo2HgZfaZTtC+k1b
RsInNtMM0DQeRm6cxFrT4dngeGLyCeqAlCDMlpFZK5vE92kNw8sa3dC8N6RFSNXU
Ps8KyYYr6PvBsfvS7+WFAj0V9qNWQ705JIkheia2Zvn1e5hbPLPAQy9uCrhHcXVR
XugbbkU4fWQ1YMukuXd8Yv+PinTsnahgRjMwwwIDAQABAoIBAQDbL3gzw/HRJvLl
cjz8sDsqNoNGWPqnqWsAH6IvmqYEvs/SmiyYVJqQFyqx+nIPn7KoaZLBuCQcj/nq
1mI0jjTukoTgiGdPrFXzH5qcjzyAYDLo8qigZE39PQsLFCaTyJn+OkDd7Q50Ku+C
K9G1+NN0bP7CRVdAF4nV48kpZ1ieugOWAU4Noanex6z9OFXZCzhJ6Kpsdbp4K6m0
Kd6HIAKw3XAvjjRo7fSb3aExFEuABq0FpGZcXjl8+xvABg0+WvV0aBa46XXBs6/x
7x97S8g1wMLI5Iva6AGgz6dDh5zmiSoCfGxHIq7YXtsq7OaPXtpxUDxVyaddCYFh
QAg2gEoJAoGBAPbmeK40KF63Dm+v48/ogADx4NNOEIyZ3cXS9nZ+z2C9ofCx2JPw
ROrCo5hPOVgsyoKOLcySSYuS/JVwOL1xBsCTS1E4B7A3pyXoIXfTTyCRCco1I2Ml
lEb5CxG92+RMtiFJbyCkEq2JuIt6eraod/pshacJtP5eeTzFfOMen/RvAoGBAPSQ
VgKsg8AU7JyIsdlcFQx2x9m5MXD3cUT7kC5qHjojBru9TJWgZHUEMlrZ/ycfj40V
CPSMe9rHKGlRE7PXqoXOaktCHSgxX9B6Ayoua42EUg6vq3tu5bTQsNlQ+dUnNdAA
glFZ5nDrSf84kwFLJpDyw2CXUIooSwGJf7Ni73rtAoGBANesO37w0NLr1RB69OWI
k0hAAcSTTKGFRtSnk+Ouojg/blZzBF02ZP0tSPqjOdRsS/n/eMJahyQFId7oSKgz
M1LFV+V6rDyiYMAcJiAl1dj82TBpeqABE6Vrpt+4mXy0BeTN4OUCbc5pn2s3cjpc
r3Fxms5vDEum+wC7AnzjI5bBAoGBAMS8F3SvMo0iR/TkQa2I1aXhJ4ON5qfpZcUI
WUP9ObOq2Y/NB/6VuDop1hgfpZHjYacsdLfFCx1DeM6/2gmiRBq/oeJInQvoLBuZ
C1KzZPHCsAAAcQIqg76g4qLu8Qr3L+LThgHLQAU2QaB98kPoIG4Z2/Gnx7JcF3p1
EbVMsTlBAoGBAMb5csH/4Ed4fLiEuv3BWwRreQRB+D7p/Vifa0srAmjz+pq4afJL
fPCIS0cpWc8VuukNn1nejkDnn3xHL+sc2Bo1qPGxXtHHaCvKy4YKPxUwtpKAbO9j
1LXzuvJ1uyMs68k4VCV9us9W0HPQlGXAU4YfXGYtm5e+GQq7xA5C9sxN
-----END RSA PRIVATE KEY-----
 
 
)KEY";