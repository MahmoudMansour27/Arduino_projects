int ch = 4;// number of relays you got
int relay[]={2,3,4,5}; // Arduino pin numbers. the same number of relay should be defined here as input pins right to left


int wait = 2000;// delay time
int i=0;

void setup() {
    Serial.begin(9600);// prepare Serial monitor
    // set  pins as output
 for(i=0; i < ch; i++)
 {    
    pinMode(relay[i], OUTPUT);// sent i(th) pin as output
   digitalWrite(relay[i], HIGH); // Turn the relay OFF  
 }
               
    Serial.println("Robojax 4 Relay Test");
}

void loop() {
    
  
 
      Serial.print("Relay "); Serial.print(1);Serial.println(" ON"); //first pump 
      digitalWrite(relay[0], LOW); // Turn the relay ON    
      delay(3500); 
      
      Serial.print("Relay "); Serial.print(1);Serial.println(" OFF");  //First pump
      digitalWrite(relay[0], HIGH); // Turn the relay OFF    

      
      Serial.print("Relay "); Serial.print(3);Serial.println(" ON");   //motor
      digitalWrite(relay[2], LOW); // Turn the relay ON    
      delay(2500);

      Serial.print("Relay "); Serial.print(3);Serial.println(" OFF");   //motor
      digitalWrite(relay[2], HIGH); // Turn the relay OFF    


      Serial.print("Relay "); Serial.print(2);Serial.println(" ON");   //Second pump
      digitalWrite(relay[1], LOW); // Turn the relay ON    
      delay(3500);

      Serial.print("Relay "); Serial.print(2);Serial.println(" ON");   //Second pump
      digitalWrite(relay[1], HIGH); // Turn the relay OFF    

      

      Serial.println("====== loop done ==");

}

