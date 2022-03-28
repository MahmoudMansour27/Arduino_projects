#include <SoftwareSerial.h>
#include <Servo.h>
Servo tds;
int bluetoothTx = A5;
int bluetoothRx = A4; 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
int flag = 0;
int ch = 4;
int relay[]= {2,3,4,5};
int i = 0;

void setup() {
  Serial.begin(9600);
  tds.attach(9);
  tds.write(200);
  for (i=0; i<ch; i++){
     pinMode(relay[i], OUTPUT);
     digitalWrite(relay[i], HIGH);
  }
  Serial.println("Relay is ready");
}

void loop() {
  while(true){
    if (Serial.available()>0){
      char stat = Serial.read();
      int TDS = 1300;
      if(stat == 's'){
        Serial.println("The program is working"); 
        if (TDS > 1200){
          tds.write(10);
          Serial.println("TDS Sensor does not work");
          digitalWrite(relay[0], LOW); 
          delay(10000);
          digitalWrite(relay[0], HIGH);
          tds.write(200);
          }
        if (TDS < 150){
          tds.write(10);
          Serial.println("TDS sensor is working");
          }
      }    
         
      if (stat == 'e'){
        Serial.println("The program is stopped");
        tds.write(200);
        } 
     }
  }
}
