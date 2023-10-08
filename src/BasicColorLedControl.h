#ifndef BasicColorLedControl_h
#define BasicColorLedControl_h

/*
 * This is a tiny and clearly arranged Arduino library for the basic RGB LED functions, 
 * to easily drive an RGB color LED (common anode/common cathode) and mix the colors.
 * The LEDs are intuitively turned on or off, regardless of their type.
 * As long as you use the Arduino definitions,
 * it should not matter which microcontroller or board you use.
 *
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
enum LedType //Possible LED types
{
    COMMON_ANODE,
    COMMON_CATHODE
};

enum LedColor //Basic RGB LED Colors
{
    RED,
    BLUE,
    GREEN,
    YELLOW,
    CYAN,
    MAGENTA,
    WHITE
};

class BasicColorLedControl 
{
    private:
        uint8_t blueLED_Port;
        uint8_t greenLED_Port;
        uint8_t redLED_Port;
        LedType led_Type;

    public:
        // Configures the outputs, sets the LedType (COMMON_ANODE/COMMON_CATHODE), defines the hardware ports based on their connection
        void setupLEDs(uint8_t redLEDport, uint8_t greenLEDport, uint8_t blueLEDport, LedType ledType);

        //Raw function call to mix the LED colors by yourself. Good for efficient bit shifting operations
        void setLEDColor(bool red, bool green, bool blue);

        //Comfortable function call to set the LED color. You have the choice: RED, BLUE, GREEN, YELLOW, CYAN, MAGENTA, WHITE
        void setLEDColor(LedColor color);

        // Deactivates all LEDs
        void unsetLEDs(void);

        // Test the LED functions in the Arduino loop() function
        void TestLEDs(void);
};

#endif