int const G = 49;
int const Ds = 39;
int const As = 59;
int const D2 = 74;
int const Ds2 = 78;
int const E2 = 83;
int const F2 = 88;
int const Fs2 = 93;
int const G2 = 99;
int const As2 = 118;
int const B2 = 125;
int const C2 = 132;
int const Cs3 = 140;

int const QT = 350;//1/4 de tempo

void vader();
void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);

  vader();

}

void loop() {

}

void vader() {
  for (int i = 0; i < 2; i++) {
    tone(10, G);
    delay(QT);
    noTone(10);
    delay(QT);
    tone(10, G);
    delay(QT);
    noTone(10);
    delay(QT / 4);

    tone(10, G);
    delay(QT / 4);
    noTone(10);
    delay(QT / 16);
    tone(10, G);
    delay(QT / 4);
    noTone(10);
    delay(QT / 16);
    tone(10, G);
    delay(QT / 4);
    noTone(10);
    delay(QT / 16);
    tone(10, G);
    delay(2 * QT / 3);
    noTone(10);
    delay(2 * QT / 3);

    tone(10, G);
    delay(QT / 4);
    noTone(10);
    delay(QT / 16);
    tone(10, G);
    delay(QT / 4);
    noTone(10);
    delay(QT / 16);
    tone(10, G);
    delay(QT / 4);
    noTone(10);
    delay(QT / 16);
    tone(10, Ds);
    delay(2 * QT);
    noTone(10);
    delay(2 * QT / 7);
  }

  tone(10, G);
  delay(2 * QT);
  noTone(10);
  delay(QT / 16);
  tone(10, G);
  delay(2 * QT);
  noTone(10);
  delay(QT / 16);
  tone(10, G);
  delay(2 * QT);
  noTone(10);
  delay(QT / 16);

  for (int i = 0; i < 2; i++) {
    tone(10, Ds);
    delay(3 * QT / 2);
    noTone(10);
    delay(QT / 8);
    tone(10, As);
    delay(QT / 2);
    noTone(10);
    delay(QT / 8);
    tone(10, G);
    delay(2 * QT);
  }
  delay(2 * QT);
  noTone(10);
  delay(2 * QT);

  /*backup
     tone(10, G);
    delay(600);
    noTone(10);
    delay(50);
    tone(10, G);
    delay(600);
    noTone(10);
    delay(50);
    tone(10, G);
    delay(600);
    noTone(10);
    delay(50);

    for (int i = 0; i < 2; i++) {
      tone(10, Ds);
      delay(600);
      tone(10, As);
      delay(200);
      tone(10, G);
      delay(600);
    }
    delay(600);
    noTone(10);
    delay(600);
  */

}
