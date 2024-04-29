#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* botToken = "YOUR_BOT_TOKEN";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("https://api.telegram.org/bot" + String(botToken) + "/getUpdates");
    int httpCode = http.GET();
    if (httpCode > 0) {
      String response = http.getString();
      Serial.println(response);
    }
    http.end();
  }
  delay(10000);  // Check for messages every 10 seconds
}
