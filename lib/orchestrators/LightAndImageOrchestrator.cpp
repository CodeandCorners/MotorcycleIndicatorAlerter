#include "LightAndImageOrchestrator.h"
#include "../models/DirectionEnum.h"
#include "../models/SpeedEnum.h"


void LightAndImageOrchestrator::run() {
    DirectionEnum direction = lds.calculateDirection();
    SpeedEnum speed = ss.getSpeed();
    if(speed == SpeedEnum::EVIDENCE_OF_DRIVING_NOT_STOPPING) {
        movingEvident(direction);
    } else {
        notProvenMoving(direction);
    }
}

void LightAndImageOrchestrator::notProvenMoving(DirectionEnum direction){

    switch (direction) {
        case DirectionEnum::LEFT_ON:
            max7219.setLeftImage();
            break;

        case DirectionEnum::LEFT_ON_TOO_LONG:
              max7219.setLeftImage();
            break;
        case DirectionEnum::RIGHT_ON:
            max7219.setRightImage();
            break;

        case DirectionEnum::RIGHT_ON_TOO_LONG:
           max7219.setRightImage();
            break;

        case DirectionEnum::BOTH_ON:
        case DirectionEnum::BOTH_ON_TOO_LONG:
            max7219.setBothImage();
            break;

        default:
            max7219.turnOffAll();
            break;
    }
}

void LightAndImageOrchestrator::movingEvident(DirectionEnum direction){
    const unsigned long BLINK_INTERVAL_MS = 100;
    bool togglePhase = (millis() / BLINK_INTERVAL_MS) % 2 == 0;

    switch (direction) {
        case DirectionEnum::LEFT_ON:
            max7219.setLeftImage();
            break;

        case DirectionEnum::LEFT_ON_TOO_LONG:
            if (togglePhase) {
                max7219.setLeftImage();
            } else {
                max7219.setOnTooLong();
            }
            break;

        case DirectionEnum::RIGHT_ON:
            max7219.setRightImage();
            break;

        case DirectionEnum::RIGHT_ON_TOO_LONG:
            if (togglePhase) {
                max7219.setRightImage();
            } else {
                max7219.setOnTooLong();
            }
            break;

        case DirectionEnum::BOTH_ON:
        case DirectionEnum::BOTH_ON_TOO_LONG:
            max7219.setBothImage();
            break;

        default:
            max7219.turnOffAll();
            break;
    }
}