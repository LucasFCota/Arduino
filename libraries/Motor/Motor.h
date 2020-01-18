/*
 * Autor: Lucas Flávio Cota
 * Data: 10/12/2019
 * By: Micro Farad
 */

#ifndef Motor_h
#define Motor_h

    #ifndef Arduino_h
        #include <Arduino.h>
    #endif

const static int _IN1 = 4; // Pinos preh-definidos
const static int _IN2 = 5;
const static int _ENA = 6;
const static int _IN3 = 7;
const static int _IN4 = 8;
const static int _ENB = 9;

const static int _vel = 60;

void motorBegin(){
    pinMode(_IN1, OUTPUT);
    pinMode(_IN2, OUTPUT);
    pinMode(_ENA, OUTPUT);
    pinMode(_IN3, OUTPUT);
    pinMode(_IN4, OUTPUT);
    pinMode(_ENB, OUTPUT);
}

void motorDireitaHorario(){
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, HIGH);
    analogWrite(_ENA, _vel);
}

void motorDireitaAntiHorario(){
    digitalWrite(_IN1, HIGH);
    digitalWrite(_IN2, LOW);
    analogWrite(_ENA, _vel);
}

void motorDireitaParar(){
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, LOW);
}

void motorEsquerdaHorario(){
    analogWrite(_ENB, _vel);
    digitalWrite(_IN3, HIGH);
    digitalWrite(_IN4, LOW);
}

void motorEsquerdaAntiHorario(){
    analogWrite(_ENB, _vel);
    digitalWrite(_IN3, HIGH);
    digitalWrite(_IN4, LOW);
}

void motorEsquerdaParar(){
    digitalWrite(_IN3, LOW);
    digitalWrite(_IN4, LOW);
}

void parar(){
    motorDireitaParar();
    motorEsquerdaParar();
}

void frente(){
    motorDireitaHorario();
    motorEsquerdaAntiHorario();
}

void tras(){
    motorDireitaAntiHorario();
    motorEsquerdaHorario();
}

void direita(){
    motorDireitaParar();
    motorEsquerdaAntiHorario();
}

void esquerda(){
    motorDireitaHorario();
    motorEsquerdaParar();
}

void frente(int esq, int dir){
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, HIGH);
    analogWrite(_ENA, dir);
    analogWrite(_ENB, esq);
    digitalWrite(_IN3, HIGH);
    digitalWrite(_IN4, LOW);
}

#endif // MOTOR_H