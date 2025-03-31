#include <Arduino.h>

#define LED_PIN 9        
#define BUTTON_PIN 2     

bool reverseOrder = false;

void blinkLED(int blinks) {
    int blinkTime = 60000 / blinks;
    for (int i = 0; i < blinks; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(blinkTime / 2);
        digitalWrite(LED_PIN, LOW);
        delay(blinkTime / 2);
    }
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);  // Use external pull-down resistor
    Serial.begin(9600);

    unsigned long startTime = millis();
    
    Serial.println("Waiting for 5 seconds to check button press...");

    while (millis() - startTime < 5000) {
        Serial.print("Button State: ");
        Serial.println(digitalRead(BUTTON_PIN));  // Print button state
        if (digitalRead(BUTTON_PIN) == HIGH) {  // Button pressed (HIGH due to pull-down)
            reverseOrder = true;
            Serial.println("Button Pressed! Reverse Order Activated.");
            break;
        }
    }
}

void loop() {
    Serial.print("Button State: ");
    Serial.println(digitalRead(BUTTON_PIN));  // Debugging button state

    if (digitalRead(BUTTON_PIN) == HIGH) {  // Button is HIGH when pressed
        delay(50);
        if (digitalRead(BUTTON_PIN) == HIGH) {  
            reverseOrder = !reverseOrder;  
            Serial.println("Button Pressed! Order Toggled.");
            delay(300);
        }
    }

    if (reverseOrder) {
        Serial.println("Blinking in Reverse Order: 30 → 20 → 10");
        blinkLED(30);
        blinkLED(20);
        blinkLED(10);
    } else {
        Serial.println("Blinking in Normal Order: 10 → 20 → 30");
        blinkLED(10);
        blinkLED(20);
        blinkLED(30);
    }
    delay(500);
}
