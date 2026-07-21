#include <Arduino.h>
#include "../lib/hardware/LM393.h"
#include "../lib/hardware/MAX7219.h"
#include "../lib/orchestrators/LightAndImageOrchestrator.h"
#include "../lib/services/LightDirectionService.h"

uint8_t leftInputPin = 4;
uint8_t rightInputPin = 5;

LM393 lm393Left(leftInputPin);
LM393 lm393Right(rightInputPin);

MAX7219 max7219;

LightDirectionService lds(lm393Left, lm393Right);
LightAndImageOrchestrator laio(lds, max7219);


void setup() {
  delay(2000);
  Serial.begin(115200);
  max7219.connect();
  max7219.setMaxbrightness();
  lm393Left.connect();
  lm393Right.connect();
  delay(1000);
}

void loop() {
  laio.run();
}

