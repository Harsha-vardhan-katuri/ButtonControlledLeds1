# LED Blink with Button Control (Arduino)

## Overview
This project demonstrates how to control an LED blinking sequence based on button presses. The project uses an **Arduino microcontroller** and toggles the blinking order of an LED when the button is pressed. The button press is detected using **digital input**, and the LED blinks at different rates based on the selected mode.

## Components
- **Microcontroller:** Arduino Uno/Nano/ESP32 (or similar)
- **LED:** Connected to **Pin 9**
- **Pushbutton:** Connected to **Pin 2** (with an external pull-down resistor)
- **Resistors:** Used for button pull-down and LED current limiting
- **Wires & Breadboard**

## Working of the Project

### Button Press
The pushbutton (connected to Pin 2) is used to toggle the LED blinking sequence:

- **Default Mode:** The LED blinks in the order **10 → 20 → 30** blinks per minute.
- **Reverse Mode:** The LED blinks in the order **30 → 20 → 10** blinks per minute.
- The button press toggles between these two modes.

### LED Blinking Logic
- The blinking speed is calculated based on the number of blinks per minute.
- The LED turns **ON** for half the duration of each blink cycle and then **OFF** for the remaining time.

### Initial Button Check (5 seconds)
- When the Arduino starts, it waits **5 seconds** for a button press.
- If the button is pressed during this period, the **reverse mode** is activated immediately.
- Otherwise, the system starts in **normal mode** by default.

## Circuit Connections
For the hardware setup, follow the circuit diagram. The JSON diagram for Wokwi is attached separately.

### **LED**
- **Anode (+)** → Connect to **Pin 9**
- **Cathode (-)** → Connect to **GND** (via a resistor)

### **Pushbutton**
- **One terminal** → Connect to **Pin 2**
- **Other terminal** → Connect to **GND**
- Use an **external pull-down resistor (10kΩ)**

### **Resistors**
- **220Ω** resistor for the LED to limit current.
- **10kΩ** pull-down resistor for the pushbutton.

## JSON Diagram for Circuit
The Wokwi JSON diagram file is provided separately for visualization.

### **How to View the Diagram**
1. Open the [Wokwi platform](https://wokwi.com/).
2. Create a new project.
3. Copy and paste the attached JSON file into the Wokwi editor.
4. Run the simulation to test the circuit.

## Code Explanation

### **Global Variables**
- `reverseOrder`: Boolean flag to track the LED blink order.
- `LED_PIN`: Defines the LED pin number.
- `BUTTON_PIN`: Defines the button pin number.
- `blinkLED()`: Function to control the LED blinking based on speed.

### **setup() Function**
- Configures the **LED pin as output** and the **button pin as input**.
- Initializes **serial communication** for debugging.
- Waits **5 seconds** to detect an initial button press and set the blink order.

### **loop() Function**
- Reads the **button state** and toggles the `reverseOrder` flag when pressed.
- Calls the `blinkLED()` function based on the **selected mode**.
- Implements a **small delay** to prevent unintended multiple toggles.

## Features
✅ LED Blinks in a predefined sequence.
✅ Button toggles between normal and reverse mode.
✅ Serial monitor logs button state changes.
✅ Initial 5-second delay for detecting startup button press.
✅ Works on multiple Arduino-compatible boards.
