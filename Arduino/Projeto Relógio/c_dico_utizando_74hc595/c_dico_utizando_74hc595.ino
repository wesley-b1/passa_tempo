#define pinSH_CP 8   //Pino Clock
#define pinST_CP 12  //Pino Latch
#define pinDS    13  //Pino Data
#define qtdeCI   1//quantos CI's estamos utilizando, apenas 1

//pino: número da porta do CI
//estado: valor HIGH ou LOW
void ci74HC595Write(byte pino, bool estado);//funciona igualmente
//a função digitalWrite(variavel,valor); para uma porta que está
//em OUTPUT

void setup() {
  pinMode(pinSH_CP, OUTPUT);
  pinMode(pinST_CP, OUTPUT);
  pinMode(pinDS, OUTPUT);
}

void loop() {

  for (int nL = 0; nL < 8; nL++) {
    ci74HC595Write(nL, HIGH);
    delay(100);
    ci74HC595Write(nL, LOW);
  }

  for (int nL = 0; nL < 8; nL++) {
    ci74HC595Write(nL, HIGH);
  }
  delay(1000);
  for (int nL = 0; nL < 8; nL++) {
    ci74HC595Write(nL, LOW);
  }
  delay(1000);
for(int nL=0;nL<8;nL++){
  ci74HC595Write(nL, HIGH);
  delay(100);
  }
   // delay(1000);
  for (int nL = 0; nL < 8; nL++) {
    ci74HC595Write(nL, LOW);
    delay(100);
  }
delay(100);
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
