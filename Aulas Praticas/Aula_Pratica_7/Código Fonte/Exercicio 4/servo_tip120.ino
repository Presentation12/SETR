#include <Servo.h>

Servo servo;
int powerControl = 8;
int servoPin = 10;

void setup() {
  pinMode(powerControl, OUTPUT);
  Serial.println("Transistor base set to pin " + String(powerControl, DEC));
  pinMode(servoPin, OUTPUT);
  Serial.println("Servo signal set to pin " + String(servoPin, DEC));
}

void loop() {
  /*--------------------------------
  ATTACH servo signal to pin 10, turn
  ON servo power and MOVE (0 to 180)
  --------------------------------*/
  // turn on the pwm signal to the servo
  servo.attach(servoPin);
  Serial.println("Servo attached to " + String(servoPin, DEC));
  // turn on servo power
  digitalWrite(powerControl, HIGH);
  Serial.println("Servo Power is ON");

  //Sweep the servo 0 to 180
  for (int servoPosition = 0; servoPosition < 181; servoPosition += 5) {
    servo.write(servoPosition);
    Serial.println("Position: " + String(servoPosition, DEC));
    delay(15);
  }
  //Wait for servo to execute last position
  delay(500);
  
  /*--------------------------------
  Turn OFF servo, DETACH pin 10 and
  WAIT for 3 second
  --------------------------------*/
  //turn off servo power
  digitalWrite(powerControl, LOW);
  Serial.println("Servo power is OFF");
  
  //turn off the pwm signal to the servo
  servo.detach();
  Serial.println("Servo detached");
  
  //wait for 1 second
  delay(3000);
  
  /*--------------------------------
  ATTACH servo signal to pin 10, turn
  ON servo power and MOVE (0 to 180)
  --------------------------------*/
  // turn on the pwm signal to the servo
  servo.attach(servoPin);
  Serial.println("Servo attached to " + String(servoPin, DEC));
  
  // turn on servo power
  digitalWrite(powerControl, HIGH);
  Serial.println("Servo Power is ON");
  
  //Sweep the servo 180 to 0
  for (int servoPosition = 180; servoPosition >= 0; servoPosition -= 5) {
    servo.write(servoPosition);
    Serial.println("Position: " + String(servoPosition, DEC));
    delay(15);
  }
  
  //Wait for servo to process last position
  delay(500);
  
  /*--------------------------------
  Turn OFF servo, DETACH pin 10 and
  WAIT for 2 second
  --------------------------------*/
  // turn off servo power
  digitalWrite(powerControl, LOW);
  Serial.println("Servo Power is OFF");
  
  //turn off the pwm signal to the servo
  servo.detach();
  Serial.println("Servo detached");
  
  //wait for 1 second
  Serial.println("Waiting for 2 sec...");
  delay(2000);
}
