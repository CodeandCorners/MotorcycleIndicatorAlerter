#include "SpeedService.h"

void SpeedService::determineSpeed()
{
    float currentSpeed = neo.getCurrentspeedInKMh();

    Serial.print("SpeedService current speed ");
    Serial.print(currentSpeed);
    Serial.println(" KMH");

    unsigned long currentMillis = millis();

    if (currentSpeed > thresholdForMovementKMH)
    {
        if (speedStartTime == 0)
        {
            speedStartTime = currentMillis;
            Serial.println("Movement timer started");
        }

        if (currentMillis - speedStartTime >= thresholdAmountOfTimeMovementMs)
        {
            speedEnum = SpeedEnum::EVIDENCE_OF_DRIVING_NOT_STOPPING;
            Serial.println("Driving confirmed");
        }
        else
        {
            speedEnum = SpeedEnum::UNCONFIRMED;
        }
    }
    else
    {
        speedStartTime = 0;
        speedEnum = SpeedEnum::UNCONFIRMED;
    }
}