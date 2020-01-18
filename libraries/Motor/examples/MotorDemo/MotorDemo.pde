/*
 * Autor: Lucas Flávio Cota
 * Data: 10/12/2019
 * By: Micro Farad
 */

#include <Motor.h>

void setup()
  {
  motorBegin(); // Realiza o pinMode
  }

void loop()
  {
  frente(); // Usa uma velocidade padrao
  delay(100);
  frente(60,55); // Com parametro
  delay(100);
  tras();
  delay(100);
  esquerda();
  delay(100);
  direita();
  delay(100);
  parar();
  motorDireitaHorario();
  delay(100);
  motorEsquerdaHorario();
  delay(100);
  parar();
  delay(100);
  }