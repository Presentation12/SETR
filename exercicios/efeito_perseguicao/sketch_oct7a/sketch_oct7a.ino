int ledPin = 6;
int lrdPin = 0;
int lightVal = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lrdPin);

  Serial.print("\nLeitura entrada analógica: ");
  Serial.print(lightVal);

  digitalWrite(ledPin, HIGH);
  delay(lightVal);
  digitalWrite(ledPin, LOW);
  delay(lightVal);
}