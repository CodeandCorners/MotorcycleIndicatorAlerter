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

void MAX7219::setLeftImage(){
    drawBitmap(LEFT_ARROW);
};

void MAX7219::setRightImage(){
    drawBitmap(RIGHT_ARROW);
};

void MAX7219::setOnTooLong(){
    drawBitmap(X_BITMAP);
};

void MAX7219::setBothImage(){
    drawBitmap(CENTER_FILLED);
};

void MAX7219::setQuestionMark(){
    drawBitmap(QUESTION_MARK);
};