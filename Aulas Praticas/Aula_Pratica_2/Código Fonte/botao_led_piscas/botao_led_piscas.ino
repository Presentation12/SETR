#define LED 13
#define BUTTON 7

int val = 0;

int i;
unsigned long time, timeinit=millis()/1000;

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  time = millis()/1000 - timeinit;
  val = digitalRead(BUTTON);

  if(val == HIGH)
  {
    Serial.print("Butao pressionado: ");
    Serial.print(time);
    Serial.print("s/n");

    for(i=1;i<=3;i++)
    {
      digitalWrite(LED,HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
    }
  }
  else 
  {
    digitalWrite(LED, LOW);
  }
}
