/*Tips:
    //lcd.setCursor(coluna,linha);
*/

/*
   0    R
   131  T
   307  D
   480  L
   722  Select
   1023 Free
*/

#include <LiquidCrystal.h>
#include <MsTimer2.h> // T0 mexe com delay e millis - T1 mexe com pwn do pino 10

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // (rs,en,d4,d5,d6,d7)

volatile int tempo[3] = {21, 47, 00}; // hh:mm:ss
int alarme[3] = {9, 0, 0};
bool alarmeState = 0; // off
int modo = 1; // relogio
int luz = 20;

void addTempo() {
  tempo[2]++;
  if (tempo[2] >= 60) {
    tempo[2] = 0;
    tempo[1]++;
  }
  if (tempo[1] >= 60) {
    tempo[1] = 0;
    tempo[0]++;
  }
  if (tempo[0] >= 24) tempo[0] = 0;
}

void lcdRel() {
  lcd.clear();
  lcd.setCursor(4, 0);
  if (tempo[0] > 9) lcd.print(String(tempo[0]) + ":"); //horas
  else lcd.print("0" + String(tempo[0]) + ":");

  if (tempo[1] > 9) lcd.print(String(tempo[1]) + ":"); //minutos
  else lcd.print("0" + String(tempo[1]) + ":");

  if (tempo[2] > 9) lcd.print(String(tempo[2]));      //segundos
  else lcd.print("0" + String(tempo[2]));
}

void lcdAlOnOff() {
  lcd.clear();
  lcd.setCursor(6, 0);
  if (alarmeState) lcd.print("ON"); // se on
  else lcd.print("OFF");
}

void lcdAl() {
  lcd.clear();
  lcd.setCursor(4, 0);
  if (alarme[0] > 9) lcd.print(String(alarme[0]) + ":"); //horas
  else lcd.print("0" + String(alarme[0]) + ":");

  if (alarme[1] > 9) lcd.print(String(alarme[1]) + ":"); //minutos
  else lcd.print("0" + String(alarme[1]) + ":");

  if (alarme[2] > 9) lcd.print(String(alarme[2]));      //segundos
  else lcd.print("0" + String(alarme[2]));
}

void lcdLuz() {
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Luz: " + String(luz));
}

void botRel() {
  int bot = analogRead(A0);
  if (bot < 800) {
    delay(200);
    if (bot < 50) { // Right
      tempo[1]++;
    } else if (bot < 200) { // Top
      tempo[0]++;
    } else if (bot < 400) { // Down
      tempo[0]--;
    } else if (bot < 550) { // Left
      tempo[1]--;
    } else { // Select
      modo = 2; // alarme on/off
    }
  }
}

void botAlOnOff() {
  int bot = analogRead(A0);
  if (bot < 800) {
    delay(200);
    if (bot < 550) { // Qualquer botao
      alarmeState = !alarmeState;
    } else { // Select
      modo = 3; // alarme tempo
    }
  }
}

void botAl() {
  int bot = analogRead(A0);
  if (bot < 800) {
    delay(200);
    if (bot < 50) { // Right
      alarme[1]++;
    } else if (bot < 200) { // Top
      alarme[0]++;
    } else if (bot < 400) { // Down
      alarme[0]--;
    } else if (bot < 550) { // Left
      alarme[1]--;
    } else { // Select
      modo = 4; // luz
    }
  }
}

void botLuz() {
  int bot = analogRead(A0);
  if (bot < 800) {
    delay(200);
    if (bot < 50) { // Right
      luz++;
    } else if (bot < 200) { // Top
      luz = luz + 5;
    } else if (bot < 400) { // Down
      luz = luz - 5;
    } else if (bot < 550) { // Left
      luz--;
    } else { // Select
      modo = 1; // Relogio
    }
    analogWrite(10, luz); // reinicia novo valor
  }
}

void testeBot(){
  switch(modo){
    case 1:
      botRel();break;
    case 2:
      botAlOnOff();break;
    case 3:
      botAl();break;
    case 4:
      botLuz();break;
    default:
      modo = 1;
  }
}

void exibir(){
  switch(modo){
    case 1:
      lcdRel();break;
    case 2:
      lcdAlOnOff();break;
    case 3:
      lcdAl();break;
    case 4:
      lcdLuz();break;
    default:
      modo = 1;
  }
}

void playAlarme(){ // bolar alguma forma de desligar com um botão
  // musica utilizando timer 0 ou 1 aqui
}

void testeAl(){
  if(tempo[0] == alarme[0] && tempo[1] == alarme[1] && tempo[2] == alarme[2]){
    playAlarme();
  }
}

void modoRel(void) {
  addTempo();
  exibir();
  testeAl();
}

void setup() {
  pinMode(10, OUTPUT); // intensidade backlight
  analogWrite(10, luz); // (pino, intensidade)

  MsTimer2::set(1000, modoRel); // interrupções a cada 1s
  MsTimer2::start();

  lcd.begin(16, 2);
}

void loop() {
  testeBot();
}
