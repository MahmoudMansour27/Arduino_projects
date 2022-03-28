#include <Servo.h>
#include <Ultrasonic.h>
#include <SoftwareSerial.h>

int bluetoothTx = A5;
int bluetoothRx = A4; 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

Servo c;
Servo b;

Ultrasonic ci(13, 12);
Ultrasonic ba(11, 10);

int distance_ci;
int distance_ba;
int m = 0;

void setup() {
  Serial.begin(9600);
  c.attach(8);
  b.attach(9);
  c.write(0);
  b.write(0);

}

void loop() {
  distance_ci = ci.read();
  distance_ba = ba.read();
   if (bluetooth.available()>0){
    char stat = Serial.read();

    if (stat = 'ci1'){
      c.write(30);
      delay(1000);
      while(m = 0){
      if (distance_ci = 15){
        Serial.println("Done");
        m = 1;
        }
      if (distance_ci =! 15){
        Serial.println("need more");
        }  
      }
    }
   }
}

