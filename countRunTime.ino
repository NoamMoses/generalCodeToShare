#include <Servo.h>

Servo motor;

void setup() {
  Serial.begin(9600);
  motor.attach(5);
  motor.write(0);
  Serial.println("setup complete");
  delay(1000);
}

unsigned int startTime = 0, endTime = 0;

void loop() {
  startTime = millis();
  motor.write(180);
  endTime = millis();
  
  Serial.print("startTime: ");
  Serial.println(startTime);
  Serial.print("endTime: ");
  Serial.println(endTime);
  Serial.print("calc: ");
  Serial.println(endTime - startTime);
  delay(10000000);
}
