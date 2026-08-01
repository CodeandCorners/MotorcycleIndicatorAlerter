#pragma once

#include <MD_MAX72xx.h>
#include <Arduino.h>

class MAX7219 {
    public:
        void connect();
        void setMaxbrightness();
        void turnOffAll();

        void setLeftImage();
        void setRightImage();
        void setOnTooLong();
        void setBothImage();
        void setQuestionMark();

    private:
const byte LEFT_ARROW[8] = {
        B00011000,
        B00001100,
        B11111110,
        B11111111,
        B11111110,
        B00001100,
        B00011000,
        B00000000
    };
    const byte RIGHT_ARROW[8] = {
        B00011000,
        B00110000,
        B01111111,
        B11111111,
        B01111111,
        B00110000,
        B00011000,
        B00000000
    };

    const byte X_BITMAP[8] = {
        B10000001,
        B01000010,
        B00100100,
        B00011000,
        B00011000,
        B00100100,
        B01000010,
        B10000001
    };
    const byte CENTER_FILLED[8] = {
        B00000000,
        B01111110,
        B01111110,
        B01111110,
        B01111110,
        B01111110,
        B01111110,
        B00000000
    };
// sideways for fitment
   const byte QUESTION_MARK[8] = {
    B00000000,
    B00000000,
    B00000000,
    B11110000,
    B00001000,
    B00001100,
    B01000010,
    B00111100
};

    void drawBitmap(const byte bitmap[8])
{
    for (uint8_t row = 0; row < 8; row++)
    {
        mx.setRow(0, row, bitmap[row]);
    }
}
        const int8_t DATA_PIN = 27;
        const int8_t CLK_PIN = 25;
        const int8_t CS_PIN = 26;
        const int8_t intensityDimmest = 0;
        const int8_t intensitybrightest = 15;
        const MD_MAX72XX::moduleType_t HARDWARE_TYPE = MD_MAX72XX::FC16_HW;
        const uint8_t MAX_DEVICES = 1;

        MD_MAX72XX mx{HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES};

};