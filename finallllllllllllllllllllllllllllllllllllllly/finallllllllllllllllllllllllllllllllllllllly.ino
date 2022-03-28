#include <Servo.h>
#include <Ultrasonic.h>
Ultrasonic ultrasonic_middle(12, 13);
Ultrasonic ultrasonic_right(20, 21);
Ultrasonic ultrasonic_left(18, 19);
Servo sv;
Servo sh;
int flame_sensor = A0;
float flame_detected;
int motor1Pin1 = 3; 
int motor1Pin2 = 4;
int enable1Pin = 6;
int motor2Pin1 = 8;
int motor2Pin2 = 9;
int enable2Pin = 10;
int state;
int flag=0;
int stateStop=0;
int button = 5;
int pmp = 11;
void setup() {
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
    Serial.begin(9600);
    pinMode(button, INPUT);
    pinMode(flame_sensor, INPUT);
    pinMode(pmp, OUTPUT);
    digitalWrite(pmp, HIGH);
    sv.attach(14);
    sh.attach(15);
}

void loop() {
      if (digitalRead(button) == HIGH){
 flame_detected = digitalRead(flame_sensor);
 if (flame_detected == 1)
  {
    digitalWrite(pmp, HIGH);
    int distance_middle = ultrasonic_middle.distanceRead();
    int distance_right = ultrasonic_right.distanceRead();
    int distance_left = ultrasonic_left.distanceRead();
    if (distance_middle > distance_right && distance_middle > distance_left) // if the middle distance bigger than any distance
    {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
    }
    if (distance_right > distance_middle && distance_right > distance_left)  // if the right distance bigger than any distance
    {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
    }
    if (distance_left > distance_right && distance_left > distance_middle)  // if the left distance bigger than any distance
    {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);

    }     
  }
  if (flame_detected != 1)
  {
    digitalWrite(pmp, LOW);
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
}
          }
     if (digitalRead(button) == LOW){
     if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }      
    else if (state == 'F') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Go Forward!");
          flag=1;
        }
    }
    else if (state == 'R') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Turn LEFT");
          flag=1;
        }
    }
    else if (state == 'S' || stateStop == 1) {
        digitalWrite(pmp, HIGH);
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
    else if (state == 'L') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Turn RIGHT");
          flag=1;
        }
    }
    else if (state == 'B') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Reverse!");
          flag=1;
        }}
                else if (state == 'M') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Back Left!");
          flag=1;
        }}
       else if (state == 'N') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Back Right!");
          flag=1;
        }
     }
        else if (state == 'T') {
        digitalWrite(pmp, LOW);
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Fire Fighting");
          flag=1;
       }
     }
  else if (state == '1') {
  int p1 = 5;
  sv.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 5 degrees");
  flag=1;
       }
     }
  else if (state == '2') {
  int p1 = 10;
  sv.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor down 10 degrees");
  flag=1;
       }
     }
  else if (state == '3') {
  int p1 = 15;
  sv.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 15 degrees");
  flag=1;
       }
     }
   else if (state == '4') {
int p1 = 20;
  sv.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 20 degrees");
  flag=1;
       }
     }
     else if (state == '5') {
int p1 = 25;
  sv.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 25 degrees");
  flag=1;
       }
     }
     else if (state == '6') {
int p1 = 30;
  sv.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 30 degrees");
  flag=1;
       }
     }
       else if (state == '7') {
int p1 = 35;
  sv.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 35 degrees");
  flag=1;
       }
     }
       else if (state == '8') {
int p1 = 40;
  sv.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 40 degrees");
  flag=1;
       }
     }
       else if (state == '9') {
int p1 = 60;
  sv.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 60 degrees");
  flag=1;
       }
     }
    else if (state == 'Q') {
  int p1 = 5;
  sh.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 5 degrees");
  flag=1;
       }
     }
  else if (state == 'W') {
  int p1 = 10;
  sh.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor down 10 degrees");
  flag=1;
       }
     }
  else if (state == 'E') {
  int p1 = 15;
  sh.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 15 degrees");
  flag=1;
       }
     }
   else if (state == 'Y') {
int p1 = 20;
  sh.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 20 degrees");
  flag=1;
       }
     }
     else if (state == 'U') {
int p1 = 25;
  sh.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 25 degrees");
  flag=1;
       }
     }
     else if (state == 'I') {
int p1 = 30;
  sh.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 30 degrees");
  flag=1;
       }
     }
       else if (state == 'O') {
int p1 = 35;
  sh.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 35 degrees");
  flag=1;
       }
     }
       else if (state == 'P') {
int p1 = 40;
  sh.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 40 degrees");
  flag=1;
       }
     }
       else if (state == 'K') {
int p1 = 60;
  sh.write(p1);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  if(flag == 0){
  Serial.println("Motor up 60 degrees");
  flag=1;
       }
     }                                     
   }
}
