#include "Arduino.h"

#define BLUE_LED 14

void setup() {
    Serial.begin(115200);
    pinMode(BLUE_LED, OUTPUT);
}

void loop() {
    if (Serial.available() == 0) {
        char character = Serial.read();
        if (character == 'B') {
            digitalWrite(BLUE_LED, HIGH);
            Serial.println("Blue=1");
        } else if (character == 'b') {
            digitalWrite(BLUE_LED, LOW);
            Serial.println("Blue=0");
        }
    }

}