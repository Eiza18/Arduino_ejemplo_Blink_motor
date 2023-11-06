#include <Servo.h>


Servo servo1;

void setup(){
  servo1.attach(9);
  Serial.begin(9600);
  }
  void loop(){
    for(int i=73; i<127; i++){
      
    servo1.write(i);
    Serial.print(i);
    delay(1000);
    }
  }
