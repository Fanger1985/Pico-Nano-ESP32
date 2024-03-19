// Motor control pins
const int motor1Pin1 = 5; // IN1 on the DRV8871
const int motor1Pin2 = 18; // IN2 on the DRV8871
const int motor2Pin1 = 19; // IN1 on the DRV8871
const int motor2Pin2 = 23; // IN2 on the DRV8871

// Hall sensor pins
const int hallSensor1Pin = 32; // Hall sensor 1 signal
const int hallSensor2Pin = 33; // Hall sensor 2 signal

void setup() {
  // Initialize motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Initialize hall sensor pins as inputs
  pinMode(hallSensor1Pin, INPUT);
  pinMode(hallSensor2Pin, INPUT);

  // Start serial communication
  Serial.begin(115200);
}

void loop() {
  // Read hall sensor values
  int hallSensor1Value = digitalRead(hallSensor1Pin);
  int hallSensor2Value = digitalRead(hallSensor2Pin);

  // Run motor 1 forward
  analogWrite(motor1Pin1, 255); // Full speed
  analogWrite(motor1Pin2, 0);   // No reverse
  // Run motor 2 forward
  analogWrite(motor2Pin1, 255); // Full speed
  analogWrite(motor2Pin2, 0);   // No reverse

  Serial.println("Motors running forward. Reading Hall Sensors...");
  Serial.print("Hall Sensor 1: ");
  Serial.println(hallSensor1Value);
  Serial.print("Hall Sensor 2: ");
  Serial.println(hallSensor2Value);

  delay(3000); // Run for 3 seconds

  // Pause both motors
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);

  Serial.println("Motors paused");
  delay(1000); // Pause for 1 second

  // Let's run the motors at half speed for better hall sensor readings
  analogWrite(motor1Pin1, 127); // Half speed forward
  analogWrite(motor1Pin2, 0);   // No reverse
  analogWrite(motor2Pin1, 127); // Half speed forward
  analogWrite(motor2Pin2, 0);   // No reverse

  // Read hall sensor values again
  hallSensor1Value = digitalRead(hallSensor1Pin);
  hallSensor2Value = digitalRead(hallSensor2Pin);

  Serial.println("Motors running forward at half speed. Reading Hall Sensors...");
  Serial.print("Hall Sensor 1: ");
  Serial.println(hallSensor1Value);
  Serial.print("Hall Sensor 2: ");
  Serial.println(hallSensor2Value);

  delay(3000); // Run for 3 seconds

  // Motors running backward at half speed
  analogWrite(motor1Pin1, 0);   // No forward
  analogWrite(motor1Pin2, 127); // Half speed reverse
  analogWrite(motor2Pin1, 0);   // No forward
  analogWrite(motor2Pin2, 127); // Half speed reverse

  Serial.println("Motors running backward at half speed. Reading Hall Sensors...");
  // Read hall sensor values again
  hallSensor1Value = digitalRead(hallSensor1Pin);
  hallSensor2Value = digitalRead(hallSensor2Pin);
  Serial.print("Hall Sensor 1: ");
  Serial.println(hallSensor1Value);
  Serial.print("Hall Sensor 2: ");
  Serial.println(hallSensor2Value);

  delay(3000); // Run for 3 seconds

  // Pause both motors before the next loop iteration
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);

  Serial.println("Motors paused");
  delay(1000); // Pause for 1 second
}
