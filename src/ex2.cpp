#include "Arduino.h"

#define GREEN_LED_PIN 27
#define BUTTON_PIN 25

bool greenState = false;
int lastButtonState = LOW;

/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
    pinMode(GREEN_LED_PIN, OUTPUT); // GREEN LED
    pinMode(BUTTON_PIN, INPUT); // BUTTON
    digitalWrite(GREEN_LED_PIN, LOW);
}


/****************************************************/
void loop(void) 
{
    int buttonState = digitalRead(BUTTON_PIN);
       
    if (buttonState == HIGH && lastButtonState == LOW) {
        greenState = !greenState;
        digitalWrite(GREEN_LED_PIN, greenState ? HIGH : LOW);
        
        Serial.println(greenState ? "GREEN=1" : "GREEN=0");
    }

    lastButtonState = buttonState;
    delay(50); // Wait for 50 ms
}
