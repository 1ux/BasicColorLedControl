#include <Arduino.h>
#include "MultiColorLedControl.h"



void MultiColorLedControl::setupLEDs(uint8_t blueLEDport, uint8_t greenLEDport, uint8_t redLEDport)
{
    blueLED_Port = blueLEDport;
    greenLED_Port = greenLEDport;
    redLED_Port = redLEDport;

    pinMode(blueLED_Port, OUTPUT);
    pinMode(greenLED_Port, OUTPUT);
    pinMode(redLED_Port, OUTPUT);
}

void MultiColorLedControl::setLEDColor(bool red, bool green, bool blue)
{
    digitalWrite(blueLED_Port, blue ? HIGH : LOW);
    digitalWrite(greenLED_Port, green ? HIGH : LOW);
    digitalWrite(redLED_Port, red ? HIGH : LOW);
}

void MultiColorLedControl::unsetLEDs(void)
{
    setLEDColor(false, false, false);
}

void MultiColorLedControl::setRedLED(bool state)
{
    setLEDColor(state, false, false);
}

void MultiColorLedControl::setBlueLED(bool state)
{
    setLEDColor(false, false, state);
}

void MultiColorLedControl::setGreenLED(bool state)
{
    setLEDColor(false, state, false);
}

void MultiColorLedControl::setYellowLED(bool state)
{
    setLEDColor(state, state, false);
}

void MultiColorLedControl::setCyanLED(bool state)
{
    setLEDColor(false, state, state);
}

void MultiColorLedControl::setMagentaLED(bool state)
{
    setLEDColor(state, false, state);
}

void MultiColorLedControl::setWhiteLED(bool state)
{
    setLEDColor(state, state, state);
}

void MultiColorLedControl::TestLEDs(void)
{
    static unsigned long lastChange = 0;
    static uint8_t state = 0;

    if (millis() - lastChange > 1300) 
    {
        lastChange = millis();
        unsetLEDs();

        switch (state)
        {
            case 0: setGreenLED(true); break;
            case 1: setRedLED(true); break;
            case 2: setBlueLED(true); break;
            case 3: setYellowLED(true); break;
            case 4: setCyanLED(true); break;
            case 5: setMagentaLED(true); break;
            case 6: setWhiteLED(true); break;
        }

        state = (state + 1) % 7;
    }
}
