/*   Hardware

           [    RTC DS3231    -> Arduino UNO        ]
            -----------------------------------------
            SDA pin   -> Analógico 4 (SDA)
            SCL pin   -> Analógico 5 (SCL)
            VCC pin   -> 5V
            GND pin   -> GND
            -----------------------------------------

            [         74HC595   -> Display          ]
            -----------------------------------------
            pin 15 (Out0) está no PinA do DISPLAY
            pin 1 (Out1) está no PinB do DISPLAY
            pin 2 (Out2) está no PinC do DISPLAY
            pin 3 (Out3) está no PinD do DISPLAY
            pin 4 (Out4) está no PinE do DISPLAY
            pin 5 (Out5) está no PinF do DISPLAY
            pin 6 (Out6) está no PinG do DISPLAY
            pin 7 (Out7) está no PinDP do DISPLAY
            -----------------------------------------

            [        74HC595   ->  Arduino UNO       ]
            -----------------------------------------
            Pin 16 no Vcc
            Pin 10 no Vcc
            Pin 8 GND
            Pin 13 GND
            pin 11 no D8
            pin 12 no D12 - - -ligar um capacitor eletrolitico de 1 microFaraday (uF) deste pino para o GND
            pin14 no D13
  ===========================================================================

  ======================================================================================================
  --- Bibliotecas Auxiliares ---*/
#include <DS3231.h>          //Inclui a biblioteca do DS3231 Shield

//---- Declaração dos pinos no Arduino UNO
#define pinSH_CP 8   //Pino Clock
#define pinST_CP 12  //Pino Latch
#define pinDS    13  //Pino Data
#define qtdeCI   1//quantos CI's estamos utilizando, apenas 1
#define Seg1 5 //pino PWM
#define Seg2 6//pino PWM
#define Seg3 9//pino PWM
#define Seg4 10//pino PWM
//=======================================================================================================
//---------------------------------------------------------
//                    Declaração Das Funções
//------------------------------------------------------------

//pino: número da porta do CI
//estado: valor HIGH ou LOW
void ci74HC595Write(byte pino, bool estado);//funciona igualmente
//a função digitalWrite(variavel,valor) para uma porta que está
//em OUTPUT

void numero0();
void numero1();
void numero2();
void numero3();
void numero4();
void numero5();
void numero6();
void numero7();
void numero8();
void numero9();
void display1();
void display2();
void display3();
void display4();
void apagarDisplay();
// ======================================================================================================
// --- Declaração de Objetos ---
DS3231  rtc(SDA, SCL);
Time t;
int horas, minutos;


// ======================================================================================================
// --- Configurações Iniciais ---

