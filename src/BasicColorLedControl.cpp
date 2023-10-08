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

void BasicColorLedControl::setLEDColor(LedColor color)
{
    switch (color)
    {
        case RED:
            setLEDColor(true, false, false);
            break;
        case BLUE:
            setLEDColor(false, false, true);
            break;
        case GREEN:
            setLEDColor(false, true, false);
            break;
        case YELLOW:
            setLEDColor(true, true, false);
            break;
        case CYAN:
            setLEDColor(false, true, true);
            break;
        case MAGENTA:
            setLEDColor(true, false, true);
            break;
        case WHITE:
            setLEDColor(true, true, true);
            break;
        default:
            unsetLEDs();
            break;
    }
}

void BasicColorLedControl::TestLEDs(void)
{
    static unsigned long lastChange = 0;
    static LedColor state = RED;

    if (millis() - lastChange > 1300) 
    {
        lastChange = millis();
        unsetLEDs();

        setLEDColor(state);

        state = static_cast<LedColor>((state + 1) % 7);
    }

}