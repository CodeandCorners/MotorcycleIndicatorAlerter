#include "LightDirectionService.h"
#include "../models/DirectionEnum.h"
#include "../models/LM393Enum.h"


DirectionEnum LightDirectionService::calculateDirection(){
    LM393Enum left = lm393Left.reading();
    LM393Enum right = lm393Left.reading();
    return DirectionEnum::BOTH;
}