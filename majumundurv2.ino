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
   drivermotor(incomingByte);
              delay(20);
  
  }
  /*  else{
       digitalWrite(PinR1, a);
              digitalWrite(PinR2 ,b);
              analogWrite(PwmR, 0);
               digitalWrite(PinL1, a);
              digitalWrite(PinL2 ,b);
              analogWrite(PwmL, 0);}*/}
  void drivermotor(int pwmi){
int putar =0;
    if(pwmi>=0){
      putar = pwmi;
              digitalWrite(PinR1, LOW);
              digitalWrite(PinR2 ,HIGH);
              analogWrite(PwmR, putar);
              digitalWrite(PinL1, LOW);
              digitalWrite(PinL2 ,HIGH);
              analogWrite(PwmL, putar);}
    else{       
      putar =abs(pwmi);
              digitalWrite(PinR1, HIGH);
              digitalWrite(PinR2 ,LOW);
              analogWrite(PwmR, putar);          
              digitalWrite(PinL1, HIGH);
              digitalWrite(PinL2 ,LOW);
              analogWrite(PwmL, putar);}}
