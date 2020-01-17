boolean state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  EICRA = B00001111; // rising edge int0 e int1 (falling por causa do pull_up
  EIMSK = B00000001; // int0 enable e int1 not enable
}

void loop() {
  
}

ISR(INT0_vect){
    EIFR = 0x00; // zera flag
    state = !state;
    digitalWrite(13, state);
}
