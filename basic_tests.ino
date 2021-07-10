#include <Servo.h>

Servo motor;
int cmd = 0;

void setup() {
  Serial.begin(9600);
  motor.attach(5);
}

void loop() {
  cmd = 0;
  motor.write(cmd);
  Serial.println(cmd);
  delay(1000);
  
  cmd = 90;
  motor.write(cmd);
  Serial.println(cmd);
  delay(1000);
  
  cmd = 180;
  motor.write(cmd);
  Serial.println(cmd);
  delay(1000);
  
  cmd = 90;
  motor.write(cmd);
  Serial.println(cmd);
  delay(1000);
}