void setup()
{

  pinMode(pinSH_CP, OUTPUT);
  pinMode(pinST_CP, OUTPUT);
  pinMode(pinDS, OUTPUT);
  pinMode(Seg1, OUTPUT);
  pinMode(Seg2, OUTPUT);
  pinMode(Seg3, OUTPUT);
  pinMode(Seg4, OUTPUT);

  Serial.begin(115200);          //Inicia comunicações Serial em 115200 baud rate

  rtc.begin();                   //Inicializa RTC

  //Descomente a linha a seguir para configurar o horário, após comente e faça o upload novamente para o Arduino
   // rtc.setTime(21,48, 0);     // Set the time to 12:30:00 (24hr format)

}
// ======================================================================================================
// --- Loop Infinito ---
void loop()
{
  
  t = rtc.getTime();
  horas = t.hour;
  minutos = t.min;
  
  int horasDezena = horas/10;//Pega o resultado inteiro (quociente). Ex.:24/10 = 2
  int horasUnidade = horas%10;//Pega o resto enquanto a conta é inteira. Ex.:24%10 = 4
  int minutosDezena = minutos/10;//Recebe o primeiro valor dos minutos
  int minutosUnidade = minutos%10;//Recebe o segundo valor dos minutos
 
  //hora dezena
  if(horasDezena == 0){numero0();}
  else if(horasDezena == 1){numero1();}
  else{numero2();}
  
  display1();
   apagarDisplay();
  //hora unidade
  if(horasUnidade == 0){numero0();}
  else if(horasUnidade == 1){numero1();}
  else if(horasUnidade == 2){numero2();}
  else{numero3();}
  
  display2();
  apagarDisplay();
  //minutos dezena
  //Só vai até o 59 minutos, então até o 5
  if(minutosDezena == 0){numero0();}
  else if(minutosDezena == 1){numero1();}
  else if(minutosDezena == 2){numero2();}
  else if(minutosDezena == 3){numero3();}
  else if(minutosDezena == 4){numero4();}
  else{numero5();}
  
  display3();
  apagarDisplay();
  //minutos unidade
  //vai até do 0 ao 9
  if(minutosUnidade == 0){numero0();}
  else if(minutosUnidade == 1){numero1();}
  else if(minutosUnidade == 2){numero2();}
  else if(minutosUnidade == 3){numero3();}
  else if(minutosUnidade == 4){numero4();}
  else if(minutosUnidade == 5){numero5();}
  else if(minutosUnidade == 6){numero6();}
  else if(minutosUnidade == 7){numero7();}
  else if(minutosUnidade ==8){numero8();}
  else{numero9();}
 
  display4();
 apagarDisplay();
  Serial.print(horasDezena);
  Serial.print("   ");
   Serial.print(horasUnidade);
  Serial.print("   ");
  Serial.print(minutosDezena);
  Serial.print("   ");
  Serial.print(minutosUnidade);
  Serial.print("   ");


  //Imprime o horário
  Serial.println(rtc.getTimeStr());

  //Atualiza monitor a cada segundo
  //delay (1000);

}
//end loop
//*********************************************************************************************************************
//====================================================================================================================
//FUNÇÕES PARA IMPRIMIR OS NÚMEROS NO DISPLAY
void numero0() {
  //numero 0
  ci74HC595Write(0, 0); //A ligado
  ci74HC595Write(1, 0); //B ligado
  ci74HC595Write(2, 0); //C ligado
  ci74HC595Write(3, 0); //D ligado
  ci74HC595Write(4, 0); //E ligado
  ci74HC595Write(5, 0); //F ligado
  ci74HC595Write(6, 1); //G desligado
  ci74HC595Write(7, 1); //DP desligado
  //delay(1);

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
  ci74HC595Write(7, 1); //DP desligado
  // delay(1);

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
  //delay(1);

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
  //delay(1);

}
void numero5() {
  //numero 5
  ci74HC595Write(0, 0); //A ligado
  ci74HC595Write(1, 1); //B desligado
  ci74HC595Write(2, 0); //C ligado
  ci74HC595Write(3, 0); //D ligado
  ci74HC595Write(4, 1); //E desligado
  ci74HC595Write(5, 0); //F ligado
  ci74HC595Write(6, 0); //G ligado
  ci74HC595Write(7, 1); //DP desligado
   //delay(1);
}
void numero6() {
  //numero 6
  ci74HC595Write(0, 0); //A ligado
  ci74HC595Write(1, 1); //B desligado
  ci74HC595Write(2, 0); //C ligado
  ci74HC595Write(3, 0); //D ligado
  ci74HC595Write(4, 0); //E ligado
  ci74HC595Write(5, 0); //F ligado
  ci74HC595Write(6, 0); //G ligado
  ci74HC595Write(7, 1); //DP desligado
  //delay(1);

}
void numero7() {
  //numero 7
  ci74HC595Write(0, 0); //A ligado
  ci74HC595Write(1, 0); //B ligado
  ci74HC595Write(2, 0); //C ligado
  ci74HC595Write(3, 1); //D desligado
  ci74HC595Write(4, 1); //E desligado
  ci74HC595Write(5, 1); //F desligado
  ci74HC595Write(6, 1); //G desligado
  ci74HC595Write(7, 1); //DP desligado
  // delay(1);

}
void numero8() {
  //numero 8
  ci74HC595Write(0, 0); //A ligado
  ci74HC595Write(1, 0); //B ligado
  ci74HC595Write(2, 0); //C ligado
  ci74HC595Write(3, 0); //D ligado
  ci74HC595Write(4, 0); //E ligado
  ci74HC595Write(5, 0); //F ligado
  ci74HC595Write(6, 0); //G ligado
  ci74HC595Write(7, 1); //DP desligado
   //delay(1);

}
void numero9() {
  //numero 9
  ci74HC595Write(0, 0); //A ligado
  ci74HC595Write(1, 0); //B ligado
  ci74HC595Write(2, 0); //C ligado
  ci74HC595Write(3, 0); //D ligado
  ci74HC595Write(4, 1); //E desligado
  ci74HC595Write(5, 0); //F ligado
  ci74HC595Write(6, 0); //G ligado
  ci74HC595Write(7, 1); //DP desligado
  // delay(1);

}

void display1() {
  //segmento 2 ligado
  digitalWrite(Seg1, HIGH);
  digitalWrite(Seg2, LOW);
  digitalWrite(Seg3, LOW);
  digitalWrite(Seg4, LOW);
  delay(3);
}
void display2() {
  //segmento 2 ligado
  digitalWrite(Seg1, LOW);
  digitalWrite(Seg2, HIGH);
  digitalWrite(Seg3, LOW);
  digitalWrite(Seg4, LOW);
   ci74HC595Write(7, 0); //DP ligado
  delay(3);
}
void display3() {
  //segmento 3 ligado
  digitalWrite(Seg1, LOW);
  digitalWrite(Seg2, LOW);
  digitalWrite(Seg3, HIGH);
  digitalWrite(Seg4, LOW);
  delay(3);
}
void display4() {
  //segmento 4 ligado
  digitalWrite(Seg1, LOW);
  digitalWrite(Seg2, LOW);
  digitalWrite(Seg3, LOW);
  digitalWrite(Seg4, HIGH);
  delay(3);
}

void apagarDisplay(){
  digitalWrite(Seg1, LOW);
  digitalWrite(Seg2, LOW);
  digitalWrite(Seg3, LOW);
  digitalWrite(Seg4, LOW);
  delay(1);
  }
//====================================================================================================================
//*********************************************************************************************************************
//inicio do controle dos pulsos do 74HC595

void ci74HC595Write(byte pino, bool estado) {//É como o analogWrite(Pino, Valor)
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
