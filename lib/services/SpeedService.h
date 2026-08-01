#pragma once
#include "../hardware/NEOM8N.h"
#include "../models/SpeedEnum.h"

class SpeedService {
    public:
        explicit SpeedService(NEOM8N& neo): neo(neo) {};

        void determineSpeed();
        SpeedEnum getSpeed() { return speedEnum;};
    private:
        NEOM8N& neo;
        const float thresholdForMovementMPH = 8.0f;
        const long thresholdAmountOfTimeMovementMs = 15000;
        unsigned long speedStartTime = 0;
        SpeedEnum speedEnum = SpeedEnum::UNCONFIRMED;
        
};