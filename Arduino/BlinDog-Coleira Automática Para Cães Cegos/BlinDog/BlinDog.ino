//Leitura de distância com o sensor HC-SR04
#include <Ultrasonic.h>
#define motor 9//pino do arduino que o vibracall se encontra
const int MAX = 255;
const int focinho = 7;
const int alcance_MAX = 40;
const int alcance_MIN = 13;//este alcance é definido de acordo com o tamanho do 
//focinho do cachorro
const int dist_intermediaria = 14;
int potencia;//valor que será o PWM do motor
Ultrasonic ultrassom(7, 8);// define o nome do sensor(ultrassom)e 
//onde esta ligado o trig(7) e o echo(8) respectivamente
long distancia;// variável global para trabalhar os valores recebidos 
//através da biblioteca


void setup() {
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
}

void loop()
{

  distancia = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a 
  //distancia em centímetros(CM) ou polegadas(INC)
  Serial.print("Distancia: ");
  Serial.print(distancia);

  if (distancia <= alcance_MAX && distancia >= dist_intermediaria) {
    potencia = map(distancia, focinho, alcance_MAX, 220, 10);
    analogWrite(motor, potencia);
    Serial.print("   Potencia: "); Serial.println(potencia);
    delay(50);

  } else if (distancia <= alcance_MIN && distancia >= focinho) {
    potencia = MAX;
    analogWrite(motor, potencia);
    Serial.print("   Potencia: "); Serial.println(potencia);
    delay(50);

  } else {
    potencia = 0;
    analogWrite(motor, 0); Serial.println(" ");

    delay(50);
  }

}
