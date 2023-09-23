#ifndef MultiColorLedControl_h
#define MultiColorLedControl_h

/*
 * This is a simple Arduino library used to easily drive a rgb color LED
 * with common ground connection and mix the colors.
 * This program by Michael Krause is licenced under the terms of the GPLv3.
 * 
 *  Common Cathode LED Pins Hardware-Notes
 * -  blue (LED Pin 1)
 * -  green (LED Pin 2)
 * -- GND  (LED Pin 3, common ground)
 * -  red  (LED Pin 4)
 */

class MultiColorLedControl {

private:
    uint8_t blueLED_Port;
    uint8_t greenLED_Port;
    uint8_t redLED_Port;

public:
    // Configures the outputs and defines the hardware ports, pay attention to your circuits
    void setupLEDs(uint8_t blueLEDport, uint8_t greenLEDport, uint8_t redLEDport);
    // Raw function to mix the LED colors by yourself.
    void setLEDColor(bool red, bool green, bool blue);
    // Deactivates all LEDs
    void unsetLEDs(void);
    // Activate only the red LED
    void setRedLED(bool state);
    // Activate only the blue LED
    void setBlueLED(bool state);
    // Activate only the green LED
    void setGreenLED(bool state);
    // Activate only the yellow LED
    void setYellowLED(bool state);
    // Activate only the cyan LED
    void setCyanLED(bool state);
    // Activate only the magenta LED
    void setMagentaLED(bool state);
    // Activate only the white LED
    void setWhiteLED(bool state);
    // Test the LED functions in the Arduino loop() function
    void TestLEDs(void);
};


#endif
