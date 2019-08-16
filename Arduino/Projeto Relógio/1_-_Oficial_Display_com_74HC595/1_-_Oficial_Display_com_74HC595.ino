/*
  No 74HC595
  pin 15 (Out0) está no PinA do DISPLAY
  pin 1 (Out1) está no PinB do DISPLAY
  pin 2 (Out2) está no PinC do DISPLAY
  pin 3 (Out3) está no PinD do DISPLAY
  pin 4 (Out4) está no PinE do DISPLAY
  pin 5 (Out5) está no PinF do DISPLAY
  pin 6 (Out6) está no PinG do DISPLAY
  pin 7 (Out7) está no PinDP do DISPLAY

  Pin 16 no Vcc
  Pin 10 no Vcc
  Pin 8 GND
  Pin 13 GND
  pin 11 no D8
  pin 12 no D12 - - -ligar um capacitor eletrolitico de 1 microFaraday (uF) deste pino para o GND
  pin14 no D13
*/
#define pinSH_CP 8   //Pino Clock
#define pinST_CP 12  //Pino Latch
#define pinDS    13  //Pino Data
#define qtdeCI   1//quantos CI's estamos utilizando, apenas 1
#define Seg1 5 //pino PWM
#define Seg2 6//pino PWM
#define Seg3 9//pino PWM
#define Seg4 10//pino PWM


//pino: número da porta do CI
//estado: valor HIGH ou LOW
void ci74HC595Write(byte pino, bool estado);//funciona igualmente
//a função digitalWrite(variavel,valor) para uma porta que está
//em OUTPUT
void numero1();
void numero2();
void numero3();
void numero4();
void setup() {
  pinMode(pinSH_CP, OUTPUT);
  pinMode(pinST_CP, OUTPUT);
  pinMode(pinDS, OUTPUT);
  pinMode(Seg1, OUTPUT);
  pinMode(Seg2, OUTPUT);
  pinMode(Seg3, OUTPUT);
  pinMode(Seg4, OUTPUT);

}

void loop() {
  numero1();
  digitalWrite(Seg1, LOW);
  digitalWrite(Seg2, LOW);
  digitalWrite(Seg3, LOW);
  digitalWrite(Seg4, LOW);
  delay(1);
  numero2();
  delay(1);
  digitalWrite(Seg1, LOW);
  digitalWrite(Seg2, LOW);
  digitalWrite(Seg3, LOW);
  digitalWrite(Seg4, LOW);
  delay(1);
  numero3();
  delay(1);
  digitalWrite(Seg1, LOW);
  digitalWrite(Seg2, LOW);
  digitalWrite(Seg3, LOW);
  digitalWrite(Seg4, LOW);
  delay(1);
  numero4();
  delay(1);
  digitalWrite(Seg1, LOW);
  digitalWrite(Seg2, LOW);
  digitalWrite(Seg3, LOW);
  digitalWrite(Seg4, LOW);

}

void numero1() {
  //numero 1
  ci74HC595Write(0, 1); //A desligado
  ci74HC595Write(1, 0); //B ligado
  ci74HC595Write(2, 0); //C ligado
  ci74HC595Write(3, 1); //D desligado
  ci74HC595Write(4, 1); //E desligado
  ci74HC595Write(5, 1); //F desligado
  ci74HC595Write(6, 1); //G desligado
  ci74HC595Write(7, 1); //DP desligado
  //delay(1);
  //segmento 2 ligado
  digitalWrite(Seg1, HIGH);
  digitalWrite(Seg2, LOW);
  digitalWrite(Seg3, LOW);
  digitalWrite(Seg4, LOW);
  delay(3);
}

void numero2() {
  //numero 2
  ci74HC595Write(0, 0); //A ligado
  ci74HC595Write(1, 0); //B ligado
  ci74HC595Write(2, 1); //C desligado
  ci74HC595Write(3, 0); //D ligado
  ci74HC595Write(4, 0); //E ligado
  ci74HC595Write(5, 1); //F desligado
  ci74HC595Write(6, 0); //G ligado
  ci74HC595Write(7, 0); //DP ligado
 // delay(1);
  //segmento 2 ligado
  digitalWrite(Seg1, LOW);
  digitalWrite(Seg2, HIGH);
  digitalWrite(Seg3, LOW);
  digitalWrite(Seg4, LOW);
  delay(3);
}

void numero3() {
  //numero 3
  ci74HC595Write(0, 0); //A ligado
  ci74HC595Write(1, 0); //B ligado
  ci74HC595Write(2, 0); //C ligado
  ci74HC595Write(3, 0); //D ligado
  ci74HC595Write(4, 1); //E desligado
  ci74HC595Write(5, 1); //F desligado
  ci74HC595Write(6, 0); //G ligado
  ci74HC595Write(7, 1); //DP desligado
 // delay(1);
  //segmento 3 ligado
  digitalWrite(Seg1, LOW);
  digitalWrite(Seg2, LOW);
  digitalWrite(Seg3, HIGH);
  digitalWrite(Seg4, LOW);
  delay(3);
}

void numero4() {
  //numero 4
  ci74HC595Write(0, 1); //A desligado
  ci74HC595Write(1, 0); //B ligado
  ci74HC595Write(2, 0); //C ligado
  ci74HC595Write(3, 1); //D desligado
  ci74HC595Write(4, 1); //E desligado
  ci74HC595Write(5, 0); //F ligado
  ci74HC595Write(6, 0); //G ligado
  ci74HC595Write(7, 1); //DP desligado
 // delay(1);
  //segmento 4 ligado
  digitalWrite(Seg1, LOW);
  digitalWrite(Seg2, LOW);
  digitalWrite(Seg3, LOW);
  digitalWrite(Seg4, HIGH);
  delay(3);
}


void ci74HC595Write(byte pino, bool estado) {
  static byte ciBuffer[qtdeCI];

  bitWrite(ciBuffer[pino / 8], pino % 8, estado);

  digitalWrite(pinST_CP, LOW); //Inicia a Transmissão

  digitalWrite(pinDS, LOW);    //Apaga Tudo para Preparar Transmissão
  digitalWrite(pinSH_CP, LOW);

  for (int nC = qtdeCI - 1; nC >= 0; nC--) {
    for (int nB = 7; nB >= 0; nB--) {

      digitalWrite(pinSH_CP, LOW);  //Baixa o Clock

      digitalWrite(pinDS,  bitRead(ciBuffer[nC], nB) );     //Escreve o BIT

      digitalWrite(pinSH_CP, HIGH); //Eleva o Clock
      digitalWrite(pinDS, LOW);     //Baixa o Data para Previnir Vazamento
    }
  }

  digitalWrite(pinST_CP, HIGH);  //Finaliza a Transmissão

}
