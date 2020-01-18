/*
 * Autor: Lucas Flávio Cota
 * Data: 29/11/2019
 * By: Micro Farad
 * 
 * Revisado por:
 * Data:
 */

#include <MotorMatriz.h>

MotorMatriz::MotorMatriz(int vel, int velVirar, int tempoFrente, int tempoVirar, int IN1, int IN2, int ENA, int IN3, int IN4, int ENB){
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENB, OUTPUT);
    _IN1 = IN1;
    _IN2 = IN2;
    _ENA = ENA;
    _IN3 = IN3;
    _IN4 = IN4;
    _ENB = ENB;
    _vel = vel;
    _tempoFrente = tempoFrente;
    _velVirar = velVirar;
    _tempoVirar = tempoVirar;
    }

void frente(){
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, HIGH);
    analogWrite(_ENA, _vel);
    analogWrite(_ENB, _vel);
    digitalWrite(_IN3, HIGH);
    digitalWrite(_IN4, LOW);
    delay(_tempoFrente);
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, LOW;
    digitalWrite(_IN3, LOW);
    digitalWrite(_IN4, LOW);
}

void direita(){
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, HIGH);
    analogWrite(_ENA, _velVirar);
    analogWrite(_ENB, _velVirar);
    digitalWrite(_IN3, LOW);
    digitalWrite(_IN4, HIGH);
    delay(_tempoVirar);
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, LOW;
    digitalWrite(_IN3, LOW);
    digitalWrite(_IN4, LOW);
}

void esquerda(){
    digitalWrite(_IN1, HIGH);
    digitalWrite(_IN2, LOW);
    analogWrite(_ENA, _velVirar);
    analogWrite(_ENB, _velVirar);
    digitalWrite(_IN3, HIGH);
    digitalWrite(_IN4, LOW);
    delay(_tempoVirar);
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, LOW;
    digitalWrite(_IN3, LOW);
    digitalWrite(_IN4, LOW);
}