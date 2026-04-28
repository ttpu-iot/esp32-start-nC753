#include "Arduino.h"
#define Yellow_LED 12
#define Sensor 33
#define Button 25

int lastButtonState = LOW;
int buttonState = 0;
int lastSensorState = LOW;
int sensorValue = 0;

void setup() {
    Serial.begin(115200);
    pinMode(Yellow_LED, OUTPUT);
    pinMode(Sensor, INPUT);
    pinMode(Button, INPUT);
}

void loop() {
    buttonState = digitalRead(Button);
    if (buttonState == HIGH && lastButtonState == LOW) {
        sensorValue = analogRead(Sensor);
        Serial.print("Snapshot= ");
        Serial.println(sensorValue);
        digitalWrite(Yellow_LED, HIGH);
     }

    lastButtonState = buttonState;
    delay(50);
}
