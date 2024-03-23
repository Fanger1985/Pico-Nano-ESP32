#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "SpectrumSetup-DD";
const char* password = "jeansrocket543";
WebServer server(80);

void handleRoot() {
  // Calculate the uptime components
  unsigned long uptime = millis();
  unsigned int seconds = uptime / 1000;
  unsigned int minutes = seconds / 60;
  unsigned int hours = minutes / 60;

  // Format the uptime string
  char uptimeStr[100];
  sprintf(uptimeStr, "%02u:%02u:%02u", hours, minutes % 60, seconds % 60);

  String html = "<!DOCTYPE html><html><head><title>ESP32 Uptime</title><style>body {text-align: center; font-family: Arial, sans-serif; margin-top: 50px;} #uptime {font-size: 2em;}</style></head><body>";
  html += "<h1>ESP32 Uptime</h1><div id='uptime'>" + String(uptimeStr) + "</div>";
  html += "<h2>ESP32 Stats</h2><p>Heap: " + String(ESP.getFreeHeap()) + "</p>";
  html += "<p>Max Alloc Heap: " + String(ESP.getMaxAllocHeap()) + "</p>";
  html += "<p>PSRAM: " + String(ESP.getFreePsram()) + "</p>";
  html += "<p>Max Alloc PSRAM: " + String(ESP.getMaxAllocPsram()) + "</p>";
  html += "<p>Chip Revision: " + String(ESP.getChipRevision()) + "</p>";
  html += "<p>Flash Chip Size: " + String(ESP.getFlashChipSize()) + "</p>";
  html += "<script>setInterval(() => { location.reload(); }, 1000);</script></body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password); // Connect to the WiFi network

  while (WiFi.status() != WL_CONNECTED) { // Wait for connection
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  
  server.on("/", handleRoot); // Define the handling function for the root path
  server.begin(); // Start the server

  Serial.println("Web server started, open http://<your_esp_ip> in a browser");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  server.handleClient(); // Handle web server client requests
}
