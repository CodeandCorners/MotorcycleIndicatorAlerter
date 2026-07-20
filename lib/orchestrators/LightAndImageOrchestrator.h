#pragma once

#include <Arduino.h>
#include "../services/LightDirectionService.h"

class LightAndImageOrchestrator {
    public:
        explicit LightAndImageOrchestrator(LightDirectionService& lds): lds(lds){};
        void run();
    private:
        LightDirectionService& lds;
};