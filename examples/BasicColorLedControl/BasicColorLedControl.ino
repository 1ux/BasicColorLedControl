/*
Library overview:

// Configures the outputs, sets the LedType (COMMON_ANODE/COMMON_CATHODE), defines the hardware ports based on their connection
void setupLEDs(redLEDport, greenLEDport, blueLEDport, ledType);

//Raw function call to mix the LED colors by yourself. Good for efficient bit shifting operations
void setLEDColor(bool red, bool green, bool blue);

//Comfortable function call to set the LED color. You have the choice: RED, BLUE, GREEN, YELLOW, CYAN, MAGENTA, WHITE
void setLEDColor(LedColor color);

// Deactivates all LEDs
void unsetLEDs(void);

// Test the LED functions in the Arduino loop() function
void TestLEDs(void);
*/

#include <BasicColorLedControl.h>
BasicColorLedControl RGBled;

void setup() {
  // put your setup code here, to run once:
  RGBled.setupLEDs(9,10,11,COMMON_CATHODE);

}

void loop() {
  // put your main code here, to run repeatedly:
  RGBled.TestLEDs();
}
