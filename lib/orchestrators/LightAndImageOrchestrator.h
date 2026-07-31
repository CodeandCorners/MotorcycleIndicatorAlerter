#pragma once

#include <Arduino.h>
#include "../services/LightDirectionService.h"
#include "../services/SpeedService.h"
#include "../hardware/MAX7219.h"
#include "../models/DirectionEnum.h"

class LightAndImageOrchestrator {
    public:
        explicit LightAndImageOrchestrator(LightDirectionService& lds, MAX7219& max7219, SpeedService& ss): lds(lds), max7219(max7219), ss(ss){};
        void run();
        void reconnecting();
    private:
        void notProvenMoving(DirectionEnum direction);
        void movingEvident(DirectionEnum direction);
        LightDirectionService& lds;
        SpeedService ss;
        MAX7219& max7219;
        int BLINK_INTERVAL_MS = 100;
};