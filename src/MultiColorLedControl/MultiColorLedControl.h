#ifndef MultiColorLedControl_h
#define MultiColorLedControl_h

/*
 * This is a simple Arduino library used to easily drive a rgb color LED
 * (Common anode or common cathode) and mix the colors. As long as you use the Arduino definitions,
 * it should not matter which microcontroller or board you use.
 * This program by Michael Krause is licenced under the terms of the GPLv3.
 * 
 *  Common Cathode LED Pins Hardware-Notes
 * -  blue (LED Pin 1)
 * -  green (LED Pin 2)
 * -- GND  (LED Pin 3, common ground)
 * -  red  (LED Pin 4)
 *
 *  Common Anode LED Pins Hardware-Notes
 * -  blue (LED Pin 1)
 * -  green (LED Pin 2)
 * -- Vcc  (LED Pin 3, common anode)
 * -  red  (LED Pin 4)
 */
enum LedType //Sets the LED Type
{
    COMMON_ANODE,
    COMMON_CATHODE
};

class MultiColorLedControl 
{
    private:
        uint8_t blueLED_Port;
        uint8_t greenLED_Port;
        uint8_t redLED_Port;
        LedType led_Type;

    public:
        // Configures the outputs, sets the LED type and defines the hardware ports based on their connection
        void setupLEDs(uint8_t blueLEDport, uint8_t greenLEDport, uint8_t redLEDport, LedType ledType);
        // Raw function to mix the LED colors by yourself. true means always switch on LED, independent of LED type (COMMON_ANODE/CATHODE)
        void setLEDColor(bool red, bool green, bool blue);
        // Deactivates all LEDs, false means always switch off
        void unsetLEDs(void);
        // Activate only the red LED, true means always switch on LED
        void setRedLED(bool state);
        // Activate only the blue LED, true means always switch on LED
        void setBlueLED(bool state);
        // Activate only the green LED, true means always switch on LED
        void setGreenLED(bool state);
        // Activate only the yellow LED, true means always switch on LED
        void setYellowLED(bool state);
        // Activate only the cyan LED, true means always switch on LED
        void setCyanLED(bool state);
        // Activate only the magenta LED, true means always switch on LED
        void setMagentaLED(bool state);
        // Activate only the white LED, true means always switch on LED
        void setWhiteLED(bool state);
        // Test the LED functions in the Arduino loop() function
        void TestLEDs(void);
};

#endif