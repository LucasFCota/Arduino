/*
 * Autor: Lucas Flávio Cota
 * Data:16/12/2019
 * By: Micro Farad
 */

#ifndef Ultrassonico_h
#define Ultrassonico_h

    #ifndef Arduino_h
        #include <Arduino.h>
    #endif

int _trig;
int _echo;

void ultrassonicoBegin(int trig, int echo){
    _trig = trig;
    _echo = echo;
    pinMode(_trig, OUTPUT);
    pinMode(_echo, INPUT);
}

int centimetros(){
    digitalWrite(_trig, LOW);
    delayMicroseconds(2);
    digitalWrite(_trig, HIGH);
    delayMicroseconds(11);
    digitalWrite(_trig, LOW);
    long _tempoPulso = pulseIn(_echo, HIGH);
    return _tempoPulso * 0.01715;
}

#endif // Ultrassonico_h