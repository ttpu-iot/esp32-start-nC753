#include "Arduino.h"

#define GREEN_LED_PIN 27
#define BLUE_LED_PIN 14
#define RED_LED_PIN 26
#define YELLOW_LED_PIN 12
#define SENSOR 33

int lightvalue = 0;

void setup() {
    Serial.begin(115200);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(SENSOR, INPUT);
}

void loop() {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);

    lightvalue = analogRead(SENSOR);
    if (lightvalue <= 1023) {
        digitalWrite(BLUE_LED_PIN, HIGH);
        Serial.print("Blue Led on ");
    }
    else if (lightvalue > 1023 && lightvalue <= 2047) {
        digitalWrite(GREEN_LED_PIN, HIGH);
        Serial.print("Green Led on ");
    }
    else if (lightvalue > 2047 && lightvalue <= 3071) {
        digitalWrite(RED_LED_PIN, HIGH);
        Serial.print("Red Led on ");
        Serial.println(lightvalue);
    }
    else if (lightvalue > 3071 && lightvalue <= 4095) {
        digitalWrite(YELLOW_LED_PIN, HIGH);
        Serial.print("Yellow Led on ");
        Serial.println(lightvalue);
    }

}