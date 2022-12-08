const byte ledPin = 13;
const byte interruptPin = 2;
int i = 0;
volatile byte state = HIGH;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(ledPin, state);
}

void blink()
{
    state = !state;

    if(state == 1) Serial.println("Botao pressionado!");
    if(state == 0) Serial.println("Botao libertado!");
}