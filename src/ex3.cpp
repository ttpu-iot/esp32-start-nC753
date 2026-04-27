#include "Arduino.h"

#define RED_LED_PIN 26
#define SENSOR 33

int lightvalue = 0;

void setup() {
    Serial.begin(115200);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(SENSOR, INPUT);
}

void loop() {
    lightvalue = analogRead(SENSOR);
    Serial.print("Light value = ");
    Serial.print(lightvalue);
    delay(500);
}