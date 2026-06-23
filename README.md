# Internship Task 3: Automatic Streetlight Controller 🚗⚡

An Arduino-based smart automation project developed as part of an internship assignment. This system simulates an energy-efficient automatic streetlight that detects ambient light levels using a Light Dependent Resistor (LDR) and automatically toggles the streetlights (LEDs) on or off.

## 🚀 Features

* **Smart Automation:** Automatically turns lights ON at dark (nighttime) and OFF during bright conditions (daytime).
* **Energy Saving:** Minimizes power consumption by ensuring lights only operate when needed.
* **PlatformIO Integrated:** Fully structured for modern embedded development using VS Code and PlatformIO.

---

## 🛠️ Hardware Requirements

To build this circuit, you will need:
* 1 x Arduino UNO (or compatible microcontroller)
* 1 x LDR (Light Dependent Resistor / Photoresistor)
* 1 x High-brightness LED (representing the streetlight)
* 1 x $10k\Omega$ Resistor (used as a voltage divider for the LDR)
* 1 x $220\Omega$ Resistor (current-limiting resistor for the LED)
* 1 x Breadboard
* Jumper wires

### Pin Configuration *(Adjust according to your final circuit setup)*
| Component | Arduino Pin | Type |
| :--- | :--- | :--- |
| **LDR (Photoresistor)** | Analog Pin `A0` | Input |
| **Streetlight LED** | Digital Pin `9` | Output |

---

## 💻 Software & Setup

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/mohdsuhail404/Internship_T3-Automatic_Streetlights.git](https://github.com/mohdsuhail404/Internship_T3-Automatic_Streetlights.git)
   ```
2. Open the project folder in **VS Code** with the **PlatformIO** extension installed.
3. Connect your Arduino board to your computer via USB.
4. PlatformIO will automatically recognize the environment utilizing `platformio.ini`.
5. Build and upload the code directly to your board.

---

## 📝 Code Overview

The system constantly reads the analog voltage value from the LDR network. If the light intensity drops below a predefined threshold, the microcontroller triggers the streetlight LED:

```cpp
#include <Arduino.h>

const int ldrPin = A0;   // LDR sensor connected to Analog pin A0
const int ledPin = 9;    // Streetlight LED connected to Digital pin 9
const int threshold = 400; // Light threshold value (adjust based on ambient environment)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication for monitoring
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Read light levels
  Serial.println(ldrValue);          // Print values to Serial Monitor

  // If ambient light is low (dark), turn on the streetlight
  if (ldrValue < threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(100); // Small delay for stability
}
