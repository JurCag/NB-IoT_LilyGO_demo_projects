
#define TINY_GSM_MODEM_SIM7000
#include <TinyGsmClient.h>

// Set serial for debug console (to the Serial Monitor, speed 115200)
#define SerialMon Serial

// Set serial for AT commands (to the module)
#define SerialAT Serial1

#define MODEM_TX_PIN 26
#define MODEM_RX_PIN 27
#define BLUE_LED_PIN 12

void powerUpModem(void);
void printSerialMonAndAT(char msg[]);
void readAndPrintATReply(void);
void initModem(bool verbose);

void setup() {
    SerialMon.begin(115200);
    delay(2000);

    powerUpModem();

    SerialAT.begin(115200, SERIAL_8N1, MODEM_TX_PIN, MODEM_RX_PIN);

    pinMode(BLUE_LED_PIN, OUTPUT);
    digitalWrite(BLUE_LED_PIN, LOW);
    for (uint8_t i = 0; i < 2; i++) {
        digitalWrite(BLUE_LED_PIN, !digitalRead(BLUE_LED_PIN));
        delay(500);
        digitalWrite(BLUE_LED_PIN, !digitalRead(BLUE_LED_PIN));
        delay(500);
    }
}

void loop() {
    float h = 2.4;
    float t = 24.24;

    initModem(true);

    printSerialMonAndAT((char*) "AT+CPIN?");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CSQ");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CREG?");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CGATT?");
    readAndPrintATReply();
    
    printSerialMonAndAT((char*) "AT+CIPSHUT");
    readAndPrintATReply();
    
    printSerialMonAndAT((char*) "AT+CIPSTATUS");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CIPMUX=0");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CSTT=\"lpwa.vodafone.com\"");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CIPSTATUS");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CIICR");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CIPSTATUS");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CIFSR");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CIPSPRT=0");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CIPSTATUS");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");
    readAndPrintATReply();

    printSerialMonAndAT((char*) "AT+CIPSTATUS");
    readAndPrintATReply();

    // This part sends data to the cloud: https://thingspeak.com/channels/1821667/private_show
    // UNCOMMENT TO SEND DATA with HTTP GET REQUEST
    // printSerialMonAndAT((char*) "AT+CIPSEND");
    // readAndPrintATReply();
    
    // String str="GET https://api.thingspeak.com/update?api_key=MNRPT8HBIFOZG2NR&field1=" + String(t) +"&field2="+String(h);
    // Serial.println(str);
    // SerialAT.println(str);
    // delay(4000);
    // SerialAT.println((char)26); // 'SUB' character
    // delay(5000);//waitting for reply, important! the time is base on the condition of internet 


    while(true) {
        if (SerialAT.available()) {
            SerialMon.write(SerialAT.read());
        }
        if (SerialMon.available()) {
            SerialAT.write(SerialMon.read());
        }
        delay(0);
    }

}


void printSerialMonAndAT(char msg[]) {
    SerialMon.println(msg);
    SerialAT.println(msg);
}

void readAndPrintATReply(void)
{
    while (true) {
        if (SerialAT.available()) {
            String reply = SerialAT.readString();
            SerialMon.print(reply);
            break;
        }
    }
}

void powerUpModem(void) 
{
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);
    delay(1000);
    digitalWrite(4, HIGH);
}

void initModem(bool verbose) 
{
    uint8_t i = 10;
    SerialMon.println(F("Modem initialization: [STARTED]"));
    while (i) {
        if(verbose) {
            SerialMon.println(F("Sending \"AT\" command"));
        }
        SerialAT.println("AT");
        delay(500);
        if (SerialAT.available()) {
            String r = SerialAT.readString();
            if(verbose) {
                SerialMon.print(r);
            }
            if ( r.indexOf("OK") >= 0 ) {
                SerialMon.println(F("Modem initialization: [COMPLETE]"));
                break;
            }
        }
        delay(500);
        i--;
    }
}