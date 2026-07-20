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

  // IF SENSOR SEES LIGHT (Blinker flashed ON)
  if (sensorState == LOW) {
    if (!isFlashing) {
      isFlashing = true;
      return LM393Enum::ON;
      firstFlashTime = now; // Start 15-second timer on first flash
    }
    lastFlashTime = now; // Remember the exact time we last saw a flash
  }

  // IF NO FLASH SEEN FOR > 1.5 SECONDS (Rider turned off signal)
  if (isFlashing && (now - lastFlashTime > BLINK_GAP_TIME)) {
    isFlashing = false;
    return LM393Enum::OFF;
  }

  // IF FLASHING HAS CONTINUED FOR > 15 SECONDS
  if (isFlashing && (now - firstFlashTime >= FLASH_TIMEOUT)) {
    return LM393Enum::ON_TOO_LONG;
  }

  delay(20); // small pause to support processing
}


