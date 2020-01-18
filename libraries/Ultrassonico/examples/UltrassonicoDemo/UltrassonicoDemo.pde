/*
 * Autor: Lucas Flávio Cota
 * Data:16/12/2019
 * By: Micro Farad
 */

#include <Ultrassonico.h>

void setup(){
  Serial.begin(9600);
  ultrassonicoBegin(4,5);
}

void loop(){
  Serial.println("A distância em centímetros é: " + String(centimetros()));
  delay(800);
}