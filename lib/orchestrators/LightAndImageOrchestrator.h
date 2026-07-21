#pragma once

#include <Arduino.h>
#include "../services/LightDirectionService.h"
#include "../hardware/MAX7219.h"

class LightAndImageOrchestrator {
    public:
        explicit LightAndImageOrchestrator(LightDirectionService& lds, MAX7219& max7219): lds(lds), max7219(max7219){};
        void run();
    private:
        LightDirectionService& lds;
        MAX7219& max7219;
        int DELAY_PER_RUN = 100;
};