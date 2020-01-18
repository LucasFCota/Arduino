/*
 * Autor: Lucas Flávio Cota
 * Data: 29/11/2019
 * By: Micro Farad
 * 
 * Revisado por:
 * Data:
 */

#include <MotorMatriz.h>

MotorMatriz robo(70, 55, 100, 700, 8, 10, 9, 11, 13, 12);

void setup()
  {
  
  }

void loop()
  {
  frente();
  esquerda();
  esquerda();
  frente();
  direita();
  direita();
  }
