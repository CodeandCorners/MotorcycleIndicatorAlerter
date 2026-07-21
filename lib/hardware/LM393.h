#pragma once
#include <Arduino.h>
#include "../models/LM393Enum.h"

class LM393 {
    public:
        explicit LM393(uint8_t pin): pin(pin){};

        void connect();
        
        LM393Enum reading();
    private:
        uint8_t pin;
        int read();
        bool isFlashing = false;
        const unsigned long FLASH_TIMEOUT = 15000; // 15s limit
        const unsigned long BLINK_GAP_TIME = 1500;  // 1.5s max pause between blinks

        unsigned long firstFlashTime = 0;
        unsigned long lastFlashTime = 0; 
};

