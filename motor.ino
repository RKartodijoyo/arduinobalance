
float pwm = 255;          // value of Pulse Width Modulation  to ENA ENB
long a = 1;             // L298N to IN 1 to 4
long b =0;             //
const int PinR1 = 5;    //  arduino  pin 5 to l298  pin IN4
const int PinR2 = 6;    //  arduino  pin 6 to l298  pin IN3
const int PinL1 = 7;    //  arduino  pin 7 to l298  pin IN1
const int PinL2 = 8;    //  arduino  pin 8 to l298  pin IN2
const int PwmR  = 9;    //  arduino  pin 9 to l298  pin ENB
const int PwmL  = 10;   //  arduino  pin 10 to l298  pin ENA
const int LED  = 13;
//****************************************************************************************************************************************************

void setup(){
      pinMode(PinR1,OUTPUT);
      pinMode(LED,OUTPUT);
      
      pinMode(PinR2,OUTPUT);
      pinMode(PinL1,OUTPUT);
      pinMode(PinL2,OUTPUT);
//**********************************************************************************************************************************************************
}
    // initialize serial communication
  
void loop() {

     
              analogWrite(PwmR, pwm);
              digitalWrite(PinR1, a);
              digitalWrite(PinR2 ,b);
             
          
}
