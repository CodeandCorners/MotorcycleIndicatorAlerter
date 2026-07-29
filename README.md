# Motorcycle Indicator Alerter
Intended to use the lights of indicators to present lights to the user to indicate indicator status/indicators remaining on.

Setup for ESP32 Dev board

## How to use
- Join up Components
- Clone repo
- Install VSCode, platformIO extension
- Connect board
- "Upload and Monitor"
- Fit light sensors to (front) indicators, tweaking potentiometers
- cover light sensors with something so external light cannot leak in
- ESP32 and matrix fitted to bike
- power on
- Wait for GPS to lock (question mark will no longer appear)

## Hardware
| Component             | Module Pin | ESP32 Pin |
| --------------------- | ---------- | --------- |
| **LM393 LDR (Left)**  | VCC        | 3V3       |
|                       | GND        | GND       |
|                       | DO         | GPIO 4    |
| **LM393 LDR (Right)** | VCC        | 3V3       |
|                       | GND        | GND       |
|                       | DO         | GPIO 5    |
| **MAX7219**           | VCC        | VIN (5V)  |
|                       | GND        | GND       |
|                       | DIN        | GPIO 27   |
|                       | CLK        | GPIO 25   |
|                       | CS         | GPIO 26   |
| **NEO8MN**            | TX         | GPIO RX2   |
|                       | RX         | GPIO TX2   |
|                       | VCC        | VIN (5V)  |
|                       | GND        | GND       |


## Notable config
- Main leftInputPin, rightInputPin - pins for light sensors
- SpeedService thresholdForMovementKMH, how quick before user is classes as "probably moving away from indication zone"
- SpeedService thresholdAmountOfTimeMovementMs - how long the user has been travelling for (not stationary, over speed threshold) before we class them as "probably moving away from indication zone"
- LM393 BLINK_GAP_TIME how long before we assume user has turned off indicators
- LM393 FLASH_TIMEOUT how long before we class the user has left their indicator on for too long


## Light sequences
- X bitmap
⬛⬜⬜⬜⬜⬜⬜⬛
⬜⬛⬜⬜⬜⬜⬛⬜
⬜⬜⬛⬜⬜⬛⬜⬜
⬜⬜⬜⬛⬛⬜⬜⬜
⬜⬜⬜⬛⬛⬜⬜⬜
⬜⬜⬛⬜⬜⬛⬜⬜
⬜⬛⬜⬜⬜⬜⬛⬜
⬛⬜⬜⬜⬜⬜⬜⬛

- centre filled
⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬛⬛⬛⬛⬛⬛⬜
⬜⬛⬛⬛⬛⬛⬛⬜
⬜⬛⬛⬛⬛⬛⬛⬜
⬜⬛⬛⬛⬛⬛⬛⬜
⬜⬛⬛⬛⬛⬛⬛⬜
⬜⬛⬛⬛⬛⬛⬛⬜
⬜⬜⬜⬜⬜⬜⬜⬜

- Left arrow
   ██
  ██
███████
████████
███████
  ██
   ██

- Right arrow
   ██
    ██
███████
████████
███████
    ██
   ██

- Question mark
··████··
·█····█·
·····█··
···██···
···█····
········
···█····
········


## Arduino notes 
- LOW == ON == 0
- HIGH == OFF == 1

## Notes
- No notable bugs, GPS can take a while to lock though, indoors this may be quite a while.
