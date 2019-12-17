#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
const int MPU_addr=0x68;
using namespace std;

Servo ServoX, ServoY, ServoZ;
double AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
double aX,DaX,aY,DaY,aZ,DaZ,RealDX,RealDY,RealDZ;
short LS11 = 0;
short LS15 = 0;
short LS21 = 0;
short LS25 = 0;
short LS31 = 0;
short LS35 = 0;
short LS41 = 0;
short LS45 = 0;
short AntrLin = 0;
short AntrRec = 0;
short ReinVor = 0;
short ReinHin = 0;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void mpu(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)   
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  aX=AcX/16384;
  if (aX > 1){
    aX = 1;
  }
  if (aX < -1){
    aX = -1;
  }
  DaX=asin(aX);
  RealDX = DaX * 180/PI;
 
  aY=AcY/16384;
  if (aY > 1){
    aY = 1;
  }
  if (aY < -1){
    aY = -1;
  }
  DaY=asin(aY);
  RealDY = DaY * 180/PI;
  aZ=AcZ/16384;
 
  if (aZ > 1){
    aZ = 1;
  }
  if (aZ < -1){
    aZ = -1;
  }
  DaZ=asin(aZ);
  RealDZ = DaZ * 180/PI;
}



void loop() {
  mpu();
  Serial.print("RealD X = ");Serial.print(RealDX);
  Serial.print(" | RealD Y = ");Serial.print(RealDY);
  Serial.print(" | RealD Z = ");Serial.println(RealDZ);
  delay(50);
}
