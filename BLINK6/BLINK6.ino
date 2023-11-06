
#include <Servo.h>
#define z 126

Servo servo1;
const int emuPin = 10;
const int LEDPin = 13;
//const int intPin = 2;
const int intPin = 2;
const int e0 = 1;
const int e1 = 2;
volatile int state = LOW;
int a0=79;
int a=a0;
int Est=e0;
int ENT;
int estado=1;
int count;
int count1;
int count2;
void setup() {
   pinMode(emuPin, OUTPUT);
   pinMode(LEDPin, OUTPUT);
   pinMode(intPin, INPUT_PULLUP);
   pinMode(LED_BUILTIN, OUTPUT);
   attachInterrupt(digitalPinToInterrupt(intPin), blink, CHANGE);
   servo1.attach(9);
   Serial.begin(9600);
}
void loop() {
   //esta parte es para emular la salida
   digitalWrite(emuPin, HIGH);
   delay(150);
   digitalWrite(emuPin, LOW);
   delay(150);
   if (ENT==estado){
       ENT=0;
       if(Est==e0){
         count=count+1;
          servo1.write(a++);
         if(a==z){
            Est=e1;
          }else{}
        }else{
          servo1.write(a--);
           count=count+1;
           if(a==a0){
            Est=e0;
            }
            else{}}
            Serial.print(count); 
             Serial.print(1); 
    }}

void blink() {
     state=!state;  
      Serial.print(2);
     digitalWrite(LEDPin, state);
     digitalWrite(LED_BUILTIN, HIGH);
     ENT=1;
    
   
}
