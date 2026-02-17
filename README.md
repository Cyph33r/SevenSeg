# SevenSeg

An easy-to-use Arduino library for controlling single or multi-digit seven-segment displays. Supports both common anode and common cathode configurations with extensive character support.

## Features

- ✅ Support for up to 5-digit seven-segment displays
- ✅ Common anode and common cathode compatibility
- ✅ Display numbers (0-9), letters (A-Z, both upper and lowercase), and special characters (-, _, =, :)
- ✅ Built-in character validation and formatting
- ✅ Simple API with customizable display duration
- ✅ Colon support for time display (HH:MM:SS format)

## Installation

1. Download the library as a ZIP file
2. In Arduino IDE, go to Sketch → Include Library → Add .ZIP Library
3. Select the downloaded ZIP file
4. Restart Arduino IDE

## Usage

```cpp
#include <SevenSeg.h>

// Define digit pins (MSD first)
byte digits[5] = {2, 3, 4, 5, 6};

// Define segment pins (a, b, c, d, e, f, g, dp)
byte segments[8] = {7, 8, 9, 10, 11, 12, 13, A0};

// Create display object (true for common anode, false for common cathode)
SevenSeg screen(digits, segments, true);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Display text for 2500ms
  screen.show("Hello", 2500);
  delay(100);
  
  // Display sensor reading with label
  int reading = analogRead(A5);
  screen.show("R:" + String(reading), 2500);
}
