#include <WiFi.h>
#include <WebServer.h>
#include <Stepper.h>

// Replace with your network credentials
const char* ssid = "SpectrumSetup-DD";
const char* password = "jeansrocket543";

const int stepsPerRevolution = 2048; // change this to fit your stepper motor

// Motor 1
int motor1Pin1 = 26;
int motor1Pin2 = 25;
int motor1Pin3 = 33;
int motor1Pin4 = 32;

// Motor 2
int motor2Pin1 = 22;
int motor2Pin2 = 21;
int motor2Pin3 = 19;
int motor2Pin4 = 18;

// Initialize the Stepper library
Stepper stepper1(stepsPerRevolution, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4);
Stepper stepper2(stepsPerRevolution, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4);

WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print the local IP address
  Serial.println(WiFi.localIP());

  // Setup motor speed
  stepper1.setSpeed(10);
  stepper2.setSpeed(10);

  // Define routes
  server.on("/", handleRoot);
  server.on("/motor1/forward", handleMotor1Forward);
  server.on("/motor1/backward", handleMotor1Backward);
  server.on("/motor2/forward", handleMotor2Forward);
  server.on("/motor2/backward", handleMotor2Backward);

  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  server.send(200, "text/html", controlPage());
}

void handleMotor1Forward() {
  stepper1.step(stepsPerRevolution);
  server.send(200, "text/plain", "Motor 1 Forward");
}

void handleMotor1Backward() {
  stepper1.step(-stepsPerRevolution);
  server.send(200, "text/plain", "Motor 1 Backward");
}

void handleMotor2Forward() {
  stepper2.step(stepsPerRevolution);
  server.send(200, "text/plain", "Motor 2 Forward");
}

void handleMotor2Backward() {
  stepper2.step(-stepsPerRevolution);
  server.send(200, "text/plain", "Motor 2 Backward");
}

String controlPage() {
  String page = "<html><head><title>Stepper Control</title></head><body><h1>Stepper Motor Control</h1>";
  page += "<p><a href=\"/motor1/forward\">Motor 1 Forward</a></p>";
  page += "<p><a href=\"/motor1/backward\">Motor 1 Backward</a></p>";
  page += "<p><a href=\"/motor2/forward\">Motor 2 Forward</a></p>";
  page += "<p><a href=\"/motor2/backward\">Motor 2 Backward</a></p>";
  page += "</body></html>";
  return page;
}