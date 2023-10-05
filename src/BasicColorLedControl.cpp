#include <Arduino.h>
#include "BasicColorLedControl.h"



void BasicColorLedControl::setupLEDs(uint8_t redLEDport, uint8_t greenLEDport, uint8_t blueLEDport, LedType ledType)
{
    redLED_Port = redLEDport;
    greenLED_Port = greenLEDport;
    blueLED_Port = blueLEDport;

    led_Type = ledType;

    pinMode(redLED_Port, OUTPUT);
    pinMode(greenLED_Port, OUTPUT);
    pinMode(blueLED_Port, OUTPUT);
}

void BasicColorLedControl::setLEDColor(bool red, bool green, bool blue)
{
    if (led_Type == COMMON_ANODE) 
    {
        digitalWrite(blueLED_Port, blue ? LOW : HIGH);
        digitalWrite(greenLED_Port, green ? LOW : HIGH);
        digitalWrite(redLED_Port, red ? LOW : HIGH);
    } 
    else 
    {
        digitalWrite(blueLED_Port, blue ? HIGH : LOW);
        digitalWrite(greenLED_Port, green ? HIGH : LOW);
        digitalWrite(redLED_Port, red ? HIGH : LOW);
    }
}

void BasicColorLedControl::unsetLEDs(void)
{
    setLEDColor(false, false, false);
}

void BasicColorLedControl::setRedLED(bool state)
{
    setLEDColor(state, false, false);
}

void BasicColorLedControl::setBlueLED(bool state)
{
    setLEDColor(false, false, state);
}

void BasicColorLedControl::setGreenLED(bool state)
{
    setLEDColor(false, state, false);
}

void BasicColorLedControl::setYellowLED(bool state)
{
    setLEDColor(state, state, false);
}

void BasicColorLedControl::setCyanLED(bool state)
{
    setLEDColor(false, state, state);
}

void BasicColorLedControl::setMagentaLED(bool state)
{
    setLEDColor(state, false, state);
}

void BasicColorLedControl::setWhiteLED(bool state)
{
    setLEDColor(state, state, state);
}

void BasicColorLedControl::TestLEDs(void)
{
    static unsigned long lastChange = 0;
    static uint8_t state = 0;

    if (millis() - lastChange > 1300) 
    {
        lastChange = millis();
        unsetLEDs();

        switch (state)
        {
            case 0: setRedLED(true); break;
            case 1: setGreenLED(true); break;
            case 2: setBlueLED(true); break;
            case 3: setYellowLED(true); break;
            case 4: setCyanLED(true); break;
            case 5: setMagentaLED(true); break;
            case 6: setWhiteLED(true); break;
        }

        state = (state + 1) % 7;
    }
}