/*
 * Autor: Lucas Flávio Cota
 * Data: 11/12/2019
 * By: Micro Farad
 * 
 * Esta biblioteca exige o uso da biblioteca Motor (by Micro Farad).
 */

#ifndef SeguirLinha5_h
#define SeguirLinha5_h

    #ifndef Motor_h
        #include <Motor.h>
    #endif

    #ifndef Arduino_h
        #include <Arduino.h>
    #endif

int _U1 = 0; // Para implementar LCD devem ser modificados
int _U2 = 0; // LCD utiliza A4 e A5 com I2C
int _U3 = 0; // No caso do nano utiliza o A6, A7 ou A0
int _U4 = 0; // No caso de ESP utilizar um em A0
int _U5 = 0;

int _I1 = 0;
int _I2;
int _I3;
int _I4;
int _I5;

void infraVBegin(int I1, int I2, int I3, int I4, int I5){ // Caso seja use outros pinos
  _I1 = I1;
  _I2 = I2;
  _I3 = I3;
  _I4 = I4;
  _I5 = I5;
}

void lerLinha(){
  if(_I1 == 0){
    _I1 = A1;
    _I2 = A2;
    _I3 = A3;
    _I4 = A4;
    _I5 = A5;
  }
    _U1 = 0; if (analogRead(_I1) < 60) _U1 = 1; // Ajustar o limiar para um valor medido
    _U2 = 0; if (analogRead(_I2) < 60) _U2 = 1;
    _U3 = 0; if (analogRead(_I3) < 60) _U3 = 1;
    _U4 = 0; if (analogRead(_I4) < 60) _U4 = 1;
    _U5 = 0; if (analogRead(_I5) < 60) _U5 = 1;
}

void seguirLeitura(){
    if (!_U1 && !_U2 && _U3 && !_U4 && !_U5) {  //Andar reto
    frente();
  } else if (!_U1 && _U2 && _U3 && !_U4 && !_U5) {  //Alinhar esquerda
    frente(50, 70);
  } else if (!_U1 && !_U2 && _U3 && _U4 && !_U5) {  //Alinhar direita
    frente(70, 50);
  } else if (_U2 && !_U3 && !_U4 && !_U5) {  //Curva esquerda
    frente(50,100);
  } else if (!_U1 && !_U2 && !_U3 && _U4) {   //Curva direita
    frente(100,50);
  } else if (_U1 && !_U2 && !_U3 && !_U4 && !_U5) {  //Curva extrema esquerda
    frente(0,100);
  } else if (!_U1 && !_U2 && !_U3 && !_U4 && _U5) {   //Curva extrema direita
    frente(100,0);
  }else if (!_U1 && !_U2 && !_U3 && !_U4 && !_U5) {   //Parar
    parar();
  }
}

#endif // SEGUIRLINHA5_H