/*Tips:
    //lcd.setCursor(coluna,linha);
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int tempo[3] = {21, 47, 00}; // hh:mm:ss
unsigned long millisAtual = 0;
unsigned long millisAnterior = 0;

void addTempo() {
  tempo[2]++;
  if (tempo[2] == 60) {
    tempo[2] = 0;
    tempo[1]++;
  }
  if (tempo[1] == 60) {
    tempo[1] = 0;
    tempo[0]++;
  }
  if (tempo[0] == 24) tempo[0] = 0;
}

void lcdTempo() {
  lcd.setCursor(4, 0);
  if(tempo[0]>9) lcd.print(String(tempo[0]) + ":");   //horas
  else lcd.print("0"+String(tempo[0]) + ":");
  
  if(tempo[1]>9) lcd.print(String(tempo[1]) + ":");   //minutos
  else lcd.print("0"+String(tempo[1]) + ":");
  
  if(tempo[2]>9) lcd.print(String(tempo[2]));         //segundos
  else lcd.print("0"+String(tempo[2]));
}

void modoRelogio() {
  millisAtual = millis();
  if ( (millisAtual - millisAnterior) >= 1000 ) {
    millisAnterior = millisAtual;
    addTempo();
    lcdTempo();
  }
}

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  modoRelogio();
}
