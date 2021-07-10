#include <Servo.h>

Servo motor;

void setup() {
  Serial.begin(9600);
  motor.attach(5);
}

int i = 0, desiredAngle = 180, currentAngle = 0;
unsigned int startTime = 0, endTime = 0;

void loop() {
  motor.write(0);
  Serial.println("reset 0");
  delay(1000);
  
  startTime = millis();
  for (i = motor.read(); i <= desiredAngle; i++) {
    motor.write(i);
    Serial.println(i);
    delay(10);
  }
  endTime = millis();
  
  Serial.print("Run time: ");
  Serial.println(endTime - startTime);
  
  delay(1000000);
}
