/*
 * Clk I/O = Clk CPU = Clk Osc = 16e6
 */

char tcnt2 = 6; // Nuhmero que irah reiniciar o timer 2
unsigned char cont = 0; // Contador postcaler por software

bool state = 1; // Apenas aplicacao

void setup() {
  TIMSK2 = B00000001; // Ativa interrupcao por ovf e desativa comparacao
  TCCR2A = 0; // Timer 2 como contador
  bitWrite(TCCR2B, CS22, 1); // Prescaler 1:256
  bitWrite(TCCR2B, CS21, 1);
  bitWrite(TCCR2B, CS20, 0);
  
  bitClear(ASSR, AS2); // Usando I/O clock

  pinMode(13, OUTPUT);
  digitalWrite(13, state);
}

void loop() {
  // programa que funcionarah independente

}


ISR(TIMER2_OVF_vect) { // a cada 4 milissegundos
  bitClear(TIFR2, TOV2); // Limpa flag
  TCNT2 = tcnt2; // Retorna no tempo inicial
  cont++;
  if(cont == 250){ // postscaler por software para 1s
    cont = 0;
    state = !state;
    digitalWrite(13, state);
  }
}
