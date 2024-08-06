// #include <ESP32Servo.h>

// // Create Servo objects for each ESC
// Servo esc1, esc2, esc3, esc4;

// volatile uint32_t current_time;
// volatile uint32_t last_channel_1 = 0;
// volatile uint32_t last_channel_2 = 0;
// volatile uint32_t last_channel_3 = 0;
// volatile uint32_t last_channel_4 = 0;
// volatile uint32_t last_channel_5 = 0;
// volatile uint32_t last_channel_6 = 0;
// volatile uint32_t timer_1;
// volatile uint32_t timer_2;
// volatile uint32_t timer_3;
// volatile uint32_t timer_4;
// volatile uint32_t timer_5;
// volatile uint32_t timer_6;
// volatile int ReceiverValue[6]; // Increase the array size to 6 for Channel 1 to Channel 6
// const int channel_1_pin = 34;
// const int channel_2_pin = 35;
// const int channel_3_pin = 32;
// const int channel_4_pin = 33;
// const int channel_5_pin = 25;
// const int channel_6_pin = 26;

// // Pin definitions
// const int esc1Pin = 13;
// const int esc2Pin = 12;
// const int esc3Pin = 14;
// const int esc4Pin = 27;


// void channelInterruptHandler()
// {
//   current_time = micros();

//   // Channel 1
//   if (digitalRead(channel_1_pin))
//   {
//     if (last_channel_1 == 0)
//     {
//       last_channel_1 = 1;
//       timer_1 = current_time;
//     }
//   }
//   else if (last_channel_1 == 1)
//   {
//     last_channel_1 = 0;
//     ReceiverValue[0] = current_time - timer_1;
//   }

//   // Channel 2
//   if (digitalRead(channel_2_pin))
//   {
//     if (last_channel_2 == 0)
//     {
//       last_channel_2 = 1;
//       timer_2 = current_time;
//     }
//   }
//   else if (last_channel_2 == 1)
//   {
//     last_channel_2 = 0;
//     ReceiverValue[1] = current_time - timer_2;
//   }

//   // Channel 3
//   if (digitalRead(channel_3_pin))
//   {
//     if (last_channel_3 == 0)
//     {
//       last_channel_3 = 1;
//       timer_3 = current_time;
//     }
//   }
//   else if (last_channel_3 == 1)
//   {
//     last_channel_3 = 0;
//     ReceiverValue[2] = current_time - timer_3;
//   }

//   // Channel 4
//   if (digitalRead(channel_4_pin))
//   {
//     if (last_channel_4 == 0)
//     {
//       last_channel_4 = 1;
//       timer_4 = current_time;
//     }
//   }
//   else if (last_channel_4 == 1)
//   {
//     last_channel_4 = 0;
//     ReceiverValue[3] = current_time - timer_4;
//   }

//   // Channel 5
//   if (digitalRead(channel_5_pin))
//   {
//     if (last_channel_5 == 0)
//     {
//       last_channel_5 = 1;
//       timer_5 = current_time;
//     }
//   }
//   else if (last_channel_5 == 1)
//   {
//     last_channel_5 = 0;
//     ReceiverValue[4] = current_time - timer_5;
//   }

//   // Channel 6
//   if (digitalRead(channel_6_pin))
//   {
//     if (last_channel_6 == 0)
//     {
//       last_channel_6 = 1;
//       timer_6 = current_time;
//     }
//   }
//   else if (last_channel_6 == 1)
//   {
//     last_channel_6 = 0;
//     ReceiverValue[5] = current_time - timer_6;
//   }

//   //TOGGLE KILL SWITCH
//   if(ReceiverValue[4] < 1500) {
//       //ESC IS BEING DISCONNECTED AND SET TO UNUSED PIN 17
//       esc1.attach(17);
//       esc2.attach(17);
//       esc3.attach(17);
//       esc4.attach(17);
//   }
// }

// void armESC(Servo &esc) {
//   // Send a low throttle signal to arm the ESC
//   esc.writeMicroseconds(1000);
//   delay(2000); // Wait for 2 seconds to ensure the ESC is armed
// }

// void setup() {
//   pinMode(channel_1_pin, INPUT_PULLUP);
//   pinMode(channel_2_pin, INPUT_PULLUP);
//   pinMode(channel_3_pin, INPUT_PULLUP);
//   pinMode(channel_4_pin, INPUT_PULLUP);
//   pinMode(channel_5_pin, INPUT_PULLUP);
//   pinMode(channel_6_pin, INPUT_PULLUP);

//   attachInterrupt(digitalPinToInterrupt(channel_1_pin), channelInterruptHandler, CHANGE);
//   attachInterrupt(digitalPinToInterrupt(channel_2_pin), channelInterruptHandler, CHANGE);
//   attachInterrupt(digitalPinToInterrupt(channel_3_pin), channelInterruptHandler, CHANGE);
//   attachInterrupt(digitalPinToInterrupt(channel_4_pin), channelInterruptHandler, CHANGE);
//   attachInterrupt(digitalPinToInterrupt(channel_5_pin), channelInterruptHandler, CHANGE);
//   attachInterrupt(digitalPinToInterrupt(channel_6_pin), channelInterruptHandler, CHANGE);

//   // Attach each ESC to the appropriate pin
//   esc1.attach(esc1Pin);
//   esc2.attach(esc2Pin);
//   esc3.attach(esc3Pin);
//   esc4.attach(esc4Pin);

//   // Start serial communication for debugging
//   Serial.begin(115200);

//   // Arm the ESCs by sending a low throttle signal
//   armESC(esc1);
//   armESC(esc2);
//   armESC(esc3);
//   armESC(esc4);
//   Serial.println("Setup completed");
// }

// void loop() {

//   channelInterruptHandler();  //redundancy

//   //1000us = 0% duty cycle, 2000us = 100% duty cycle 
//   //gradual incline and decline
//   int throttle = 1000;
//   while(throttle < 2000) {
//     esc1.writeMicroseconds(throttle);
//     esc2.writeMicroseconds(throttle);
//     esc3.writeMicroseconds(throttle);
//     esc4.writeMicroseconds(throttle);
//     throttle++;
//     delay(20);
//   }
//   while(throttle > 0) {
//     esc1.writeMicroseconds(throttle);
//     esc2.writeMicroseconds(throttle);
//     esc3.writeMicroseconds(throttle);
//     esc4.writeMicroseconds(throttle);
//     throttle--;
//     delay(20);
//   }
// }
