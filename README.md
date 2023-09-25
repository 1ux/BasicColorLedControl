*„Das Gesicht des Menschen erkennst du bei Licht, seinen Charakter im Dunkeln.“ - Verfasser unbekannt*

# RGB Multi Color LED Control

This is a simple Arduino library used to easily drive a RGB color LED (common anode or common cathode) and mix the colors.
It uses the principle of [additive color mixing](https://en.wikipedia.org/wiki/Additive_color), resulting in the following 7 colors: red, green, blue, yellow, cyan, magenta and white.
As long as you use the Arduino definitions, it should not matter which microcontroller or board you use.

<p align="center">
  <img width="120" height="120" src="Figures/additive_mixing_example.svg">
</p>

[Graphic Source of the color circles](https://de.wikipedia.org/wiki/Datei:Synthese%2B.svg)


If you drive only one pin of the RGB LED, you get the 3 basic colors. The other colours are obtained by mixing these basic colours.
<p align="center">
  <img width="504" height="288" src="Figures/RGB_LED.svg">
</p>

## Hardware Setup

An RGB LED combines 3 LEDs in one. Depending on your taste, they are available with a common anode or a common cathode.
Below you can see the internal circuit structure.
<p align="center">
  <img width="340" height="313" src="Figures/schematic_RGB_LED.png">
</p>

It can make sense to choose the common anode if the power consumption of components is higher, as this way it is not the microcontroller that limits the current, but the voltage source to which the microcontroller is usually also connected.
But this should not be an issue with one RGB LED. Depending on the microcontroller and power supply, however, they should keep an eye on the current to be driven. As a rule, you should consider series resistors for (light-emitting) diodes.

## Usage
1. Copy the src directory into your current Arduino project directory. Alternatively, you can also move the „./MultiColorLedControl“ directory to your Arduino library directory. (~/Arduino/libraries/)
2. Include the header file using the include directive.
3. This library is organized in a class. First create an object.
4. Then call the setup method and specify the 3 hardware ports of the microcontroller to which the RGB LED is connected. As the last parameter, specify the LED type as COMMON_ANODE or COMMON_CATHODE.
5. Now you can use the LED. First run the test method that displays all colors individually to make sure everything is connected correctly to the microcontroller.


Here is an example as Common Cathode :

```C
#include "src/MultiColorLedControl/MultiColorLedControl.h"
MultiColorLedControl ledControl;

void setup() {
  // put your setup code here, to run once:
  ledControl.setupLEDs(11,10,9,COMMON_CATHODE);

}

void loop() {
  // put your main code here, to run repeatedly:
  ledControl.TestLEDs();
}
```

All other methods should be self-explanatory. Here are all the methods of the library:

## Library overview

```C
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
```


## Thanks to:

- [Jana Weigel](https://janaweigel.wordpress.com/) for graphic design.

## Licence
This program by Michael Krause is licenced under the terms of the GPLv3.
