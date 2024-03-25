#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "SpectrumSetup-DD";
const char* password = "jeansrocket543";

// Set up the web server on port 80
WebServer server(80);

// Pin where the flame sensor's analog output is connected
const int flameSensorAnalogPin = 34;

// Variable to store the flame sensor status
String flameStatus = "No Flame";

void setup() {
  Serial.begin(115200);
  delay(1000); // Wait a second to open the Serial Monitor
  // Initialize the flame sensor pin as an input
  pinMode(flameSensorAnalogPin, INPUT);
  connectToWiFi();

  // Define the route for the status
  server.on("/status", HTTP_GET, []() {
    server.send(200, "text/plain", flameStatus);
  });
  
  server.begin();
}

void loop() {
  // Static variables keep their value between function calls
  static unsigned long lastNoFlameReportTime = 0; // To store the last time we reported no flame
  static bool lastFlameState = false; // To store the last state of flame detection
  static const unsigned long noFlameReportDelay = 5000; // Delay in milliseconds for no flame reports
  
  // Read the value from the flame sensor's analog output
  int sensorValue = analogRead(flameSensorAnalogPin);
  bool isFlameDetected = sensorValue < 1000; // Assuming a lower value means flame detected

  // Check if there's a flame detected
  if (isFlameDetected) {
    if (!lastFlameState) { // If the last state was no flame, then this is a change
      Serial.println("Flame Detected!");
      flameStatus = "Flame Detected!";
      lastFlameState = true; // Update the last flame state
    }
    // Handle flame detected tasks here
  } else {
    if (lastFlameState || millis() - lastNoFlameReportTime >= noFlameReportDelay) {
      // If we previously detected a flame or it's been enough time since the last no flame report
      Serial.println("No Flame");
      flameStatus = "No Flame";
      lastNoFlameReportTime = millis(); // Update the last no flame report time
      lastFlameState = false; // Update the last flame state
    }
    // Handle no flame detected tasks here
  }

  // Handle any incoming client requests
  server.handleClient();
}


void connectToWiFi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to WiFi! IP Address: ");
  Serial.println(WiFi.localIP());
}

// Function that provides the HTML code for the web page
String htmlPage() {
  String html = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<title>Flame Sensor Status</title>";
  html += "<script>";
  html += "setInterval(function() {";
  html += "fetch('/status').then(response => response.text()).then(data => {";
  html += "document.getElementById('status').innerText = data;";
  html += "});";
  html += "}, 1000);"; // Update status every 1000 ms
  html += "</script></head><body><h1>Flame Sensor Status</h1><p>Status: <span id='status'>" + flameStatus + "</span></p></body></html>";
  return html;
}


// Function to handle the root path
void handleRoot() {
  server.send(200, "text/html", htmlPage());
}
