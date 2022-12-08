/*
  Declaração de variáveis:
    luz: variavel que contem o pinSlot para o LED
    sensor: variavel que contem o pinSlot para o sensor (este está ligado ao pin Analog)
    dados_sensor: variavel que contem os valores lidos pelo sensor
*/
int ledPin = 6;
int ldrPin = 0;
int lightVal = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // É armazenado o valor lido pelo sensor de luz
	lightVal = analogRead(ldrPin);

  //Printagem de valores lidos pelo dados_sensor
  Serial.print("Valor lido pelo sensor de luz: ");
  Serial.print(lightVal);
  
  //Acender luz da LED durante o tempo que o sensor detetar esse valor
  digitalWrite(ledPin, HIGH);
  delay(lightVal);
  digitalWrite(ledPin, LOW);
  delay(lightVal);
}