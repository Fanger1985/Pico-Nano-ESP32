#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "NetworkName";
const char* password = "NetworkPassword";

// Set up the web server object on port 80
WebServer server(80);

// GPIO pin where the moisture sensor is connected
const int moistureSensorPin = 34; // GPIO34 as moisture sensor input

unsigned long previousMillis = 0;        // Stores last time the sensor was updated
const long interval = 10000;             // Interval for web page refresh (10 seconds)

int moistureLevel = 0;                   // Stores the latest moisture level

int getMoistureLevel() {
  int sensorValue = analogRead(moistureSensorPin); // Read the moisture sensor value
  Serial.print("Raw Sensor Value: "); // Print raw value for debugging
  Serial.println(sensorValue);
  
int moisturePercent = map(sensorValue, 700, 100, 100, 0); // Reverse the range
  moisturePercent = constrain(moisturePercent, 0, 100); // Ensuring the percentage is between 0 and 100
  
  Serial.print("Moisture Percentage: "); // Print calculated moisture percentage
  Serial.println(moisturePercent);
  
  return moisturePercent;
}

void handleRoot() {
  String html = "<html><head><style>"
                "body { font-family: Arial, sans-serif; display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0; background: #e0e5ec; color: #333; }"
                ".card { background: #ffffff; border-radius: 25px; box-shadow: 10px 10px 15px #a3b1c6, -10px -10px 15px #ffffff; padding: 20px; }"
                "h1 { font-size: 2em; }"
                "p { font-size: 1.5em; }"
                "</style></head><body>"
                "<div class=\"card\"><h1>Plant Moisture Level</h1>"
                "<p>Moisture: " + String(moistureLevel) + "%</p></div></body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  pinMode(moistureSensorPin, INPUT);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  Serial.print("Connected to Wi-Fi. ESP32 IP Address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient(); // Handle web server
  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000) { // Update sensor reading every second
    previousMillis = currentMillis;
    moistureLevel = getMoistureLevel(); // Update global moisture level
  }
}
