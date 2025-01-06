# Joystick-Controlled-Eyes-with-OLED-Display
Description

This Arduino project uses a joystick to control the movement of pupils on an OLED screen. The joystick allows you to move the pupils within a predefined range, and when the joystick's button is pressed, the eyes "blink" by displaying closed eyelids.

Features

Interactive Pupils: Move the pupils based on joystick input.

Blink Mechanism: Press the joystick button to simulate eye closure.

Simple and Compact Design: Uses an OLED display and a joystick for an engaging output.

Components

Arduino Board (e.g., Arduino Uno)

Joystick Module

X-axis (analog output)

Y-axis (analog output)

Button (digital output)

OLED Display

SSD1306-based, I2C connection

Connecting wires and breadboard

Circuit Connections

Joystick:

X-axis: A0 (analog pin)

Y-axis: A1 (analog pin)

Button: Digital pin 2 (configured with INPUT_PULLUP)

OLED:

SDA: A4 (on Arduino Uno)

SCL: A5 (on Arduino Uno)

VCC: 3.3V or 5V

GND: GND

Installation

Connect the components as per the circuit diagram above.

Install the Adafruit GFX and Adafruit SSD1306 libraries in your Arduino IDE.

Go to Tools > Manage Libraries and search for these libraries.

Upload the provided Arduino code to your board.

Usage

Power the Arduino board.

Use the joystick to move the pupils on the OLED screen:

Push the joystick left/right to move the pupils horizontally.

Push the joystick up/down to move the pupils vertically.

Press the joystick button to make the eyes "blink" (draw eyelids).

Code

The full Arduino code is included in this repository under joystick_eye_control.ino. It uses the following key functions:

drawEye: Draws the eyes and pupils based on joystick input.

drawEyelids: Simulates closed eyes when the joystick button is pressed.

map: Maps joystick analog values to screen coordinates.

Demo



Dependencies

Arduino IDE 1.8 or higher

Adafruit GFX Library

Adafruit SSD1306 Library

License

This project is open-source and available under the MIT License.

