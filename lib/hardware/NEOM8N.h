#pragma once
#include <TinyGPS++.h>

class NEOM8N {
    public:
        explicit NEOM8N(HardwareSerial& gpsSerial, TinyGPSPlus& gps): gpsSerial(gpsSerial), gps(gps) {};
        void connect();
        void encode();
        bool ping();
        bool getStillConnected(){return stillConnected;}
        float getCurrentspeedInKMh();

    private:
        HardwareSerial& gpsSerial;
        TinyGPSPlus& gps;
        int GPS_RX_PIN = 16;
        int GPS_TX_PIN = 17;
        int GPS_BAUD = 9600;
        bool stillConnected;

};