#include <Ultrasonic.h>
#include <Servo.h>
Ultrasonic ultrasonic(12, 13);
Servo mag;
Servo cont1;
int pos = 0;
int result;

void setup() {
  Serial.begin(9600);
  mag.attach(9);
  cont1.attach(10);
  mag.write(200);
  cont1.write(20);
  }

void loop() {
  while(true){  
   delay(500);
   Serial.print("Distance in CM: ");
   Serial.println(ultrasonic.distanceRead());
   result = ultrasonic.distanceRead();
   if(result==16)
   {
     Serial.print("Servo Start\n");
     mag.write(80);
     delay(20000);
     mag.write(85);
     cont1.write(50);
     mag.write(170);
     cont1.write(5);
     Serial.print("Servo end");
   }
   if(result==17)
   {
     Serial.print("Servo Start\n");
     mag.write(80);
     delay(20000);
     mag.write(85);
     cont1.write(50);
     mag.write(170);
     cont1.write(5);
     Serial.print("Servo end");
   }
  }
}
