# EchoLock
Smart ultrasonic distance measurement system using Arduino and HC-SR04.


EchoLock is an Arduino-based ultrasonic distance measurement system that uses the HC-SR04 sensor and an I2C LCD display.

## Features

* Measures object distance using ultrasonic waves
* Takes 10 readings and calculates the average distance
* Displays measurements in centimeters and inches
* One-button measurement system
* Reset button for new measurements
* LCD-based user interface

## Components Used

* Arduino Uno/Nano
* HC-SR04 Ultrasonic Sensor
* 16x2 I2C LCD Display
* Push Buttons
* Breadboard and Jumper Wires

## Working

1. Place the target object.
2. Press the Measure button.
3. EchoLock captures 10 distance readings.
4. The readings are averaged for better accuracy.
5. The final distance is displayed on the LCD.
6. Press Reset to start a new measurement.

## Pin Connections

| Component      | Arduino Pin |
| -------------- | ----------- |
| HC-SR04 Trig   | D9          |
| HC-SR04 Echo   | D10         |
| Measure Button | D2          |
| Reset Button   | D3          |
| LCD SDA        | A4          |
| LCD SCL        | A5          |

## Future Improvements

* Data logging
* OLED display support
* Bluetooth connectivity
* Object detection alerts

## Author

Srikar
