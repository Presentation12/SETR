#include <Servo.h>
// Criar Servo da esquerda
Servo myservoLeft;
// Criar Servo da direita
Servo myservoRight;

//Variavel que armazena o angulo atual do servo
int angle = 0;

void setup(){
  myservoLeft.attach(3);
  myservoRight.attach(9);
}
void loop(){
  //Começa no angulo 90º e vai até ao angulo 180º
  for(angle = 90; angle < 180; angle += 1)
  {
    //Rotacao de servo
    myservoLeft.write(angle);
    myservoRight.write(180-angle);
    delay(20);
  }
  for(angle = 180; angle >= 90; angle -= 1)
  {
    myservoLeft.write(angle);
    myservoRight.write(180-angle);
  } 
}