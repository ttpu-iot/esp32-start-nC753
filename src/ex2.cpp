


#include "Arduino.h"

#define GREEN_LED_PIN 27
#define BUTTON_PIN 25

bool greenState = false;
bool ledState = HIGH; 

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
    bool currentButtonState = digitalRead(BUTTON_PIN);
    
    if (buttonState == LOW && lastButtonState == HIGH) {
        greenState = !greenState;
        digitalWrite(GREEN_LED_PIN, greenState ? HIGH : LOW);
        
        Serial.println(greenState ? "GREEN=1" : "GREEN=0");
    }

    delay(1000); // Wait for 1000 ms
}
