#include "SpeedService.h"
void SpeedService::determineSpeed(){
    float currentSpeed = neo.getCurrentspeedInKMh();
    Serial.print("SpeedService current speed ");
    Serial.println(" KMH");

    unsigned long currentMillis = millis();
    bool isAcceleratingOrCruising = (currentSpeed >= lastSpeed - 0.8f);
    
    if (currentSpeed > 10.0f && isAcceleratingOrCruising) {
        if (speedStartTime == 0) {
            speedStartTime = currentMillis; 
        }

        lastSpeed = currentSpeed;

        if (currentMillis - speedStartTime >= 15000) {
            speedEnum = SpeedEnum::EVIDENCE_OF_DRIVING_NOT_STOPPING;
        } else {
            speedEnum = SpeedEnum::UNCONFIRMED;
        }
    } else {
        speedStartTime = 0;
        lastSpeed = currentSpeed;
        speedEnum = SpeedEnum::UNCONFIRMED;
    }
}