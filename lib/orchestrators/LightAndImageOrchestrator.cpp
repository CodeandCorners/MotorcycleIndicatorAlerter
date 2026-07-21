#include "LightAndImageOrchestrator.h"

void LightAndImageOrchestrator::run(){
    DirectionEnum direction = lds.calculateDirection();
    max7219.turnOffAll();
    if(direction == DirectionEnum::LEFT_ON) {
        max7219.setLeftImage();
    } else if (direction == DirectionEnum::LEFT_ON_TOO_LONG) {
        //TODO: Exclamation and then left image, flashing, will need delay
        max7219.setLeftImage();
    } else if (direction == DirectionEnum::RIGHT_ON) {
        max7219.setRightImage();
    } else if (direction == DirectionEnum::RIGHT_ON_TOO_LONG) {
        //TODO: Exclamation and then right image, flashing, will need delay
        max7219.setRightImage();
    } else if (direction == DirectionEnum::BOTH_ON || direction == DirectionEnum::BOTH_ON_TOO_LONG) {
        //TODO generic 2 arrows, hazards scenario
    } else {
        // DO nothing
        Serial.println("No output");
    }
    // supports flashing, supports processing compute costs
      delay(DELAY_PER_RUN);
};