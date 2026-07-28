#include <Arduino.h>
#include "../lib/hardware/LM393.h"
#include "../lib/hardware/MAX7219.h"
#include "../lib/hardware/NEOM8N.h"
#include "../lib/orchestrators/LightAndImageOrchestrator.h"
#include "../lib/services/LightDirectionService.h"
#include "../lib/services/SpeedService.h"


uint8_t leftInputPin = 4;
uint8_t rightInputPin = 5;

LM393 lm393Left(leftInputPin);
LM393 lm393Right(rightInputPin);
HardwareSerial gpsSerial(2);
TinyGPSPlus gps;
NEOM8N neo8(gpsSerial, gps);
SpeedService speedService(neo8);

MAX7219 max7219;

LightDirectionService lds(lm393Left, lm393Right);
LightAndImageOrchestrator laio(lds, max7219, speedService);
const long GPSPingDelay = 1000;
uint64_t lastGPSCheck = 0;

uint64_t ensureGPS(uint64_t lastCheck) {
 uint64_t now = millis();
 if(now - lastCheck >= GPSPingDelay) {
   neo8.ping();
  return now;
 } else {
  return lastCheck;
 }
}
void setup() {
  delay(2000);
  Serial.begin(115200);
  max7219.connect();
  max7219.setMaxbrightness();
  lm393Left.connect();
  lm393Right.connect();
  neo8.connect();
  delay(1000);
}

void loop() {
  lastGPSCheck = ensureGPS(lastGPSCheck);
  speedService.determineSpeed();
  if(neo8.getStillConnected()) {
  laio.run(); 
  } else {
    Serial.println("GPS Not connected, no orchestrator run");
  }
}
