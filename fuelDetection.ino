/*
Assuming a room temp of 20 degrees centigrade
The circuit:
  * VVC connection of the sensor attached to +5V
  * GND connection of the sensor attached to ground
  * TRIG connection of the sensor attached to digital pin 12
  * ECHO connection of the sensor attached to digital pin 13
  * Rx connection of the sensor attached to digital pin 6
  * Tx connection of the sensor attached to digital pin 7
*/

#include <SoftwareSerial.h> 

// bluetooth
#define RxD 6
#define TxD 7

//ultrasonic
#define TRIG_PIN 12
#define ECHO_PIN 13

SoftwareSerial blueToothSerial(RxD,TxD);
 
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
 
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  blueToothSerial.begin(9600);
  //wait 1s and flush the serial buffer
  delay(1000);
  Serial.flush();
  blueToothSerial.flush();
}
 
void loop()
{
  double duration, distanceIn;
 
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN,HIGH);
 
  // convert the time into a distance
  distanceIn = duration / 74 / 2;
 
  if (distanceIn <= 0) {
    Serial.println("Out of range");
  }
  else {
    blueToothSerial.print(distanceIn);
  }
  
  delay(1000);
}
