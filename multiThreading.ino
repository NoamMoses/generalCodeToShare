#include <Servo.h>

Servo motor;

void setup() {
  Serial.begin(9600);
  motor.attach(5);
  motor.write(0);
  Serial.println("reset 0");
  delay(1000);
}

int i = 0, desiredAngle = 180, currentAngle = 0;
unsigned long startTime = 0, endTime = 0;
bool servoDone = false;
int timer = 0;

void loop() {
  startTime = millis();
  
  if (!servoDone) {
    if (startTime - timer >= 10) {
      if (i <= desiredAngle) {
        Serial.println(i);
        motor.write(i);
        i++;
      } else {
        Serial.println("done");
        servoDone = true;
        endTime = millis();
        Serial.print("Run time: ");
        Serial.println(endTime - startTime);
      }
      timer = millis();
    }
  }

  Serial.println("do some more code here");
}
