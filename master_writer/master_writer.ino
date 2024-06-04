#include <Wire.h>

void setup() {
  analogReference(INTERNAL);
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(analogRead(A0)>>2);              // sends one byte
  Wire.endTransmission();    // stop transmitting
}
