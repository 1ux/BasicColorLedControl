#include "src/BasicColorLedControl.h"
BasicColorLedControl ledControl;

void setup() {
  // put your setup code here, to run once:
  ledControl.setupLEDs(2,3,4,COMMON_CATHODE);

}

void loop() {
  // put your main code here, to run repeatedly:
  ledControl.TestLEDs();
}
