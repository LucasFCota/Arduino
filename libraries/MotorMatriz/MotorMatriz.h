/*
 * Autor: Lucas Flávio Cota
 * Data: 29/11/2019
 * By: Micro Farad
 * 
 * Revisado por:
 * Data:
 */

#ifndef MOTORMATRIZ_H
#define MOTORMATRIZ_H

class MotorMatriz
    {
    public:
    MotorMatriz(int vel, int velVirar, int tempoFrente, int tempoVirar, int IN1, int IN2, int ENA, int IN3, int IN4, int ENB);
    void frente();
    void direita();
    void esquerda();

    private:
    int _IN1;
    int _IN2;
    int _ENA;
    int _IN3;
    int _IN4;
    int _ENB;
    int _vel;
    int _tempoFrente;
    int _velVirar;
    int _tempoVirar;
    };

#endif // MOTORMATRIZ_H