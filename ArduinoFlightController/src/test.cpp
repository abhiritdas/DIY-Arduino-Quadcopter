#include <ESP32Servo.h>

// Create Servo objects for each ESC
Servo esc1, esc2, esc3, esc4;

// Pin definitions
const int esc1Pin = 13;
const int esc2Pin = 12;
const int esc3Pin = 14;
const int esc4Pin = 27;

void armESC(Servo &esc);
void setup() {
  // Attach each ESC to the appropriate pin
  esc1.attach(esc1Pin);
  esc2.attach(esc2Pin);
  esc3.attach(esc3Pin);
  esc4.attach(esc4Pin);

  // Start serial communication for debugging
  Serial.begin(115200);

  // Arm the ESCs by sending a low throttle signal
  armESC(esc1);
  armESC(esc2);
  armESC(esc3);
  armESC(esc4);
}

void loop() {

  //1000us = 0% duty cycle, 2000us = 100% duty cycle 
  //gradual incline and decline
  int throttle = 1000;
  while(throttle < 2000) {
    esc1.writeMicroseconds(throttle);
    esc2.writeMicroseconds(throttle);
    esc3.writeMicroseconds(throttle);
    esc4.writeMicroseconds(throttle);
    throttle++;
    delay(20);
  }
  while(throttle > 0) {
    esc1.writeMicroseconds(throttle);
    esc2.writeMicroseconds(throttle);
    esc3.writeMicroseconds(throttle);
    esc4.writeMicroseconds(throttle);
    throttle--;
    delay(20);
  }
}

void armESC(Servo &esc) {
  // Send a low throttle signal to arm the ESC
  esc.writeMicroseconds(1000);
  delay(2000); // Wait for 2 seconds to ensure the ESC is armed
}
