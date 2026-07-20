#include "MAX7219.h"

void MAX7219::connect() {
    delay(1000);
    mx.begin();
    Serial.println("MAX7219 CONNECTED");
} 

void MAX7219::turnOffAll() {
    mx.clear();
}

void MAX7219::setMaxbrightness() {
    mx.control(MD_MAX72XX::INTENSITY, intensitybrightest);
}

void MAX7219::setLeftImage(){};
void MAX7219::setRightImage(){};
void MAX7219::setBothImage(){};
