#include <SPI.h>
#include <Wire.h>
const int MPU_addr=0x68;
using namespace std;
double AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
double aX,DaX,aY,DaY,aZ,DaZ,RealDX,RealDY,RealDZ;
int incomingByte = 0; // for incoming serial data        //
const int PinR1 = 5;    //  arduino  pin 5 to l298  pin IN4
const int PinR2 = 6;    //  arduino  pin 6 to l298  pin IN3
const int PinL1 = 7;    //  arduino  pin 7 to l298  pin IN1
const int PinL2 = 8;    //  arduino  pin 8 to l298  pin IN2
const int PwmR  = 9;    //  arduino  pin 9 to l298  pin ENB
const int PwmL  = 10;   //  arduino  pin 10 to l298  pin ENA
const int LED  = 13;
int data_temp=0;
void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
      pinMode(PinR1,OUTPUT);
      pinMode(LED,OUTPUT);
      pinMode(PinR2,OUTPUT);
      pinMode(PinL1,OUTPUT);
      pinMode(PinL2,OUTPUT);
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
  int asli=0;
  int power=0;
  
  Serial.print("RealD X = ");Serial.print(RealDX);
  Serial.print(" | RealD Y = ");Serial.print(RealDY);
  Serial.print(" | RealD Z = ");Serial.println(RealDZ);
  asli=RealDY;
  
  if(RealDY>0){
   power=+RealDY+20;
              if(data_temp>=0){
                digitalWrite(PinR1, 0);
              digitalWrite(PinR2 ,1);
              analogWrite(PwmR, 100);
              digitalWrite(PinL1, 0);
              digitalWrite(PinL2 ,1);
              analogWrite(PwmL, 100);
              delay(20);
              data_temp=-1;
              }
              maju_kanan(power);
              maju_kiri(power);Serial.println(RealDY);
  }
  else if(RealDY<=0){
    if(RealDY<0){
      power=+abs(RealDY)+20;}
              if(data_temp<=0){
              digitalWrite(PinR1, 1);
              digitalWrite(PinR2 ,0);
              analogWrite(PwmR, 100);
              digitalWrite(PinL1, 1);
              digitalWrite(PinL2 ,0);
              analogWrite(PwmL, 100);
              delay(20);Serial.println(RealDY);
              data_temp=1;
              }
              mundur_kanan(power);
              mundur_kiri(power);}
  
  
  }
   void maju_kanan(int pwmi){
    int a = 0;             // L298N to IN 1 to 4
    int b = 1;  
              digitalWrite(PinR1, a);
              digitalWrite(PinR2 ,b);
              analogWrite(PwmR, pwmi);}
  void maju_kiri(int pwmi){
        int a = 0;             // L298N to IN 1 to 4
    int b = 1;  
              digitalWrite(PinL1, a);
              digitalWrite(PinL2 ,b);
              analogWrite(PwmL, pwmi);
              }
  void mundur_kanan(int pwmi){    
    int a = 1;             // L298N to IN 1 to 4
    int b = 0;  
              digitalWrite(PinR1, a);
              digitalWrite(PinR2 ,b);
              analogWrite(PwmR, pwmi);
              }
  void mundur_kiri(int pwmi){
     int a = 1;             // L298N to IN 1 to 4
    int b = 0;  
              digitalWrite(PinL1, a);
              digitalWrite(PinL2 ,b);
              analogWrite(PwmL, pwmi);}
