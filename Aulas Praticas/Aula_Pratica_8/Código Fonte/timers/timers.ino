#include "TimerOne.h"

unsigned long tempoanterior = 0;
const long intervalo = 1000;
const byte ledPin = 9;

void setup(){
    Timer1.initialize(2500);
    Timer1.setPeriod(25000);
    Timer1.attachInterrupt(teste);
    Serial.begin(9600);
}

void teste(){
    Serial.println("Timer Interrupt");
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
}

void loop(){
    if(millis() - tempoanterior >= intervalo){
        tempoanterior = millis();
        Serial.println("Programa a executar");
    }
}