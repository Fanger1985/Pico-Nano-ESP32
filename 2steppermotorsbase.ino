#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this for your stepper motor

// Motor 1
int motor1Pin1 = 26;  // IN1 on the ULN2003 driver 1
int motor1Pin2 = 25;  // IN2 on the ULN2003 driver 1
int motor1Pin3 = 33;  // IN3 on the ULN2003 driver 1
int motor1Pin4 = 32;  // IN4 on the ULN2003 driver 1

// Motor 2 - Choose different pins for the second motor
int motor2Pin1 = 22;  // IN1 on the ULN2003 driver 2
int motor2Pin2 = 21;  // IN2 on the ULN2003 driver 2
int motor2Pin3 = 19;  // IN3 on the ULN2003 driver 2
int motor2Pin4 = 18;  // IN4 on the ULN2003 driver 2

// Initialize the Stepper library for both motors
Stepper stepper1(stepsPerRevolution, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4);
Stepper stepper2(stepsPerRevolution, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4);

void setup() {
  // Set the speed of the motors (RPM)
  stepper1.setSpeed(10);
  stepper2.setSpeed(10);
}

void loop() {
  // Motor 1 takes a step
  stepper1.step(stepsPerRevolution);
  delay(1000); // Wait a second
  
  // Motor 2 takes a step
  stepper2.step(stepsPerRevolution);
  delay(1000); // Wait a second
  
  // Motor 1 takes a step back
  stepper1.step(-stepsPerRevolution);
  delay(1000); // Wait a second
  
  // Motor 2 takes a step back
  stepper2.step(-stepsPerRevolution);
  delay(1000); // Wait a second
}
