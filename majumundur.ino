int incomingByte = 0; // for incoming serial data
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

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
      pinMode(PinR1,OUTPUT);
      pinMode(LED,OUTPUT);
      pinMode(PinR2,OUTPUT);
      pinMode(PinL1,OUTPUT);
      pinMode(PinL2,OUTPUT);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte =  Serial.parseInt();
    if(incomingByte<0){
              digitalWrite(PinR1, 0);
              digitalWrite(PinR2 ,1);
              analogWrite(PwmR, 100);
              digitalWrite(PinL1, 0);
              digitalWrite(PinL2 ,1);
              analogWrite(PwmL, 100);
              delay(20);
              maju_kanan(incomingByte);
              maju_kiri(incomingByte);Serial.println(incomingByte,DEC);
  }
  else if(incomingByte>=0){
              digitalWrite(PinR1, 1);
              digitalWrite(PinR2 ,0);
              analogWrite(PwmR, 100);
              digitalWrite(PinL1, 1);
              digitalWrite(PinL2 ,0);
              analogWrite(PwmL, 100);
              delay(20);Serial.println(incomingByte,DEC);
              mundur_kanan(incomingByte);
              mundur_kiri(incomingByte);}
  }
  /*  else{
       digitalWrite(PinR1, a);
              digitalWrite(PinR2 ,b);
              analogWrite(PwmR, 0);
               digitalWrite(PinL1, a);
              digitalWrite(PinL2 ,b);
              analogWrite(PwmL, 0);}*/}
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
