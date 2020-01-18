#ifndef Encoder_h
#define Encoder_h

    #ifndef Arduino_h
        #include <Arduino.h>
    #endif

int _cont0 = 0;
int _cont1 = 0;
int _t0 = 0;
int _intervalo0 = 0;
int _t1 = 0;
int _intervalo1 = 0;

void encoderBegin() {
  pinMode(2, INPUT); // Esquerda
  pinMode(3, INPUT); // Direita
  // Interrupcao externa
  EICRA = B00001111; // rising edge int0 e int1 (falling por causa do pull_up)
  EIMSK = B00000011; // int0 e int1 ativas
}

ISR(INT0_vect){ // Quando ocorrer interrupcao
    _intervalo0 = millis() - _t0;
    _t0 = millis();
    _cont0++;
    EIFR = 0x00; // zera flag
}
ISR(INT1_vect){
    _intervalo1 = millis() - _t1;
    _t1 = millis();
    _cont1++;
    EIFR = 0x00; // zera flag
}

int tempoE(){
    return _intervalo0;
}
int pulsosE(){
    return _cont0;
}
int tempoD(){
    return _intervalo1;
}
int pulsosD(){
    return _cont1;
}
#endif // ENCODER_H