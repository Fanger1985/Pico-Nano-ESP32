#include <Stepper.h>

// Define the number of steps per revolution
const int stepsPerRevolution = 2048; 

// Pins connected from the ESP32 to the ULN2003 driver
int motorPin1 = 26;  // IN1 on the ULN2003 driver
int motorPin2 = 25;  // IN2 on the ULN2003 driver
int motorPin3 = 33;  // IN3 on the ULN2003 driver
int motorPin4 = 32;  // IN4 on the ULN2003 driver

// Initialize the Stepper library
Stepper myStepper(stepsPerRevolution, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  // Set the speed of the motor
  myStepper.setSpeed(10); // 10 RPMs
}

void loop() {
  // Move the motor one revolution in one direction:
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // Move the motor one revolution in the other direction:
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
