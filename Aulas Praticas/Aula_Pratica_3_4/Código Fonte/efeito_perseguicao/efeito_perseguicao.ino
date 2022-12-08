// Criação de array para os pinos dos Leds
byte ledPin[] = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
int ledDelay(65);  // delay entre mudança
int direction = 1;
int currentLED = 0;
unsigned long changeTime;



void setup() {
  //Definir todos os pinos como OUTPUT
  for (int x = 0; x < 10; x++) {
    pinMode(ledPin[x], OUTPUT);
  }
  changeTime = millis();
}

void changeLED() {

  for (int x = 0; x < 10; x++) {
    digitalWrite(ledPin[x], LOW);
  }
  //acende led atual
  digitalWrite(ledPin[currentLED], HIGH);
  //incrementa pelo valor da direção
  currentLED += direction;
  //mudar de direção caso chegue ao fim
  if (currentLED == 9) { direction = -1; }
  if (currentLED == 0) { direction = 1; }
}


void loop() {
  //se passam ledDelay ms desde a ultima mudança
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}