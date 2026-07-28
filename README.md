# Motorcycle Indicator Alerter
Intended to use the lights of indicators to present lights to the user to indicate indicator status/indicators remaining on.

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
| **NEO8MN**            | TX         | GPIO 16   |
|                       | RX         | GPIO 17   |
|                       | VCC        | VIN (5V)  |
|                       | GND        | GND       |


## Arduino notes 
- LOW == ON == 0
- HIGH == OFF == 1

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