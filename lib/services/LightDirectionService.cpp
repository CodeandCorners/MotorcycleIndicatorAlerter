#include "LightDirectionService.h"
#include "../models/DirectionEnum.h"
#include "../models/LM393Enum.h"
#include <stdexcept>


DirectionEnum LightDirectionService::calculateDirection(){
    LM393Enum left = lm393Left.reading();
    LM393Enum right = lm393Right.reading();
    const bool everythingOff = left == LM393Enum::OFF && right == LM393Enum::OFF;
    const bool everythingOn = (left == LM393Enum::ON || left == LM393Enum::ON_TOO_LONG) && 
        (right == LM393Enum::ON || right == LM393Enum::ON_TOO_LONG);

    if(everythingOff) {
        return DirectionEnum::NOT_ON;
    } else if (everythingOn) {
        return DirectionEnum::BOTH_ON;
    } else if (left == LM393Enum::ON) {
        return DirectionEnum::LEFT_ON;
    } else if (left == LM393Enum::ON_TOO_LONG) {
        return DirectionEnum::LEFT_ON_TOO_LONG;
    } else if(right == LM393Enum::ON) {
        return DirectionEnum::RIGHT_ON;
    } else if(right == LM393Enum::ON_TOO_LONG) {
        return DirectionEnum::RIGHT_ON_TOO_LONG;
    } else {
        throw std::runtime_error("Matching on LM393Enum, MISSED CONDITION");
    }
}