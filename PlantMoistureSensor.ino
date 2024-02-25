#include <WiFi.h>
#include <HTTPClient.h>

// Replace with your network credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* serverName = "http://yourserver.com/data";

// GPIO where the sensor is connected
const int moistureSensorPin = 34; // ADC1 Channel 6 on ESP32

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  // Configure ADC
  analogReadResolution(12); // Set the resolution to 12-bit (0 - 4095)
  analogSetAttenuation(ADC_11db); // For full scale voltage of 3.3V
}

void loop() {
  // Read moisture level
  int moistureLevel = analogRead(moistureSensorPin);
  // Map the value to a range from 0 to 100 (adjust the range according to your sensor's calibration)
  int moisturePercent = map(moistureLevel, 0, 4095, 0, 100);
  
  Serial.print("Moisture Level: ");
  Serial.print(moisturePercent);
  Serial.println("%");
  
  // Check Wi-Fi connection
  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    // Prepare your HTTP POST request data
    String httpRequestData = "moisturePercent=" + String(moisturePercent);
    int httpResponseCode = http.POST(httpRequestData);
    
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  
  // Deep sleep for 10 minutes before next reading
  // 600e6 is 10 minutes in microseconds
  esp_sleep_enable_timer_wakeup(600e6);
  esp_deep_sleep_start();
}
