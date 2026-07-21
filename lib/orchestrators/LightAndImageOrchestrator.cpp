#include "LightAndImageOrchestrator.h"

void LightAndImageOrchestrator::run(){
    DirectionEnum direction = lds.calculateDirection();

    max7219.turnOffAll();
    if(direction == DirectionEnum::LEFT_ON) {
        max7219.setLeftImage();
    } else if (direction == DirectionEnum::LEFT_ON_TOO_LONG) {
        //Alert user
        max7219.setLeftImage();
        delay(DELAY_PER_RUN);
        max7219.turnOffAll();
        max7219.setOnTooLong();

    } else if (direction == DirectionEnum::RIGHT_ON) {
        max7219.setRightImage();

    } else if (direction == DirectionEnum::RIGHT_ON_TOO_LONG) {
        //Alert user
        max7219.setRightImage();
        delay(DELAY_PER_RUN);
        max7219.turnOffAll();
        max7219.setOnTooLong();


    } else if (direction == DirectionEnum::BOTH_ON || direction == DirectionEnum::BOTH_ON_TOO_LONG) {
        max7219.setBothImage();

    } else {
        // DO nothing
        Serial.println("No output");
    }
     delay(DELAY_PER_RUN);

};