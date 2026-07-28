#include "SpeedService.h"

void SpeedService::determineSpeed(){
    float currentSpeed = neo.getCurrentspeedInKMh();
    Serial.print("SpeedService current speed ");
    Serial.print(currentSpeed);
    Serial.println(" KMH");

    unsigned long currentMillis = millis();
    // funky stablising magic
    bool isAcceleratingOrCruising = (currentSpeed >= lastSpeed - 0.8f);
    

    if (currentSpeed > thresholdForMovementKMH && isAcceleratingOrCruising) {
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