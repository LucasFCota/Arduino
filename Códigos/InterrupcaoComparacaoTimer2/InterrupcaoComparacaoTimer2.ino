/*
 * Clk I/O = Clk CPU = Clk Osc = 16e6
 * Possivel aplicacao - gerar pulso para ultrassonico
 */

unsigned int cont = 0;
boolean onoff = 1; // 1 

void setup() {
  TIMSK2 = B00000110; // Ativa interrupcao por ovf e por comparacao
  TCCR2A = 0; // Timer 2 como contador
  bitWrite(TCCR2B, CS22, 0); // Prescaler 1:8
  bitWrite(TCCR2B, CS21, 1); // 0,5mics/cont
  bitWrite(TCCR2B, CS20, 0);
  bitClear(ASSR, AS2); // Usando I/O clock
  OCR2A = 4; // Para 2mics
  OCR2B = 24; // Para 12mics
  
}

void loop() {
  // programa que funcionarah independente

}
ISR(TIMER2_COMPA_vect) { // aos 2ms e aos 14ms
  bitClear(TIFR2, OCF2A); // Limpa flag
  digitalWrite(PINO_TRIG, LOW);
  OCR2A = 28; // mais 2mics
}
ISR(TIMER2_COMPB_vect) { // aos 12ms
  bitClear(TIFR2, OCF2B); // Limpa flag
  TCNT2 = tcnt2; // Retorna no tempo inicial
  digitalWrite(PINO_TRIG, HIGH);
}
