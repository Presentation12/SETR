#define LED 13
#define BUTTON 7

int val = 0;

int i;
float Output;
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

    for(i=1;i<=255;i++)
    {
      digitalWrite(LED,i);
      Output=i*5/255;
      Serial.print("Output voltage: ");
      Serial.println((int)Output);
      Serial.print(".");
      Serial.println(i*5%255);
      Serial.print(" V\n");
      delay(10);
    }

    for(i=255;i >= 1;i--)
    {
      analogWrite(LED,i);
      Output=i*5/255;
      Serial.print("Output voltage: ");
      Serial.println((int)Output);
      Serial.print(".");
      Serial.println(i*5%255);
      Serial.print(" V\n");
      delay(10);
    }
  }
  else 
  {
    digitalWrite(LED, LOW);
  }
}
