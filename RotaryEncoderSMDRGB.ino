#include <Arduino.h>

// Define the pins for the RGB module
const int redPin = 23;
const int greenPin = 18;
const int bluePin = 19;

// Encoder pins
const int clkPin = 13;
const int dtPin = 14;
// Button pin
const int buttonPin = 15;

int counter = 0; // To keep track of the encoder position
int currentStateCLK;
int lastStateCLK;
bool ledState = true; // True means LED is on, false means off

unsigned long lastButtonPress = 0; // For debouncing the button press

void setup() {
  // Initialize RGB LED pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Initialize encoder pins as inputs
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Initialize the button as an input with an internal pull-up resistor

  // Read the initial state of clkPin
  lastStateCLK = digitalRead(clkPin);
}

void loop() {
  // Read the current state of clkPin
  currentStateCLK = digitalRead(clkPin);

  // If the current state of clkPin is different from the last state...
  if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {
    // If the dtPin state is different than the clkPin state, that means the encoder is rotating clockwise
    if (digitalRead(dtPin) != currentStateCLK) {
      counter++;
    } else {
      // Otherwise, it's rotating counterclockwise
      counter--;
    }

    counter = counter % 256; // Keep the counter within 0-255
    // Update RGB LED based on counter value
    if(ledState) {
      updateColor(counter);
    }
  }

  // Save the current state as the last state, for next time through the loop
  lastStateCLK = currentStateCLK;

  // Button debouncing
  if (millis() - lastButtonPress > 50) {
    // Check if button state has changed from HIGH to LOW (button pressed)
    if (digitalRead(buttonPin) == LOW) {
      // Wait for button to be released to toggle LED state
      while(digitalRead(buttonPin) == LOW); // Busy wait for button release
      
      // Toggle the LED state
      ledState = !ledState;
      
      // Update the LED only if turning it on, otherwise turn it off
      if (!ledState) {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0);
      } else {
        updateColor(counter); // Update the color if the LED is turned on
      }

      // Update the debouncing timer
      lastButtonPress = millis();
    }
  }
}

void updateColor(int position) {
  // Map the position to a color
  int redValue, greenValue, blueValue;

  if(position < 85) {
    redValue = 255 - position * 3;
    greenValue = position * 3;
    blueValue = 0;
  } else if(position < 170) {
    position -= 85;
    redValue = 0;
    greenValue = 255 - position * 3;
    blueValue = position * 3;
  } else {
    position -= 170;
    redValue = position * 3;
    greenValue = 0;
    blueValue = 255 - position * 3;
  }

  // Now set the RGB LED to the calculated color values
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
