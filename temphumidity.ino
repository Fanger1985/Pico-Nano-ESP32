#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

// Replace with your network credentials
const char* ssid = "SpectrumSetup-DD";
const char* password = "jeansrocket543";

// Set up the web server on port 80
WebServer server(80);

// DHT Sensor setup
#define DHTPIN 4     // What digital pin the DHT sensor is connected to
#define DHTTYPE DHT11   // DHT 11 or DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  connectToWiFi();

  // Define the route for the root page
  server.on("/", HTTP_GET, handleRoot);

  // Define the route for the status
  server.on("/status", HTTP_GET, []() {
    float humidity = dht.readHumidity(); // Read humidity
    float tempC = dht.readTemperature(); // Read temperature as Celsius
    float tempF = dht.readTemperature(true); // Read temperature as Fahrenheit

    if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
      server.send(500, "text/plain", "Failed to read from DHT sensor!");
    } else {
      server.send(200, "text/plain", "Humidity: " + String(humidity) + "%\nTemperature: " + String(tempF) + "°F");
    }
  });

  server.begin();
}

void loop() {
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

String htmlPage() {
  String html = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<title>Temp & Humidity Status</title>";
  html += "<script>";
  html += "setInterval(function() {";
  html += "fetch('/status').then(response => response.text()).then(data => {";
  html += "document.getElementById('status').innerText = data;";
  html += "});";
  html += "}, 1000);"; // Update status every 1000 ms
  html += "</script></head><body><h1>Temp & Humidity Sensor Status</h1><p>Status: <span id='status'>Loading...</span></p></body></html>";
  return html;
}

void handleRoot() {
  server.send(200, "text/html", htmlPage());
}
