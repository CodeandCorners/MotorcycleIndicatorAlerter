#pragma once

#include <MD_MAX72xx.h>
#include <SPI.h>
#include <Arduino.h>

class MAX7219 {
    public:
        void connect();
        void setMaxbrightness();
        void turnOffAll();
        void setLeftImage();
        void setRightImage();
        void setBothImage();

    private:
        const int8_t DATA_PIN = 27;
        const int8_t CLK_PIN = 25;
        const int8_t CS_PIN = 26;
        const int8_t intensityDimmest = 0;
        const int8_t intensitybrightest = 15;
        const MD_MAX72XX::moduleType_t HARDWARE_TYPE = MD_MAX72XX::FC16_HW;
        const uint8_t MAX_DEVICES = 1;

        MD_MAX72XX mx{HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES};



};