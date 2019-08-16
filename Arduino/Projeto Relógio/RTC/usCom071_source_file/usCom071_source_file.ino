/* ======================================================================================================
   
   Usina Info & WR Kits
   
   RTC DS3231


   Hardware
            DS3231    -> Arduino UNO
            -----------------------------------------
            VCC pin   -> Analógico 3 (utilizado como digital 17)
            GND pin   -> Analógico 3 (utilizado como digital 16)
            SDA pin   -> Analógico 4 (SDA)  
            SCL pin   -> Analógico 5 (SCL)  
            -----------------------------------------
    
   Autor: Eng. Wagner Rambo  Data: Novembro de 2016
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/user/canalwrkits
   
====================================================================================================== */


// ======================================================================================================
// --- Bibliotecas Auxiliares ---
#include <DS3231.h>          //Inclui a biblioteca do DS3231 Shield


// ======================================================================================================
// --- Mapeamento de Hardware ---
#define    vcc    17
#define    gnd    16


// ======================================================================================================
// --- Declaração de Objetos ---
DS3231  rtc(SDA, SCL);
Time t;
int horas, minutos, ano;


// ======================================================================================================
// --- Configurações Iniciais ---
void setup()
{

  pinMode(vcc, OUTPUT);
  pinMode(gnd, OUTPUT);
  digitalWrite(vcc, HIGH);
  digitalWrite(gnd,  LOW);
 
  Serial.begin(115200);          //Inicia comunicações Serial em 115200 baud rate
 
  rtc.begin();                   //Inicializa RTC
  
  //Descomente as linhas a seguir para configurar o horário, após comente e faça o upload novamente para o Arduino
  //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
//  rtc.setTime(11,43, 0);     // Set the time to 12:00:00 (24hr format)
//  rtc.setDate(25,7,2020);

} //end setup


// ======================================================================================================
// --- Loop Infinito ---
void loop()
{
  t = rtc.getTime();
  horas = t.hour;
  minutos = t.min;
  ano   = t.year;
  Serial.print(horas);
  Serial.print("   ");
  Serial.print(minutos);
  Serial.print("   ");
  Serial.print(ano);
  Serial.print("   ");
  //Imprime o dia da semana
  //Serial.print(rtc.getDOWStr());
  Serial.print(rtc.getDateStr());
  Serial.print(" ");
  Serial.print(" -- ");
  Serial.print(" ");

  //Imprime o horário
  Serial.println(rtc.getTimeStr());
  
  //Atualiza monitor a cada segundo
  delay (1000);
  
} //end loop
