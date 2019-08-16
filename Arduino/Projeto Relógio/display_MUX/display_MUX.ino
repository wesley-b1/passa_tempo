#define A 0
#define B 1
#define C 2
#define pinOUT 3
#define pinA 4
#define pinB 5
#define pinC 6
#define pinD 7
#define pinE 8
#define pinF 9
#define pinG 10
//#define botao 11
//#define pot 0
void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(pinOUT, OUTPUT);
  
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
//  pinMode(botao, OUTPUT);
  digitalWrite(pinOUT,1);
  pinMode(A0,INPUT);
  //pinMode(A1,INPUT);
 //Serial.begin(9600);
}


void loop() {
  analogWrite(pinOUT,map(analogRead(A0),0,1023,30,255));
 /* if(botao==1){
    Serial.print("Manual\n");
  analogWrite(pinOUT,map(analogRead(A0),0,1023,30,255));
  }else{
   Serial.print("Automatico\n");
    analogWrite(pinOUT,map(analogRead(A1),0,1023,30,255));
    }*/
  digitalWrite(A,0);
  digitalWrite(B,0);
  digitalWrite(C,1);
//numero 1
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 0);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);
delay(5);

digitalWrite(A,0);
digitalWrite(B,1);
digitalWrite(C,0);
//numero 2
 digitalWrite(pinA, 0);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 0);

delay(5);

digitalWrite(A,0);
digitalWrite(B,1);
digitalWrite(C,1);
//numero 3
 digitalWrite(pinA, 0);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 0);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 0);
delay(5);
digitalWrite(A,1);
digitalWrite(B,0);
digitalWrite(C,0);
//numero 4
 digitalWrite(pinA, 1);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 0);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 0);   
  digitalWrite(pinG, 0);
delay(5);  
}
