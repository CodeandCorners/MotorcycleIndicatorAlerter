#include "LM393.h"
#include "../models/LM393Enum.h"
#include <Arduino.h>

void LM393::connect() {
    pinMode(pin, INPUT);
};

int LM393::read() {
    return digitalRead(pin);
}
LM393Enum LM393::reading() {
    unsigned long now = millis(); // Get current timestamp in milliseconds

  int sensorState = read();
    Serial.print(pin);
  // IF SENSOR SEES LIGHT (Blinker flashed ON)
  if (sensorState == LOW && !isFlashing) {
    isFlashing = true;
    firstFlashTime = now; // Start 15-second timer on first flash
    Serial.println("Set to On from off");
    lastFlashTime = now; // Remember the exact time we last saw a flash
    return LM393Enum::ON;
  } else if(sensorState == LOW) {
         if(now - firstFlashTime >= FLASH_TIMEOUT) {
                 // IF FLASHING HAS CONTINUED FOR > 15 SECONDS
                lastFlashTime = now;
                return LM393Enum::ON_TOO_LONG;
        } else {
                Serial.println("Marked as ON, continues to be on, not hit thresholds");
                lastFlashTime = now; 
                return LM393Enum::ON;
        }
    } else if(sensorState == HIGH) {
        if ((now - lastFlashTime > BLINK_GAP_TIME)) {
            isFlashing = false;
                  Serial.println("Marked as OFF, as been off for > blink threshold");
            return LM393Enum::OFF;
        } else {
            return LM393Enum::ON;
        }
    }
}
