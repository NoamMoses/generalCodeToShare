#include <Servo.h>

Servo motor;

void setup() {
  Serial.begin(9600);
  motor.attach(5);
  motor.write(100);
  Serial.println("reset 0");
  delay(1000);
}

int desiredAngle = 180, currentAngle = 0;
unsigned int startTime = 0, endTime = 0;
bool servoDone = false;
int timer = 0;

void loop() {
  startTime = millis();

  if (!servoDone) {
    static int motorAngle = motor.read(); // Starting pos of the motor - MUST be static
    if (!moveServo(motorAngle)) {
      // Servo is still running
      Serial.println("Servo is running");
    } else {
      // Servo finished to work
      Serial.println("servo is done");
      servoDone = true;
    }
  }

  // Code here will happen in parallel
  Serial.println("do some more code here");
}

bool moveServo(int startAngle) {
  bool state = false; // Value to return - whether the servo is done or not
  static int i = startAngle; // Angle counter - MUST be static
  
  if (startTime - timer >= 10) { // Multithreading
    if (i <= desiredAngle) { // Servo didn't reach desired angle yet
      Serial.println(i);
      motor.write(i);
      i++;
    } else { // Servo reached desired angle
      Serial.println("done");
      state = true;
      endTime = millis();
      Serial.print("Run time: ");
      Serial.println(endTime - startTime);
    }
    
    timer = millis(); // Upade the timer for the multithreading
  }

  return state; // Will be true when the servo is done
}
