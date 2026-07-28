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
        unsigned long speedStartTime = 0;
        float lastSpeed = 0.0;
        SpeedEnum speedEnum;
        
};