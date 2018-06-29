/*
 * Oliver's first arduino program
 */
#include <Servo.h> 

int ledPin = 13;
Servo myservo;
float x;
int rx;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  myservo.attach(9);
  //myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
//    while(Serial.available()==0){
//    }
//    x = Serial.parseFloat();
//
//    Serial.print("Your float value is ");
//    Serial.println(x);
}

void serialEvent(){
  while(Serial.available()){
      rx = Serial.parseInt(); 
      Serial.println(rx);
      switch(rx){
           case 1:
              for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
                // in steps of 1 degree
                myservo.write(pos);              // tell servo to go to position in variable 'pos'
                delay(15);                       // waits 15ms for the servo to reach the position
                }
              for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
                myservo.write(pos);              // tell servo to go to position in variable 'pos'
                delay(15);                       // waits 15ms for the servo to reach the position
              }
              Serial.println("We're in the case statement");
              break;
        }
   }
}
