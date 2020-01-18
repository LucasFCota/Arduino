/*
 * Autor: Lucas Flávio Cota
 * Data:16/12/2019
 * By: Micro Farad
 */

#include <Encoder.h>

void setup(){
  Serial.begin(9600);
  encoderBegin(); // Realiza os pinModes em modo INPUT e configura interrupcoes externas
}

void loop(){
  Serial.println("Número de pulsos na esquerda" + pulsosE());
  Serial.println("Milisegundos a cada pulso da esquerda" + tempoE());
  Serial.println("Número de pulsos na direita" + pulsosD());
  Serial.println("Milisegundos a cada pulso da direita" + tempoD());
  delay(800);
}