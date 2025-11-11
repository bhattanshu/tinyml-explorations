#include "mbed.h"
mbed::DigitalIn button(P0.1);
constexpr int PRESSED = 0;

void setup() {
  // put your setup code here, to run once:
  button.mode(PullUp);
  Serial.begin(9600);
  while (!Serial);
  Serial.write("Serial Ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (button == PRESSED)
  {
    Serial.write("Button Pressed");
  }

}
