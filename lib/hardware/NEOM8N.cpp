#include "NEOM8N.h"


void NEOM8N::connect() {
    gpsSerial.begin(GPS_BAUD, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
}

void NEOM8N::encode() {
while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    gps.encode(c);
  }
}

float NEOM8N::getCurrentspeedInKMh(){
    return gps.speed.kmph();
};

bool NEOM8N::ping() {
if (gps.charsProcessed() < 10) {
      Serial.println("Hardware Error: No data from GPS! Check wiring/baud.");
      stillConnected = false;
      return false; 
    } else if (!gps.location.isValid() || gps.satellites.value() < 4) {
        Serial.println("Fix Error: Waiting for satellite lock...");
        stillConnected = false;
        return false;
    } else if (!gps.speed.isValid()) {
        Serial.println("SPEED ERROR, GPS Speed invalid");
        stillConnected = false;
        return false;
    } else if(gps.location.age() > 2000) {
        Serial.println("Data Error: GPS signal lost or frozen!");
        stillConnected = false;
        return false;
    } else {
        stillConnected = true;
        return true;
    }

}