int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int pinDP =13;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

void setup() {
  pinMode(pinDP,OUTPUT);
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  

}

void loop() {
  
digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
  //0
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 0);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);   
   digitalWrite(pinDP,1); 
  delay(2);               // wait for a second
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
 delay(2); 
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
  //1
  digitalWrite(pinA, 0);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 0);
  digitalWrite(pinDP,0);   
  delay(4);               // wait for a second*/
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
  delay(2);
  digitalWrite(D1, 0);
  digitalWrite(D2, 0);
  digitalWrite(D3,1);
  digitalWrite(D4,0);
  //3
  digitalWrite(pinA, 0);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 0);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 0);     
   digitalWrite(pinDP,1); 
  delay(4);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
  delay(2);               // wait for a second
digitalWrite(D1, 0);
  digitalWrite(D2, 0);
  digitalWrite(D3,0);
  digitalWrite(D4,1);
  //3
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 0);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 0);   
  digitalWrite(pinG, 0);     
   digitalWrite(pinDP,1); 
  delay(3);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
  delay(4);               // wait for a second
  

}
