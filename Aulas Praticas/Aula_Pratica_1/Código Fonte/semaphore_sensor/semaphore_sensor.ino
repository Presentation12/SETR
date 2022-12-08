/*
  Declaração de variáveis:
    redPin: variavel que contem o pinSlot para o LED_1
    greenPin: variavel que contem o pinSlot para o LED_2
    yellowPin: variavel que contem o pinSlot para o LED_3

    ldrPin: variavel que contem o pinSlot para o ldrPin (este está ligado ao pin Analog)
    lightVal: variavel que contem os valores lidos pelo ldrPin
*/
int redPin = 4;
int yellowPin = 5;
int greenPin = 6;

int ldrPin = 0;
int lightVal = 0;

void setup()
{
  //Identificacao da funcionalidade do PIN do LED
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop()
{
    // É armazenado o valor lido pelo ldrPin de luz
    lightVal = analogRead(ldrPin);

    //Printagem de valores lidos pelo lightVal
    Serial.print("Valor lido pelo ldrPin de luz: ");
    Serial.print(lightVal);

    //Acender luz da LED durante o tempo que o ldrPin detetar esse valor
    //Ter em conta que liga o LED com a respetiva cor tendo em conta a luminosidade
    if(lightVal <= 400){
        digitalWrite(redPin, HIGH);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, LOW);

        delay(lightVal);
        digitalWrite(redPin, LOW);
        delay(lightVal);
    }
    else if(lightVal > 400 && lightVal <= 900){
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, HIGH);
        digitalWrite(greenPin, LOW);

        delay(lightVal);
        digitalWrite(yellowPin, LOW);
        delay(lightVal);
    }
    else{
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, HIGH);

        delay(lightVal);
        digitalWrite(greenPin, LOW);
        delay(lightVal);
    }
}