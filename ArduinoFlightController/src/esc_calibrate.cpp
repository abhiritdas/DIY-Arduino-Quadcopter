/*
    08.13.2024 : NOT GUARENTEED TO WORK
*/

// #include <ESP32Servo.h>

// Servo mot1;
// Servo mot2;
// Servo mot3;
// Servo mot4;

// const int mot1_pin = 14;  //top right
// const int mot2_pin = 13;  //rear right
// const int mot3_pin = 12;  //rear left
// const int mot4_pin = 27;  //top left

// void setup() {

// Serial.begin(115200);

//   mot1.attach(mot1_pin, 1000, 2000); // Attach motor with a range of 1000-2000 µs
//   mot2.attach(mot2_pin, 1000, 2000);
//   mot3.attach(mot3_pin, 1000, 2000);
//   mot4.attach(mot4_pin, 1000, 2000);

//   // Send maximum signal
//   mot1.write(180); // 2000 µs
//   mot2.write(180);
//   mot3.write(180);
//   mot4.write(180);

//   Serial.println("Plug in Battery in 5");
//   delay(1000);
//     Serial.println("Plug in Battery in 4");
//   delay(1000);
//     Serial.println("Plug in Battery in 3");
//   delay(1000);
//     Serial.println("Plug in Battery in 2");
//   delay(1000);
//     Serial.println("Plug in Battery in 1");
//   delay(1000);

//     Serial.println("STAND BACK");
//   // Send minimum signal
//   mot1.write(0); // 1000 µs
//   mot2.write(0);
//   mot3.write(0);
//   mot4.write(0);
//   delay(2000); // Wait for 2 seconds

//   // End calibration and enter normal operation
// //1000us = 0% duty cycle, 2000us = 100% duty cycle 
//   //gradual incline and decline
//   int throttle = 1000;
//   while(throttle < 2000) {
//     mot1.writeMicroseconds(throttle);
//     mot2.writeMicroseconds(throttle);
//     mot3.writeMicroseconds(throttle);
//     mot4.writeMicroseconds(throttle);
//     throttle++;
//     delay(20);
//   }
//   while(throttle > 0) {
//     mot1.writeMicroseconds(throttle);
//     mot2.writeMicroseconds(throttle);
//     mot3.writeMicroseconds(throttle);
//     mot4.writeMicroseconds(throttle);
//     throttle--;
//     delay(20);
//   }
//   throttle = 0;
//     mot1.writeMicroseconds(throttle);
//     mot2.writeMicroseconds(throttle);
//     mot3.writeMicroseconds(throttle);
//     mot4.writeMicroseconds(throttle);
// }

// void loop() {
//   // Normal flight code here
// }
