#pragma once
#include <Arduino.h>
#include "../hardware/LM393.h"
#include "../models/DirectionEnum.h"

class LightDirectionService {
    public:
        explicit LightDirectionService(LM393& lm393Left, LM393& lm393Right): lm393Left(lm393Left), lm393Right(lm393Right){}; 

        DirectionEnum calculateDirection();
    private:
    LM393& lm393Left;
    LM393& lm393Right;
};