/*
 * Autor: Lucas Flávio Cota
 * Data: 11/12/2019
 * By: Micro Farad
 * 
 * Esta biblioteca exige o uso da biblioteca Motor (by Micro Farad).
 */

#include <SeguirLinha5.h>

void setup()
{
  infraVBegin(A0, A1, A2, A3, A4); // Caso nao haja essa linha serah A1,A2,A3,A4,A5
  motorBegin();
}

void loop()
{
  lerLinha();
  seguirLeitura();  
}
