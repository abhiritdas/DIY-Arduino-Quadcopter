// /*
//     RUN THIS ON ARDUINO IDE AND OPEN SERIAL PLOTTER
//     WAIT FOR 3 SECOND CALIBRATION, SOLID BLUE LIGHT INDICATES READY
// */

#include <Wire.h>
#include <Arduino.h>

volatile float RatePitch, RateRoll, RateYaw;
volatile float RateCalibrationPitch, RateCalibrationRoll, RateCalibrationYaw;
int RateCalibrationNumber;

volatile float AccX, AccY, AccZ;
volatile float AngleRoll, AnglePitch;

void gyro_signals(void){
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x1C);
  Wire.write(0x10);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(); 
  Wire.requestFrom(0x68,6);
  int16_t AccXLSB = Wire.read() << 8 | Wire.read();
  int16_t AccYLSB = Wire.read() << 8 | Wire.read();
  int16_t AccZLSB = Wire.read() << 8 | Wire.read();
  Wire.beginTransmission(0x68);
  Wire.write(0x1B); 
  Wire.write(0x8);
  Wire.endTransmission();                                                   
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0x68,6);
  int16_t GyroX=Wire.read()<<8 | Wire.read();
  int16_t GyroY=Wire.read()<<8 | Wire.read();
  int16_t GyroZ=Wire.read()<<8 | Wire.read();
  RateRoll=(float)GyroX/65.5;
  RatePitch=(float)GyroY/65.5;
  RateYaw=(float)GyroZ/65.5;
  AccX=(float)AccXLSB/4096;
  AccY=(float)AccYLSB/4096;
  AccZ=(float)AccZLSB/4096;
  AccZ=AccZ-0.26; // calibration offset
  AngleRoll=atan(AccY/sqrt(AccX*AccX+AccZ*AccZ))*1/(3.142/180);
  AnglePitch=-atan(AccX/sqrt(AccY*AccY+AccZ*AccZ))*1/(3.142/180);
  
}

void setup() {
  Serial.begin(115200);
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  Wire.beginTransmission(0x68); 
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();

  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  for (RateCalibrationNumber = 0; RateCalibrationNumber < 3000; RateCalibrationNumber++)
  {
    gyro_signals();
    RateCalibrationRoll += RateRoll;
    RateCalibrationPitch += RatePitch;
    RateCalibrationYaw += RateYaw;
    delay(1);
  }
  RateCalibrationRoll /= 3000;
  RateCalibrationPitch /= 3000;
  RateCalibrationYaw /= 3000;
  digitalWrite(2, HIGH);
}

void loop() {

    gyro_signals();
    RateRoll -= RateCalibrationRoll;
    RatePitch -= RateCalibrationPitch;
    RateYaw -= RateCalibrationYaw;

    //Angles from accelerometer
    Serial.print("AngleRoll:");
    Serial.print(AngleRoll);
    Serial.print("  ");
    Serial.print("AnglePitch:");
    Serial.println(AnglePitch);

    Serial.println("");

    //Angular rates from gyro
    Serial.print("RateRoll:");
    Serial.print(RateRoll);
    Serial.print("  ");
    Serial.print("RatePitch:");
    Serial.println(RatePitch);
    Serial.println(" ");
    Serial.print("RateYaw:");
    Serial.println(RateYaw);
    Serial.println(10);     //irrelevant value used to zoom out in Serial plotter
}