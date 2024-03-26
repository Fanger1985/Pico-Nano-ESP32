#include <Arduino.h>

// Define the pins for the RGB module
const int redPin = 23;    // Red pin connected to GPIO 23
const int greenPin = 22;  // Green pin connected to GPIO 22
const int bluePin = 1;    // Blue pin connected to GPIO 1

void setup() {
  // Initialize RGB LED pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Fade RED to GREEN
  for (int i = 0; i <= 255; i++) {
    analogWrite(redPin, 255 - i);
    analogWrite(greenPin, i);
    analogWrite(bluePin, 0);
    delay(5); // Delay for smooth color transition
  }

  // Fade GREEN to BLUE
  for (int i = 0; i <= 255; i++) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255 - i);
    analogWrite(bluePin, i);
    delay(5); // Delay for smooth color transition
  }

  // Fade BLUE to RED
  for (int i = 0; i <= 255; i++) {
    analogWrite(redPin, i);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255 - i);
    delay(5); // Delay for smooth color transition
  }
}
